#include "CommandLineManager.h"
#include <iostream>
#include "Question.h"
#include "BealCalculator.h"
#include "QuestionOne.h"
#include "FileOperator.h"

namespace {
	constexpr const int MAIN_MENU_EXIT_SELECTION = 2;
	constexpr const int RETURN_TO_MAIN_MENU_FROM_QUESTIONS_INDEX = 2;
}

CommandLineManager::CommandLineManager(std::vector<const char*> & rawTxtQuestions, std::vector<std::vector<const char*>>& rawAnswerTexts, BealCalculator& bealCalculator, FileOperator& fileOperator){
	_fileOperator = &fileOperator;
	initQuestionInitMap();
	initQuestions(rawTxtQuestions, rawAnswerTexts, bealCalculator);
}

void CommandLineManager::handleCommandLine()
{
	handleMainMenu();
}


void CommandLineManager::initQuestionInitMap(){
	_questionInitMap = {
		{1, [](const char* questionText, std::vector<const char*>& choices, BealCalculator& calculator) -> Question* {return new QuestionOne(questionText, choices, calculator);}},
		{2, [](const char* questionText, std::vector<const char*>& choices, BealCalculator& calculator) -> Question* {return new QuestionOne(questionText, choices, calculator);}},
		{3, [](const char* questionText, std::vector<const char*>& choices, BealCalculator& calculator) -> Question* {return new QuestionOne(questionText, choices, calculator);}},
		{4, [](const char* questionText, std::vector<const char*>& choices, BealCalculator& calculator) -> Question* {return new QuestionOne(questionText, choices, calculator);}},
		{5, [](const char* questionText, std::vector<const char*>& choices, BealCalculator& calculator) -> Question* {return new QuestionOne(questionText, choices, calculator);}},
		{6, [](const char* questionText, std::vector<const char*>& choices, BealCalculator& calculator) -> Question* {return new QuestionOne(questionText, choices, calculator);}},
		{7, [](const char* questionText, std::vector<const char*>& choices, BealCalculator& calculator) -> Question* {return new QuestionOne(questionText, choices, calculator);}},
		{8, [](const char* questionText, std::vector<const char*>& choices, BealCalculator& calculator) -> Question* {return new QuestionOne(questionText, choices, calculator);}}
	};
}

void CommandLineManager::initQuestions(std::vector<const char*>& rawTxtQuestions, std::vector<std::vector<const char*>>& rawAnswerTexts, BealCalculator& bealCalculator){
	for (int i = 0; i < rawTxtQuestions.size(); i++) {
		Question* question = _questionInitMap[i + 1](rawTxtQuestions[i], rawAnswerTexts[i], bealCalculator);
		_questions.push_back(question);
	}
	int a = 0;
}

void CommandLineManager::handleMainMenu(){
	system("cls");
	std::cout << "CSC8501 - Beal Conjecture" << std::endl;
	int currentSelectedMenu = 0;
	while (currentSelectedMenu != MAIN_MENU_EXIT_SELECTION){
		std::cout << "1-) Show Questions" << std::endl;
		std::cout << "2-) Exit" << std::endl;
		std::cin >> currentSelectedMenu;
		if (currentSelectedMenu == 1)
			handleQuestionsMenu();
	}

}

void CommandLineManager::handleQuestionsMenu(){
	system("cls");
	int selectedQuestion = -1;
	std::cout << "---------------------- Questions ----------------------" << std::endl;
	for (int i = 0; i < _questions.size(); i++) {
		std::cout << "Question " << i + 1 << std::endl;
	}
	while (selectedQuestion < 1 || selectedQuestion > 9){
			std::cout << "Please select a valid question number.(1-8)\nEnter 9 to go back to main menu." << std::endl;
			std::cin >> selectedQuestion;
	}

	handleQuestionUI(selectedQuestion - 1);
}

void CommandLineManager::handleQuestionUI(int selectedQuestionIndex){
	system("cls");
	char key = NULL;
	
	auto* selectedQuestion = _questions[selectedQuestionIndex];

	while (key == NULL){
		std::cout << "---------------------- Question " << selectedQuestionIndex + 1 << "----------------------" << std::endl;
		std::cout << selectedQuestion->getQuestionText() << "\n\n\n\n";
		
		std::cout << "Answers: " << std::endl;

		std::vector<BealData*>& answers = selectedQuestion->getAnswers();
		if (answers.size() == 0) {
			selectedQuestion->findAnswer();
			_fileOperator->createAnswersFile(selectedQuestionIndex + 1, answers);
		}

		for (auto answer : answers) {
			answer->printBealData();
		}

		std::cout << "Enter any key to turn back to questions menu" << std::endl;
		std::cin >> key;
	}
	handleQuestionsMenu();
}
