/**
 * @file QuestionOne.h
 *
 * @brief QuestionOne class decleration.
 *
 *
 * @author Salih Eren Degirmenci
 * Contact: S.E.Degirmenci2@newcastle.ac.uk
 */

#pragma once
#include "Question.h"

class QuestionOne : public Question {
public:
	QuestionOne(const char* questionText, std::vector<const char*>& answersText, BealCalculator& bealCalculator);
	void findAnswer() override;
};