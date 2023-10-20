#include "FileOperator.h"
#include <iostream>
#include <fstream>
#include <string>
#include "BealCalculator.h"

namespace {
    constexpr const char* ANSWERS_FILE_NAME_PREFIX = "Answer";
    constexpr const char* ANSWER_FILE_EXTENSION = ".txt";
}

const char* FileOperator::getTextInFile(const char* fileName){
    std::ifstream file(fileName);
    if (!file.is_open())
        return nullptr;

    std::string fileContents;
    std::string line;

    while (std::getline(file, line)) {
        fileContents += line + '\n';
    }
    file.close();

    const size_t resultSize = fileContents.size() + 1;
    char* result = new char[resultSize];
    strcpy_s(result, resultSize, fileContents.c_str());

    return result;
}

std::vector<const char*> FileOperator::seperateLines(const char* questionsText){

    std::vector<const char*> lines;

    if (questionsText == nullptr) {
        return lines;
    }

    const char* start = questionsText;
    const char* end = questionsText;

    while (*end != '\0') {
        if (*end == '\n' || *end == '\r') {
            if (start != end) {
                size_t length = end - start;
                char* line = new char[length + 1];
                strncpy_s(line, length + 1, start, length);
                line[length] = '\0';
                lines.push_back(line);
            }
            start = end + 1;
        }
        end++;
    }

    if (start != end) {
        size_t length = end - start;
        char* line = new char[length + 1];
        strncpy_s(line, length + 1, start, length);
        line[length] = '\0';
        lines.push_back(line);
    }

    return lines;
}

void FileOperator::createAnswersFile(int questionNumber, const std::vector<BealData>& answers){
    std::string filename = "Answer" + std::to_string(questionNumber) + ".txt";
    std::ofstream file(filename);

    if (!file.is_open()) {
        std::cerr << "Error opening file for writing." << std::endl;
        return;
    }

    for (auto& data : answers) {
        file << data.getBealTotalNumber() << ":" << data.A << "," << data.B << "," << data.C << "," << data.x << "," << data.y << "," << data.z << std::endl;
    }

    file.close();
    std::cout << "File " << filename << " created successfully." << std::endl;
}

void FileOperator::parseAnswersToLines(std::vector<std::vector<const char*>>& parsedAnswerTexts, int questionCount){
    for (int i = 0; i < questionCount; i++) {
        char fileName[50];
        strcpy_s(fileName, sizeof(fileName), (char*)ANSWERS_FILE_NAME_PREFIX);
        std::string questionNumber = std::to_string(i + 1);
        const char* numbertxt = questionNumber.c_str();
        strcat_s(fileName, sizeof(fileName), numbertxt);
        strcat_s(fileName, sizeof(fileName), ANSWER_FILE_EXTENSION);
        const char* answerTxt = getTextInFile(fileName);
        parsedAnswerTexts.push_back(seperateLines(answerTxt));
    }
}
