/**
 * @file QuestionThree.h
 *
 * @brief QuestionThree class decleration.
 *
 *
 * @author Salih Eren Degirmenci
 * Contact: S.E.Degirmenci2@newcastle.ac.uk
 */


#pragma once

#include "Question.h"

class QuestionThree : public Question {
public:
	QuestionThree(const char* questionText, std::vector<const char*>& answersText, BealCalculator& bealCalculator);
	void findAnswer() override;
};