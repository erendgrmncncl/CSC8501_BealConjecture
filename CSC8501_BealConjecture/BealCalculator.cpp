#include "BealCalculator.h"
#include <iostream>
#include <cmath>
#include <algorithm>
#include "BigInt.hpp"

BealData::BealData(int A, int B, int C, int x, int y, int z){
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

void BealData::printBealData(){
	std::cout << this->A + this-> B + this->C + this->x + this-> y + this->z << " : ";
	std::cout << this->A << ", " << this->B << ", " << this->C << ", " << this->x << ", " << this->y << ", " << this->z << std::endl;
}

bool BealData::operator==(const BealData& other) const{
	int bnt = getBealTotalNumber();
	int otherBnt = other.getBealTotalNumber();
	return bnt == otherBnt;
 }

BealCalculator::BealCalculator()
{
}

bool BealCalculator::haveCommonPrimeFactor(int numOne, int numTwo){
	while (numTwo != 0) {
		int temp = numTwo;
		numTwo = numOne % numTwo;
		numOne = temp;
	}
	return numOne > 1;
}

bool BealCalculator::haveCommonPrimeFactor(BigInt& numOne, BigInt& numTwo){
	
	while (numTwo != 0) {
		BigInt temp = numTwo;
		numTwo = numOne % numTwo;
		numOne = temp;
	}
	return numOne > 1;
}

bool BealCalculator::isNumberSetFitsBealConjecture(int A, int B, int C, int x, int y, int z){
	long long maxLongLongValue = std::numeric_limits<long long>::max();
	double logMaxLongLong = log(maxLongLongValue);

	if (isOverflowHappeningInPow(A,x) || isOverflowHappeningInPow(B,y) || isOverflowHappeningInPow(C,z)){
		return isNumberSetFitsBealConjectureBigInt(A, B, C, x, y, z);
	}

	unsigned long long axby = pow(A, x) + pow(B, y);
	unsigned long long cz = pow(C, z);

	return axby == cz;
}

bool BealCalculator::isNumberSetFitsBealConjectureBigInt(int A, int B, int C, int x, int y, int z){
	BigInt bigA = A;
	BigInt bigB = B;
	BigInt bigC = C;

	BigInt axby = pow(bigA, x) + pow(bigB, y);
	BigInt cz = pow(bigC, z);
	bool res = axby == cz;

	return res;
}

bool BealCalculator::isPrimeNumber(int num)
{
	bool is_prime = true;
	if (num == 0 || num == 1) {
		is_prime = false;
	}

	for (int i = 2; i <= num / 2; ++i) {
		if (num % i == 0) {
			is_prime = false;
			break;
		}
	}

	return is_prime;
}

bool BealCalculator::isCompositeNumber(int num){
	if (num <= 1) {
		return false; // 0 and 1 are not composite numbers
	}

	for (int i = 2; i <= num / 2; i++) {
		if (num % i == 0) {
			return true; // It has a factor other than 1 and itself, so it's composite
		}
	}

	return false; // It's not divisible by any number other than 1 and itself, so it's not composite
}

bool BealCalculator::isSquareNumber(int num)
{
	if (num < 0) {
		return false;  // Negative numbers cannot be square numbers
	}

	int squareRoot = static_cast<int>(std::sqrt(num));
	return squareRoot * squareRoot == num;
}

void BealCalculator::checkAndAddBNTToMinimumVec(std::vector<BealData>& bnts, BealData& bnt, int maxSize){

	if (std::find(bnts.begin(), bnts.end(), bnt) == bnts.end()) {
		if (bnts.size() < maxSize) 
			bnts.push_back(bnt);
		else
		{
			//TODO(eren.degirmenci): remove leak
			BealData* tempBealData = nullptr;
			for (int i = 0; i < maxSize; i++) {
				if (tempBealData == nullptr && bnts[i].getBealTotalNumber() > bnt.getBealTotalNumber()) {
					tempBealData = new BealData (bnts[i].A, bnts[i].B, bnts[i].C, bnts[i].x, bnts[i].y, bnts[i].z);
					bnts[i] = bnt;
				}
				else if (tempBealData != nullptr && bnts[i].getBealTotalNumber() > tempBealData->getBealTotalNumber()) {
					BealData* newTempBealData = new BealData(bnts[i].A, bnts[i].B, bnts[i].C, bnts[i].x, bnts[i].y, bnts[i].z);
					bnts[i] = (*tempBealData);
					tempBealData = newTempBealData;
				}
			}
		}
	}
	else
		return;
}

int BealCalculator::calculateBealTotalNumber(BealData& data){
	return data.A + data.B + data.C + data.x + data.y + data.z;
}

int BealCalculator::getGreatestCommonDivisior(int numOne, int numTwo){
	while (numTwo != 0) {
		int temp = numTwo;
		numTwo = numOne % numTwo;
		numOne = temp;
	}
	return numOne;
}

bool BealCalculator::isOverflowHappeningInPow(int base, int exponent){
	int iteration = 0;
	long long baseConversion = base;
	long long result = base;
	while (iteration != exponent){
		long long tempRes = result;
		result *= baseConversion;

		if (result / baseConversion != tempRes){
			return true;
		}
		iteration++;
	}
	return false;
}
