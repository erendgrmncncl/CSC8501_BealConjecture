/**
 * @file QuestionTwo.h
 *
 * @brief QuestionTwo class decleration.
 *
 *
 * @author Salih Eren Degirmenci
 * Contact: S.E.Degirmenci2@newcastle.ac.uk
 */

#pragma once
#include "Question.h"

class QuestionTwo : public Question {
public:
	QuestionTwo(const char* questionText, std::vector<const char*>& answersText, BealCalculator& bealCalculator);
	void findAnswer() override;
};