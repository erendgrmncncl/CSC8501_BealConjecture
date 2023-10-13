#pragma once
#include <vector>


struct BealData;

class Question {
public:
	Question(const char* questionText, const char* answersText);
private:
	char* _questionText = nullptr;
	BealData* _bealData;

	void parseAnswerTextToBealData(const char* answersText);
};