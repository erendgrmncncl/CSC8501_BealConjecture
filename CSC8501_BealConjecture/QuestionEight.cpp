#include "QuestionEight.h"
#include "BealCalculator.h"
#include <algorithm>


namespace {
	constexpr const long long MAX_LIMIT = 9000000; // long long max value
	constexpr const long long MIN_LIMIT = 8000000;
}

QuestionEight::QuestionEight(const char* questionText, std::vector<const char*>& answers, BealCalculator& bealCalculator) : QuestionSix(questionText, answers, bealCalculator){
}

void QuestionEight::findAnswer(){

	std::vector<long long> squareNumbs = findSquareNumbersInRange(MIN_LIMIT, MAX_LIMIT);
	auto maxElement = std::max_element(squareNumbs.begin(), squareNumbs.end());

	long long maxElementValue = *maxElement;
	
	bool isFittingToBealConjecture = false;
	
	long long xValue = 0;
	long long yValue = 0;
	long long zValue = 0;

	long long aValue = 0;
	long long bValue = 0;
	long long cValue = 0;

	if (isNumberInFormatPowerOfTwo(maxElementValue)){
		isFittingToBealConjecture = true;
		long long n = (maxElementValue - 7) / 3;
		xValue = n;
		yValue = n;
		zValue = n + 1;

		aValue = 2;
		bValue = 2;
		cValue = 2;
	}
	else if (isNumberInFormatPowerOfSixteen(maxElementValue)){
		isFittingToBealConjecture = true;
		int n = (maxElementValue - 18) / 9;
		xValue = 4 * n - 1;
		yValue = n;
		zValue = n;

		aValue = 2;
		bValue = 2;
		cValue = 16;
	}

	if (isFittingToBealConjecture){
		BealData bealData(aValue, bValue, cValue, xValue, yValue, zValue);
		_answers.push_back(bealData);
	}
}

bool QuestionEight::isNumberInFormatPowerOfTwo(long long squareNumber){
	return (squareNumber - 7) % 3 == 0;
}

bool QuestionEight::isNumberInFormatPowerOfSixteen(long long squareNumber){
	return (squareNumber - 18) % 9 == 0;
}

std::vector<long long> QuestionEight::findSquareNumbersInRange(long long start, long long end){
	std::vector<long long> squareNumbers;
	for (long long i = start; i < end; i++) {
		long long root = std::sqrt(i);
		if (root * root == i) {
			squareNumbers.push_back(i);
		}
	}

	return squareNumbers;
}
