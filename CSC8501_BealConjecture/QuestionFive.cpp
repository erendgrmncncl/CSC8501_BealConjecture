#include "QuestionFive.h"
#include "BealCalculator.h"

namespace {
    constexpr const int BNT_TO_FIND = 10;

	constexpr const int MIN_BASE_VALUE = 2;
	constexpr const int MAX_BASE_VALUE = 20;
	constexpr const int MIN_EXPONENT_VALUE = 3;
	constexpr const int MAX_EXPONENT_VALUE = 15;
}

QuestionFive::QuestionFive(const char* questionText, std::vector<const char*>& answersText, BealCalculator& bealCalculator) : Question(questionText, answersText, bealCalculator){
}

void QuestionFive::findAnswer(){
	_bealCalculator->startSearchingBNTSMultiThread(_answers, MIN_BASE_VALUE, MAX_BASE_VALUE, MIN_EXPONENT_VALUE, MAX_EXPONENT_VALUE, BNT_TO_FIND,
		true, true, false, true, false);
}
