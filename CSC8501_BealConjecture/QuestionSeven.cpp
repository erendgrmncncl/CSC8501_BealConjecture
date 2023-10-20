#include "QuestionSeven.h"
#include "BealCalculator.h"
#include "MathTemplates.h"
#include <iostream>

namespace {
    constexpr const int MIN_BASE_VALUE = 2;
    constexpr const int MAX_BASE_VALUE = 20;
    constexpr const int MIN_EXPONENT_VALUE = 3;
    constexpr const int MAX_EXPONENT_VALUE = 15;

    constexpr const int HISTOGRAM_EMPTY_CELL_CHAR_COUNT = 20;
}


QuestionSeven::QuestionSeven(const char* questionText, std::vector<const char*>& answersText, BealCalculator& bealCalculator) : Question(questionText, answersText, bealCalculator) {

}

void QuestionSeven::findAnswer(){
    std::map<int, int> bntFrequencyMap;
    int minBntValue = 0;
    int maxBntValue = 0;
    std::cout << "Enter min BNT value: ";
    std::cin >> minBntValue;

    std::cout << "Enter max BNT value: ";
    std::cin >> maxBntValue;
    bntFrequencyMap = _bealCalculator->searchForBNTsWithFrequencyMultiThread(_answers, MIN_BASE_VALUE, MAX_BASE_VALUE, MIN_EXPONENT_VALUE, MAX_EXPONENT_VALUE, minBntValue, maxBntValue);

    drawHistogram(bntFrequencyMap);
}

void QuestionSeven::drawHistogram(const std::map<int, int>& bntOccurances){
    std::cout << "BNT                 " << "|Count              " << "|Histogram          " << std::endl;
    std::cout << "--------------------" << "--------------------" << "--------------------" << std::endl;
    for (const auto& bntPair : bntOccurances) {
        std::cout << bntPair.first;
        int digitCount = countDigits(bntPair.first);
        printSpaceForColumn(digitCount);
        std::cout<< "|" << bntPair.second;
        printSpaceForColumn(countDigits(bntPair.second) + 1);
        std::cout << "|";
        for (int i = 0; i < bntPair.second; i++){
            std::cout << "*";
        }
       std::cout << std::endl;
    }
}

void QuestionSeven::printSpaceForColumn(int printedCharCount){
    for (int i = 0; i < HISTOGRAM_EMPTY_CELL_CHAR_COUNT - printedCharCount; i++){
        std::cout << " ";
    }
}
