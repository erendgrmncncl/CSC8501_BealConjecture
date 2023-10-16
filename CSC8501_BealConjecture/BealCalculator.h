#pragma once
#include <vector>

struct BealData{
	int A;
	int B;
	int C;
	int x;
	int y;
	int z;

	BealData(int A, int B, int C, int x, int y, int z);
	int getBealTotalNumber() const;
	void printBealData();
	bool operator==(const BealData& other) const;
};

class BealCalculator {
public:
	BealCalculator();
	bool haveCommonPrimeFactor(int numOne, int numTwo);
	bool isNumberSetFitsBealConjecture(int A, int B, int C, int x, int y, int z);
	bool isPrimeNumber(int num);
	bool isCompositeNumber(int num);
	bool isSquareNumber(int num);
	void checkAndAddBNTToMinimumVec(std::vector<BealData>& bnts, BealData& bnt, int maxSize);

private:
	int calculateBealTotalNumber(BealData& data);
	int getGreatestCommonDivisior(int numOne, int numTwo);
};