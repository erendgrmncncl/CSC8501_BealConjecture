#include <iostream>
#include "FileOperator.h"
#include "CommandLineManager.h"

namespace {
	constexpr const char* QUESTIONS_TXT = "questions.txt";
	constexpr const char* ANSWERS_TXT = "answers.txt";
}

int main() {
	FileOperator* fileOperator = new FileOperator();
	const char* questionsTxt = fileOperator->getTextInFile(QUESTIONS_TXT);
	const char* answersTxt = fileOperator->getTextInFile(ANSWERS_TXT);
	std::vector<const char*> rawQuestionTexts = fileOperator->seperateQuestions(questionsTxt);


	CommandLineManager* commandLineManager = new CommandLineManager(rawQuestionTexts, answersTxt);
	commandLineManager->handleCommandLine();
}