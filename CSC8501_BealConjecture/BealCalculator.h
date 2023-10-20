/**
 * @file BealCalculator.h
 *
 * @brief Includes declerations of the structures based on handling beal conjecture operations.
 *
 *
 * @author Salih Eren Degirmenci
 * Contact: S.E.Degirmenci2@newcastle.ac.uk
 */

#pragma once
#include <vector>
#include <map>
#include "InfInt.h"

struct BealData{
	int A;
	int B;
	int C;
	int x;
	int y;
	int z;

	BealData(int A, int B, int C, int x, int y, int z);
	bool operator==(const BealData& other) const;
	int getBealTotalNumber() const;
	void printBealData();
};

struct PowData {
	int base;
	int exponent;
	InfInt result;
};

class BealCalculator {
public:
	BealCalculator();

	bool isNumberSetFitsBealConjecture(int A, int B, int C, int x, int y, int z);
	bool isNumberSetFitsBealConjectureBigInt(int A, int B, int C, int x, int y, int z);

	PowData* getPowData(int base, int exponent);

	InfInt bigIntPow(int base, int exponent);

	std::map<int, int> searchForBNTsWithFrequency(std::vector<BealData>& answers, int currAStart, int currAEnd, int minBase, int maxBase, int minExponent, int maxExponent, int minBNTValue, int maxBNTValue);
	std::map<int, int> searchForBNTsWithFrequencyMultiThread(std::vector<BealData>& answers, int minBase, int maxBase, int minExponent, int maxExponent, int minBNTValue, int maxBNTValue);

	void startSearchingBNTSMultiThread(std::vector<BealData>& bnts, int minBase, int maxBase, int minExponent, int maxExponent, int bntToFind = 0, bool isBNTMustBeDistinct = false, bool isSearchingMinimums = false, bool isBNTMustBeSquare = false, bool isBNTMustBeComposit = false, bool isBNTMustBePrime = false);
	
	void searchForBNTs(std::vector<BealData>& bnts, int currAStart, int currAEnd, int minBase, int maxBase, int minExponent, int maxExponent,
		bool isBNTMustBeDistinct = false, bool isBNTMustBeSquare = false, bool isBNTMustBeComposit = false, bool isBNTMustBePrime = false);
	
	void addPowData(int base, int exponent, InfInt result);
private:
	bool isOverflowHappeningInPow(int base, int exponent);
	bool isOverflowHappeningInSum(int firstNum, int secondNum);
	int calculateBealTotalNumber(BealData& data);

	PowData* getCalculatedPowData(int base, int exponent);

	std::vector<PowData*> _calculatedPowDatas;
	void sortBNTAnswers(std::vector<BealData>& answers);
	void keepMinNBealData(std::vector<BealData>& answers, int bntCount);
	void mergeAndRemoveDuplicates(const std::vector<std::vector<BealData>>& input, std::vector<BealData>& answers, bool isBntMustBeDistinct);
};