#pragma once

#include <vector>
#include <map>
#include <iostream>
#include <functional>

class Question;
class FileOperator;
class BealCalculator;

class CommandLineManager {
public:
	CommandLineManager(std::vector<const char*>& rawTxtQuestions, std::vector<std::vector<const char*>>& rawAnswerTexts, BealCalculator& bealCalculator, FileOperator& fileOperator);
	void handleCommandLine();
private:
	FileOperator* _fileOperator = nullptr;
	
	void initQuestionInitMap();
	void initQuestions(std::vector<const char*>& rawTxtQuestions, std::vector<std::vector<const char*>>& rawAnswerTexts, BealCalculator& bealCalculator);
	void handleMainMenu();
	void handleQuestionsMenu();
	void handleQuestionUI(int selectedQuestionIndex);

	std::map<int, std::function<Question* (const char*, std::vector<const char*>&, BealCalculator&)>> _questionInitMap;
	std::vector<Question*> _questions;
};