#pragma once

#include <vector>

class Question;
class FileOperator;

class CommandLineManager {
public:
	CommandLineManager(std::vector<const char*>& rawTxtQuestions, const char* answers);
	void handleCommandLine();
private:
	void init(const char* rawTxtQuestions, const char* answers);
	void initQuestions(std::vector<const char*>& rawTxtQuestions);
	void handleMainMenu();
	void handleQuestionsMenu();
	void handleQuestionUI(int selectedQuestionIndex);

	std::vector<Question*> _questions;
};