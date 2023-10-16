#pragma once
#include "Question.h"

class QuestionSix : public Question {
public:
	QuestionSix(const char* questionText, std::vector<const char*>& answersText, BealCalculator& bealCalculator);
	void findAnswer() override;
};