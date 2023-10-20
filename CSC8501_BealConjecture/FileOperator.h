/**
 * @file FileOperator.h
 *
 * @brief Handles file read write operations.
 *
 *
 * @author Salih Eren Degirmenci
 * Contact: S.E.Degirmenci2@newcastle.ac.uk
 */

#pragma once
#include<vector>
struct BealData;

class FileOperator {
public:
	const char* getTextInFile(const char* fileName);
	std::vector<const char*> seperateLines(const char* questionsText);
	void createAnswersFile(int questionNumber, const std::vector<BealData>& answers);
	void parseAnswersToLines(std::vector<std::vector<const char*>>& parsedAnswerTexts, int questionCount);
};