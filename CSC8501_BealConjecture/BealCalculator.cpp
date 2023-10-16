#include "BealCalculator.h"

#include <iostream>
#include <cmath>
#include <algorithm>

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
	return getBealTotalNumber() == other.getBealTotalNumber();
 }

BealCalculator::BealCalculator()
{
}

bool BealCalculator::haveCommonPrimeFactor(int numOne, int numTwo){
	int commonFactor = getGreatestCommonDivisior(numOne, numTwo);

	while (commonFactor > 1) {
		if (numOne % commonFactor == 0 && numTwo % commonFactor == 0) {
			return true;
		}
		numOne /= commonFactor;
		commonFactor = getGreatestCommonDivisior(numOne, commonFactor);
	}

	return false;
}

bool BealCalculator::isNumberSetFitsBealConjecture(int A, int B, int C, int x, int y, int z){
	if ( !haveCommonPrimeFactor(A,B) || !haveCommonPrimeFactor(A,C)  || !haveCommonPrimeFactor(B,C)){
		return false;
	}

	int axby = pow(A, x) + pow(B, y);
	int cz = pow(C, z);

	return axby == cz;
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

void BealCalculator::checkAndAddBNTToMinimumVec(std::vector<BealData>& bnts, BealData& bnt, int maxSize){
	if (bnts.size() < maxSize) {
		if (std::find(bnts.begin(), bnts.end(), bnt) == bnts.end()){
			bnts.push_back(bnt);
		}

		return;
	}
	BealData* tempBealData = nullptr;
	for (int i = 0; i < maxSize; i++){
		if (tempBealData == nullptr && bnts[i].getBealTotalNumber() > bnt.getBealTotalNumber()){
			tempBealData = &bnts[i];
			bnts[i] = bnt;
		}
		else if(tempBealData != nullptr && bnts[i].getBealTotalNumber() > tempBealData->getBealTotalNumber()){
			BealData* newTempBealData = &bnts[i];
			bnts[i] = (*tempBealData);
			tempBealData = newTempBealData;
		}
	}
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
