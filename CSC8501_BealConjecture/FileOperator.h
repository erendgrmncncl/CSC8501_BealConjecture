#pragma once
#include<vector>

class FileOperator {
public:
	const char* getTextInFile(const char* fileName);
	std::vector<const char*> seperateQuestions(const char* questionsText);
	const char* seperateAnswers(const char* questionsText);
private:
};