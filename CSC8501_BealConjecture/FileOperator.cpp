#include "FileOperator.h"
#include <iostream>
#include <fstream>
#include <string>

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

std::vector<const char*> FileOperator::seperateQuestions(const char* questionsText){

    std::vector<const char*> lines;

    if (questionsText == nullptr) {
        return lines;
    }

    const char* start = questionsText;
    const char* end = questionsText;

    while (*end != '\0') {
        if (*end == '\n' || *end == '\r') {
            if (start != end) {
                // Calculate the length of the line
                size_t length = end - start;
                // Allocate memory for the line and copy it using strncpy_s
                char* line = new char[length + 1];
                strncpy_s(line, length + 1, start, length);
                line[length] = '\0';
                // Add the line to the vector
                lines.push_back(line);
            }
            start = end + 1; // Move start to the next character after newline
        }
        end++;
    }

    // Handle the last line (if it doesn't end with a newline)
    if (start != end) {
        size_t length = end - start;
        char* line = new char[length + 1];
        strncpy_s(line, length + 1, start, length);
        line[length] = '\0';
        lines.push_back(line);
    }

    return lines;
}

const char* FileOperator::seperateAnswers(const char* questionsText)
{
    return nullptr;
}
