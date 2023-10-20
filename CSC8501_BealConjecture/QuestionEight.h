#pragma once
#include "QuestionSix.h"
class QuestionEight : public QuestionSix {
public:
	QuestionEight(const char* questionText, std::vector<const char*>& answers, BealCalculator& bealCalculator);
	void findAnswer() override;
private:
	bool isNumberInFormatPowerOfTwo(long long squareNumber);
	bool isNumberInFormatPowerOfSixteen(long long squareNumber);
	std::vector<long long> findSquareNumbersInRange(long long start, long long end);
};