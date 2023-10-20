#include "QuestionThree.h"
#include "BealCalculator.h"
#include <iostream>

namespace {
	constexpr const int BNT_TO_FIND = 5;

	constexpr const int MIN_BASE_VALUE = 3;
	constexpr const int MAX_BASE_VALUE = 20;
	constexpr const int MIN_EXPONENT_VALUE = 3;
	constexpr const int MAX_EXPONENT_VALUE = 15;
}

QuestionThree::QuestionThree(const char* questionText, std::vector<const char*>& answersText, BealCalculator& bealCalculator) : Question(questionText, answersText, bealCalculator) {

}

void QuestionThree::findAnswer() {
	_bealCalculator->startSearchingBNTSMultiThread(_answers, MIN_BASE_VALUE, MAX_BASE_VALUE, MIN_EXPONENT_VALUE, MAX_EXPONENT_VALUE, BNT_TO_FIND, 
		false, false, false, false, false);
}