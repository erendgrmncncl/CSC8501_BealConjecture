#pragma once
#include<vector>
struct BealData;

class FileOperator {
public:
	const char* getTextInFile(const char* fileName);
	std::vector<const char*> seperateLines(const char* questionsText);
	void createAnswersFile(int questionNumber, const std::vector<BealData*>& answers);
private:
};