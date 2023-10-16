#pragma once

#include "Question.h"

class QuestionThree : public Question {
public:
	QuestionThree(const char* questionText, std::vector<const char*>& answersText, BealCalculator& bealCalculator);
	void findAnswer() override;
};