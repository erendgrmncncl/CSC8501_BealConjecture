#include <iostream>
#include "FileOperator.h"
#include "CommandLineManager.h"
#include "BealCalculator.h"
#include <string>

namespace {
	constexpr const char* QUESTIONS_TXT = "questions.txt";

	constexpr const int QUESTION_COUNT = 8;
}

int main() {
	FileOperator* fileOperator = new FileOperator();
	const char* questionsTxt = fileOperator->getTextInFile(QUESTIONS_TXT);
	
	std::vector<std::vector<const char*>> parsedAnswerTexts;
	fileOperator->parseAnswersToLines(parsedAnswerTexts, QUESTION_COUNT);
	
	std::vector<const char*> rawQuestionTexts = fileOperator->seperateLines(questionsTxt);
	
	BealCalculator* bealCalculator = new BealCalculator();
	CommandLineManager* commandLineManager = new CommandLineManager(rawQuestionTexts, parsedAnswerTexts, *bealCalculator, *fileOperator);
	commandLineManager->handleCommandLine();

	delete bealCalculator;
	delete fileOperator;
	delete questionsTxt;
	delete commandLineManager;
}