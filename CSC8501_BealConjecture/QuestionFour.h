/**
 * @file QuestionFour.h
 *
 * @brief QuestionFour class decleration.
 *
 *
 * @author Salih Eren Degirmenci
 * Contact: S.E.Degirmenci2@newcastle.ac.uk
 */

#pragma once

#include "Question.h"
#include <map>

class QuestionFour : public Question {
public:
	QuestionFour(const char* questionText, std::vector<const char*>& answersText, BealCalculator& bealCalculator);
	void findAnswer() override;
};