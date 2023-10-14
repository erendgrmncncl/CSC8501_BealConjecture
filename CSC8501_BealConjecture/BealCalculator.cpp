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

int BealData::getBealTotalNumber()
{
	return A + B + C + x + y + z;
}

void BealData::printBealData(){
	std::cout << "BNT: " << this->A + this-> B + this->C + this->x + this-> y + this->z << std::endl;
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
		// Reduce the common factor to its prime factors
		numOne /= commonFactor;
		commonFactor = getGreatestCommonDivisior(numOne, commonFactor);
	}

	return false;
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
