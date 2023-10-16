#include "FileOperator.h"
#include <iostream>
#include <fstream>
#include <string>

#include "BealCalculator.h"

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

void FileOperator::createAnswersFile(int questionNumber, const std::vector<BealData*>& answers){
    std::string filename = "Answer" + std::to_string(questionNumber) + ".txt";
    std::ofstream file(filename);

    if (!file.is_open()) {
        std::cerr << "Error opening file for writing." << std::endl;
        return;
    }

    for (BealData* data : answers) {
        file << data->getBealTotalNumber() << ":" << data->A << "," << data->B << "," << data->C << "," << data->x << "," << data->y << "," << data->z << std::endl;
    }

    file.close();
    std::cout << "File " << filename << " created successfully." << std::endl;
}
