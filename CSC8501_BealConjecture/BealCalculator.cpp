#include "BealCalculator.h"
#include <iostream>
#include <cmath>
#include <algorithm>
#include "InfInt.h"
#include "MathTemplates.h"
#include <thread>
#include <future>

BealData::BealData(int A, int B, int C, int x, int y, int z) {
	this->A = A;
	this->B = B;
	this->C = C;
	this->x = x;
	this->y = y;
	this->z = z;
}

int BealData::getBealTotalNumber() const
{
	return A + B + C + x + y + z;
}

void BealData::printBealData() {
	std::cout << this->A + this->B + this->C + this->x + this->y + this->z << " : ";
	std::cout << this->A << ", " << this->B << ", " << this->C << ", " << this->x << ", " << this->y << ", " << this->z << std::endl;
}

bool BealData::operator==(const BealData& other) const {
	int bnt = getBealTotalNumber();
	int otherBnt = other.getBealTotalNumber();
	return bnt == otherBnt;
}

BealCalculator::BealCalculator(){
}

bool BealCalculator::isNumberSetFitsBealConjecture(int A, int B, int C, int x, int y, int z) {
	
	if (isOverflowHappeningInPow(A, x) || isOverflowHappeningInPow(B, y) || isOverflowHappeningInPow(C, z)) {
		return isNumberSetFitsBealConjectureBigInt(A, B, C, x, y, z);
	}
	long long ax = getPow(A, x);
	long long by = getPow(B, y);
	if (!isOverflowHappeningInSum(ax, by)) {
		long long axby = ax + by;
		long long cz = getPow(C, z);

		return axby == cz;
	}

	return isNumberSetFitsBealConjectureBigInt(A, B, C, x, y, z);
}

bool BealCalculator::isNumberSetFitsBealConjectureBigInt(int A, int B, int C, int x, int y, int z) {
	InfInt ax = bigIntPow(A, x);
	InfInt by = bigIntPow(B, y);
	InfInt cz = bigIntPow(C, z);

	InfInt axby = ax + by;
	bool res = axby == cz;

	return res;
}


void BealCalculator::startSearchingBNTSMultiThread(std::vector<BealData>& bnts, int minBase, int maxBase, int minExponent, int maxExponent, int bntToFind, bool isBNTMustBeDistinct, bool isSearchingMinimums, bool isBNTMustBeSquare, bool isBNTMustBeComposit, bool isBNTMustBePrime) {
	std::vector<std::thread> threads;
	std::vector<std::vector<BealData>> results;

	int threadCount = std::thread::hardware_concurrency();;

	if (threadCount >= maxBase)
		threadCount = 1;
	int chunkSize = ceil((maxBase - minBase + 1) / threadCount);
	int remaining = (maxBase - minBase + 1) % threadCount;

	for (int i = 0; i < threadCount; i++){
		std::vector<BealData> res;
		results.push_back(res);
	}

	for (int i = 0; i < threadCount; ++i) {
		int startBase = minBase + i * chunkSize;
		int endBase = minBase + (i + 1) * chunkSize + (i == threadCount - 1 ? remaining : 0);
		threads.emplace_back(&BealCalculator::searchForBNTs, this, std::ref(results[i]), startBase, endBase, minBase, maxBase, minExponent, maxExponent, isBNTMustBeDistinct, isBNTMustBeSquare, isBNTMustBeComposit, isBNTMustBePrime);
	}

	for (auto& thread : threads) {
		thread.join();
	}

	mergeAndRemoveDuplicates(results, bnts, isBNTMustBeDistinct);
	sortBNTAnswers(bnts);
	if (isSearchingMinimums) {
		keepMinNBealData(bnts, bntToFind);
	}
}

void BealCalculator::searchForBNTs(std::vector<BealData>& bnts, int currAStart, int currAEnd, int minBase, int maxBase, int minExponent, int maxExponent,
	bool isBNTMustBeDistinct, bool isBNTMustBeSquare, bool isBNTMustBeComposit, bool isBNTMustBePrime) {
	
	for (int A = currAStart; A < currAEnd; A++) {
		int bRange = isBNTMustBeDistinct ? A : maxBase;
		for (int B = minBase; B <= bRange; B++) {
			if (haveCommonPrimeFactor(A, B)) {
				for (int C = minBase; C <= maxBase; C++) {
					if (haveCommonPrimeFactor(getGreatestCommonDivisior(A, B), C))
					{
						for (int x = minExponent; x <= maxExponent; x++) {
							for (int y = minExponent; y <= maxExponent; y++) {
								for (int z = minExponent; z <= maxExponent; z++) {
									int tempBNT = A + B + C + x + y + z;
									bool isPrimeCheckOk = !isBNTMustBePrime || (isBNTMustBePrime && isPrime(tempBNT));
									bool isSquareCheckOk = !isBNTMustBeSquare || (isBNTMustBeSquare && isSquare(tempBNT));
									bool isCompositeCheckOk = !isBNTMustBeComposit || (isBNTMustBeComposit && isComposite(tempBNT));
									if (isPrimeCheckOk && isSquareCheckOk && isCompositeCheckOk && isNumberSetFitsBealConjecture(A, B, C, x, y, z)) {
										BealData bealData(A, B, C, x, y, z);
										if (A > 10)
										{
											int f = 1;
										}
										if (isBNTMustBeDistinct) {
											if (std::find(bnts.begin(), bnts.end(), bealData) == bnts.end()) {
												bnts.push_back(bealData);
											}
										}
										else
										{
											bnts.push_back(bealData);
										}

									}
								}
							}
						}
					}
				}
			}

		}
	}

}

std::map<int, int> BealCalculator::searchForBNTsWithFrequency(std::vector<BealData>& answers, int currAStart, int currAEnd, int minBase, int maxBase, int minExponent, int maxExponent, int minBNTValue, int maxBNTValue) {
	std::map<int, int> bntFrequencyMap;
	for (int A = currAStart; A < currAEnd; A++) {
		for (int B = minBase; B <= maxBase; B++) {
			if (haveCommonPrimeFactor(A, B)) {
				for (int C = minBase; C <= maxBase; C++) {
					if (haveCommonPrimeFactor(getGreatestCommonDivisior(A, B), C)) {
						for (int x = minExponent; x <= maxExponent; x++) {
							for (int y = minExponent; y <= maxExponent; y++) {
								for (int z = minExponent; z <= maxExponent; z++) {
									int tempBNT = A + B + C + x + y + z;
									if (tempBNT >= minBNTValue && tempBNT <= maxBNTValue && isNumberSetFitsBealConjecture(A, B, C, x, y, z)) {
										BealData bealData(A, B, C, x, y, z);
										if (bntFrequencyMap.count(tempBNT) > 0) {
											bntFrequencyMap[tempBNT] += 1;
										}
										else {
											bntFrequencyMap.insert(std::make_pair(tempBNT, 1));
											answers.push_back(bealData);
										}
									}

								}
							}
						}
					}
				}
			}
		}
	}

	

	return bntFrequencyMap;
}

void BealCalculator::addPowData(int base, int exponent, InfInt result) {
	PowData* powData = new PowData();
	powData->base = base;
	powData->exponent = exponent;
	powData->result = result;
	if (powData != nullptr) {
		_calculatedPowDatas.push_back(powData);
	}
}

std::map<int, int> BealCalculator::searchForBNTsWithFrequencyMultiThread(std::vector<BealData>& answers, int minBase, int maxBase, int minExponent, int maxExponent, int minBNTValue, int maxBNTValue) {

	std::vector<std::future<std::map<int, int>>> futures;
	std::map<int, int> bntFrequencyMap;

	int threadCount = std::thread::hardware_concurrency();

	int chunkSize = (maxBase - minBase + 1) / threadCount;
	int remaining = (maxBase - minBase + 1) % threadCount;

	for (int i = 0; i < threadCount; ++i) {
		int startBase = (minBase + i * chunkSize);
		int endBase = minBase + (i + 1) * chunkSize + (i == threadCount - 1 ? remaining : 0);
		futures.push_back(std::async(&BealCalculator::searchForBNTsWithFrequency, this, std::ref(answers), startBase, endBase, minBase, maxBase, minExponent, maxExponent, minBNTValue, maxBNTValue));
	}

	for (auto& future : futures) {
		std::map<int, int> result = future.get();
		for (const auto& entry : result) {
			bntFrequencyMap[entry.first] += entry.second;
		}
	}

	sortBNTAnswers(answers);

	return bntFrequencyMap;
}

int BealCalculator::calculateBealTotalNumber(BealData& data) {
	return data.A + data.B + data.C + data.x + data.y + data.z;
}

PowData* BealCalculator::getCalculatedPowData(int base, int exponent){
	for (auto powData : _calculatedPowDatas) {
		if (powData->base == base && powData->exponent == exponent) {
			return powData;
		}
	}
	return nullptr;
}

void BealCalculator::sortBNTAnswers(std::vector<BealData>& answers) {
	std::sort(answers.begin(), answers.end(), [](const BealData& a, const BealData& b) {
		return a.getBealTotalNumber() < b.getBealTotalNumber();
	});
}

void BealCalculator::keepMinNBealData(std::vector<BealData>& answers, int bntCount) {
	if (bntCount >= answers.size()) {
		return;
	}
	answers.erase(answers.begin() + bntCount, answers.end());
}

void BealCalculator::mergeAndRemoveDuplicates(const std::vector<std::vector<BealData>>& input, std::vector<BealData>& answers, bool isBntMustBeDistinct){
	for (const std::vector<BealData>& innerVector : input) {
		for (const BealData& data : innerVector) {
			bool isOkayToAdd = !isBntMustBeDistinct || (isBntMustBeDistinct && std::find(answers.begin(), answers.end(), data) == answers.end());
			if (isOkayToAdd) {
				answers.push_back(data);
			}
		}
	}
}

PowData* BealCalculator::getPowData(int base, int exponent) {
	for (PowData* data : _calculatedPowDatas) {
		if (data->base == base && data->exponent == exponent) {
			return data;
		}
	}
	return nullptr;
}

InfInt BealCalculator::bigIntPow(int base, int exponent) {

	InfInt res = 1;
	for (int i = 0; i < exponent; i++) {
		(res) *= base;
	}
	return res;
	//TODO: Needs fix for multi-thread solution.
	/*PowData* data = getPowData(base, exponent);
	if (data == nullptr) {
		InfInt res = 1;
		for (int i = 0; i <= exponent; i++) {
			(res) *= base;
		}
		addPowData(base, exponent, res);
		return res;
	}
	return data->result;
	*/
}

bool BealCalculator::isOverflowHappeningInPow(int base, int exponent) {
	int iteration = 0;
	long long baseConversion = base;
	long long result = base;
	while (iteration != (exponent -1)) {
		long long tempRes = result;
		result *= baseConversion;

		if (result / baseConversion != tempRes) {
			return true;
		}
		iteration++;
	}
	return false;
}

bool BealCalculator::isOverflowHappeningInSum(int firstNum, int secondNum) {
	if (firstNum == 0 || secondNum == 0) {
		return false;
	}
	int sum = firstNum + secondNum;
	return sum - firstNum != secondNum;
}
