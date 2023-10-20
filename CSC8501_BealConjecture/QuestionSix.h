/**
 * @file QuestionSix.h
 *
 * @brief QuestionSix class decleration.
 *
 *
 * @author Salih Eren Degirmenci
 * Contact: S.E.Degirmenci2@newcastle.ac.uk
 */

#pragma once
#include "Question.h"

class QuestionSix : public Question {
public:
	QuestionSix(const char* questionText, std::vector<const char*>& answersText, BealCalculator& bealCalculator);
	void findAnswer() override;
private:
	bool isNumberInFormatPowerOfTwo(int squareNumber);
	bool isNumberInFormatPowerOfSixteen(int squareNumber);
	
	void calculateBNTsInThreads(std::vector<int>& squareNumbers, std::vector<BealData>& bnts);
	void checkIsSquareNumberBNT(std::vector<int> squareNumbers, std::vector<BealData>& bnts);

	std::vector<int> findSquareNumbersInRange(int start, int end);
};