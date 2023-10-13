#pragma once

struct BealData {
	int A;
	int B;
	int C;
	int x;
	int y;
	int z;

	BealData(int A, int B, int C, int x, int y, int z);
};

class BealCalculator {
public:
	
private:
	int calculateBealTotalNumber(BealData& data);
};