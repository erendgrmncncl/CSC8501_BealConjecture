/**
 * @file QuestionSeven.h
 *
 * @brief QuestionSeven class decleration.
 *
 *
 * @author Salih Eren Degirmenci
 * Contact: S.E.Degirmenci2@newcastle.ac.uk
 */

#pragma once
#include "Question.h"
#include <map>

class QuestionSeven : public Question {
public:
	QuestionSeven(const char* questionText, std::vector<const char*>& answersText, BealCalculator& bealCalculator);
	void findAnswer() override;
private:
	void drawHistogram(const std::map<int, int>& bntOccurances);
	void printSpaceForColumn(int printedCharCount);
};