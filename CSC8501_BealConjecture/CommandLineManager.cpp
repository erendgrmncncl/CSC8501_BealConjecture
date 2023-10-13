#include "CommandLineManager.h"
#include <iostream>
#include "Question.h"

namespace {
	constexpr const int MAIN_MENU_EXIT_SELECTION = 2;
	constexpr const int RETURN_TO_MAIN_MENU_FROM_QUESTIONS_INDEX = 2;
}

CommandLineManager::CommandLineManager(std::vector<const char*> & rawTxtQuestions, const char* answers){
	initQuestions(rawTxtQuestions);
}

void CommandLineManager::handleCommandLine()
{
	handleMainMenu();
}

void CommandLineManager::initQuestions(std::vector<const char*>& rawTxtQuestions){
	for (auto* questionTxt : rawTxtQuestions) {
		Question* question = new Question(questionTxt, nullptr);
		_questions.push_back(question);
	}
	int a = 0;
}

void CommandLineManager::handleMainMenu(){
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
	int selectedQuestion = -1;
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
	char key = NULL;
	
	auto* selectedQuestion = _questions[selectedQuestionIndex];

	while (key == NULL){
		std::cout << "---------------------- Question " << selectedQuestionIndex + 1 << "----------------------" << std::endl;
		std::cout << selectedQuestion->getQuestionText() << std::endl;

		std::cout << "Press Any Key To Turn Back To Questions Menu" << std::endl;
		std::cin >> key;
	}
	handleQuestionsMenu();
}
