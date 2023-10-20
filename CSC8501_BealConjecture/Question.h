#pragma once
#include <vector>

/**
 * @file Question.h
 *
 * @brief Includes decleration of abstact(parent) question class.
 *
 *
 * @author Salih Eren Degirmenci
 * Contact: S.E.Degirmenci2@newcastle.ac.uk
 */

struct BealData;
class BealCalculator;

class Question {
public:
	Question(const char* questionText, std::vector<const char*>& answersText, BealCalculator& bealCalculator);
	const char* getQuestionText();
	std::vector<BealData>& getAnswers();
	virtual void findAnswer();
protected:
	BealCalculator* _bealCalculator;
	std::vector<BealData> _answers;
private:
	const char* _questionText = nullptr;

	void parseAnswerTextToBealData(const char* answersText);
};