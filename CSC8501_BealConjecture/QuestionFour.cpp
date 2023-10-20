#include "QuestionFour.h"
#include "BealCalculator.h"
#include<iostream>
QuestionFour::QuestionFour(const char* questionText, std::vector<const char*>& answersText, BealCalculator& bealCalculator) : Question(questionText, answersText, bealCalculator){
}

void QuestionFour::findAnswer(){
	std::cout << "Implemented file read and write logics successfully! Please look to the other questions for demonstrations." << std::endl;
}
