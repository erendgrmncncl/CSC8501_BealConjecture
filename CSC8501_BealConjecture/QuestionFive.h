#pragma once

#include "Question.h"
class QuestionFive : public Question{
public:
	QuestionFive(const char* questionText, std::vector<const char*>& answersText, BealCalculator& bealCalculator);
	void findAnswer() override;
};