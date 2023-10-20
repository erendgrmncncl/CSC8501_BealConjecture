/**
 * @file CommandLineManager.h
 *
 * @brief Provides handling user interface for program.
 *
 *
 * @author Salih Eren Degirmenci
 * Contact: S.E.Degirmenci2@newcastle.ac.uk
 */

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
	~CommandLineManager();
	void handleCommandLine();
private:
	FileOperator* _fileOperator = nullptr;
	
	void initQuestionInitMap();
	void deleteQuestions();
	void initQuestions(std::vector<const char*>& rawTxtQuestions, std::vector<std::vector<const char*>>& rawAnswerTexts, BealCalculator& bealCalculator);
	void handleMainMenu();
	void handleQuestionsMenu();
	void handleQuestionUI(int selectedQuestionIndex);

	std::map<int, std::function<Question* (const char*, std::vector<const char*>&, BealCalculator&)>> _questionInitMap;
	std::vector<Question*> _questions;
};