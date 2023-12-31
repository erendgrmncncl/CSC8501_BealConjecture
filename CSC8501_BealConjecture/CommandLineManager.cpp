#include "CommandLineManager.h"
#include <iostream>
#include "Question.h"
#include "BealCalculator.h"
#include "QuestionOne.h"
#include "QuestionTwo.h"
#include "QuestionThree.h"
#include "QuestionFour.h"
#include "QuestionFive.h"
#include "QuestionSix.h"
#include "QuestionSeven.h"
#include "QuestionEight.h"
#include "FileOperator.h"
#include <algorithm>
#include <functional>


namespace {
	constexpr const int MAIN_MENU_EXIT_SELECTION = 2;
	constexpr const int RETURN_TO_MAIN_MENU_FROM_QUESTIONS_INDEX = 2;
}

CommandLineManager::CommandLineManager(std::vector<const char*> & rawTxtQuestions, std::vector<std::vector<const char*>>& rawAnswerTexts, BealCalculator& bealCalculator, FileOperator& fileOperator){
	_fileOperator = &fileOperator;
	initQuestionInitMap();
	initQuestions(rawTxtQuestions, rawAnswerTexts, bealCalculator);
}

CommandLineManager::~CommandLineManager(){
	deleteQuestions();
}

void CommandLineManager::handleCommandLine()
{
	handleMainMenu();
}


void CommandLineManager::initQuestionInitMap(){
	_questionInitMap = {
		{1, [](const char* questionText, std::vector<const char*>& choices, BealCalculator& calculator) -> Question* {return new QuestionOne(questionText, choices, calculator);}},
		{2, [](const char* questionText, std::vector<const char*>& choices, BealCalculator& calculator) -> Question* {return new QuestionTwo(questionText, choices, calculator);}},
		{3, [](const char* questionText, std::vector<const char*>& choices, BealCalculator& calculator) -> Question* {return new QuestionThree(questionText, choices, calculator);}},
		{4, [](const char* questionText, std::vector<const char*>& choices, BealCalculator& calculator) -> Question* {return new QuestionFour(questionText, choices, calculator);}},
		{5, [](const char* questionText, std::vector<const char*>& choices, BealCalculator& calculator) -> Question* {return new QuestionFive(questionText, choices, calculator);}},
		{6, [](const char* questionText, std::vector<const char*>& choices, BealCalculator& calculator) -> Question* {return new QuestionSix(questionText, choices, calculator);}},
		{7, [](const char* questionText, std::vector<const char*>& choices, BealCalculator& calculator) -> Question* {return new QuestionSeven(questionText, choices, calculator);}},
		{8, [](const char* questionText, std::vector<const char*>& choices, BealCalculator& calculator) -> Question* {return new QuestionEight(questionText, choices, calculator);}}
	};
}

void CommandLineManager::deleteQuestions(){
	for (Question* question : _questions) {
		delete question;
	}
	_questions.clear();
}

void CommandLineManager::initQuestions(std::vector<const char*>& rawTxtQuestions, std::vector<std::vector<const char*>>& rawAnswerTexts, BealCalculator& bealCalculator){
	for (int i = 0; i < rawTxtQuestions.size(); i++) {
		Question* question = _questionInitMap[i + 1](rawTxtQuestions[i], rawAnswerTexts[i], bealCalculator);
		_questions.push_back(question);
	}
	int a = 0;
}

void CommandLineManager::handleMainMenu(){
	int currentSelectedMenu = 0;
	while (currentSelectedMenu != MAIN_MENU_EXIT_SELECTION){
		std::cout << "CSC8501 - Beal Conjecture" << std::endl;
		std::cout << "1-) Show Questions" << std::endl;
		std::cout << "2-) Exit" << std::endl;
		std::cin >> currentSelectedMenu;
		if (currentSelectedMenu == 1)
			handleQuestionsMenu();
			system("cls");
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
	if (selectedQuestion != 9)
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

		std::vector<BealData>& answers = selectedQuestion->getAnswers();
		if (answers.size() == 0) {
			selectedQuestion->findAnswer();
			_fileOperator->createAnswersFile(selectedQuestionIndex + 1, answers);
		}
		else
			std::cout << "Answer read from file..." << std::endl;
		std::vector<int> answersNumVec;
		for (int i = 0; i < answers.size(); i++)
		{
			answersNumVec.push_back(answers[i].getBealTotalNumber());
		}
		std::sort(answersNumVec.begin(), answersNumVec.end(), std::greater<int>());
		for (auto answer : answers) {		
			answer.printBealData();
		}
		std::cout << "Answer count: " << answers.size() << std::endl;

		std::cout << "Enter any key to turn back to questions menu" << std::endl;
		std::cin >> key;
	}
	handleQuestionsMenu();
}
