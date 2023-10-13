#include "CommandLineManager.h"
#include <iostream>

namespace {
	constexpr const int MAIN_MENU_EXIT_SELECTION = 2;
	constexpr const int RETURN_TO_MAIN_MENU_FROM_QUESTIONS_INDEX = 2;
}

void CommandLineManager::init(){

}

void CommandLineManager::handleMainMenu(){
	std::cout << "CSC8501 - Beal Conjecture" << std::endl;
	int currentSelectedMenu = 0;
	while (currentSelectedMenu != MAIN_MENU_EXIT_SELECTION){
		std::cout << "1-) Show Questions" << std::endl;
		std::cout << "2-) Exit" << std::endl;
		std::cin >> currentSelectedMenu;
	}
}

void CommandLineManager::handleQuestionsMenu(){
	int selectedQuestion = -1;
	while (selectedQuestion != 9){
	}
}
