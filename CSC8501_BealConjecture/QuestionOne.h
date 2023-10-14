#pragma once
#include "Question.h"

class QuestionOne : public Question {
public:
	QuestionOne(const char* questionText, std::vector<const char*>& answersText, BealCalculator& bealCalculator);
	void findAnswer() override;
};