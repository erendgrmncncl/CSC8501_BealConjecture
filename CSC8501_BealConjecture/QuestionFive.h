/**
 * @file QuestionFive.h
 *
 * @brief QuestionFive class decleration.
 *
 *
 * @author Salih Eren Degirmenci
 * Contact: S.E.Degirmenci2@newcastle.ac.uk
 */

#pragma once

#include "Question.h"
class QuestionFive : public Question{
public:
	QuestionFive(const char* questionText, std::vector<const char*>& answersText, BealCalculator& bealCalculator);
	void findAnswer() override;
};