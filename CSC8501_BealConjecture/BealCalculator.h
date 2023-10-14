#pragma once

struct BealData{
	int A;
	int B;
	int C;
	int x;
	int y;
	int z;

	BealData(int A, int B, int C, int x, int y, int z);
	int getBealTotalNumber();
	void printBealData();
};

class BealCalculator {
public:
	BealCalculator();
	bool haveCommonPrimeFactor(int numOne, int numTwo);
private:
	int calculateBealTotalNumber(BealData& data);
	int getGreatestCommonDivisior(int numOne, int numTwo);
};