#include <iostream>
#include "FileOperator.h"
#include "CommandLineManager.h"
#include "BealCalculator.h"
#include <string>

namespace {
	constexpr const char* QUESTIONS_TXT = "questions.txt";
	constexpr const char* ANSWERS_FILE_NAME_PREFIX = "answers";
	constexpr const char* ANSWER_FILE_EXTENSION = ".txt";

	constexpr const int QUESTION_COUNT = 8;
}

int main() {
	FileOperator* fileOperator = new FileOperator();
	const char* questionsTxt = fileOperator->getTextInFile(QUESTIONS_TXT);
	
	std::vector<std::vector<const char*>> parsedAnswerTexts;
	for (int i = 0; i < QUESTION_COUNT; i++){
		char fileName[50];
		strcpy_s(fileName, sizeof(fileName), (char*)ANSWERS_FILE_NAME_PREFIX);
		std::string questionNumber = std::to_string(i + 1);
		const char* numbertxt = questionNumber.c_str();
		strcat_s(fileName, sizeof(fileName), numbertxt);
		strcat_s(fileName, sizeof(fileName), ANSWER_FILE_EXTENSION);
		const char* answerTxt = fileOperator->getTextInFile(fileName);
		parsedAnswerTexts.push_back(fileOperator->seperateLines(answerTxt));
	}
	
	std::vector<const char*> rawQuestionTexts = fileOperator->seperateLines(questionsTxt);
	
	BealCalculator* bealCalculator = new BealCalculator();
	CommandLineManager* commandLineManager = new CommandLineManager(rawQuestionTexts, parsedAnswerTexts, *bealCalculator, *fileOperator);
	commandLineManager->handleCommandLine();

	delete bealCalculator;
	delete questionsTxt;
}