#include "QuestionSix.h"
#include <iostream>
#include "Question.h"
#include "BealCalculator.h"
#include <thread>

namespace {
    constexpr const int MIN_LIMIT = 1000;
    constexpr const int MAX_LIMIT = 100000;
}

QuestionSix::QuestionSix(const char* questionText, std::vector<const char*>& answersText, BealCalculator& bealCalculator) : Question(questionText, answersText, bealCalculator)
{
}

void QuestionSix::findAnswer(){
    std::vector<int> squareNumbers = findSquareNumbersInRange(MIN_LIMIT, MAX_LIMIT);
    
    calculateBNTsInThreads(squareNumbers, _answers);
}
//2^n + 2^n = 2^n+1
bool QuestionSix::isNumberInFormatPowerOfTwo(int squareNumber){
    return (squareNumber - 7) % 3 == 0;
}
//2^4n-1 + 2^4n-1 = 16^n
bool QuestionSix::isNumberInFormatPowerOfSixteen(int squareNumber){
    return (squareNumber - 18) % 9 == 0;
}

void QuestionSix::calculateBNTsInThreads(std::vector<int>& squareNumbers, std::vector<BealData>& bnts){
    std::vector<std::thread> threads;

    int threadCount = std::thread::hardware_concurrency();
    int partVectorSize = squareNumbers.size() / threadCount;
    
    for (int i = 0; i < threadCount; ++i) {
        int startIdx = i * partVectorSize;
        int endIdx = (i == threadCount - 1) ? squareNumbers.size() : startIdx + partVectorSize;
        std::vector<int> partVec(squareNumbers.begin() + startIdx, squareNumbers.begin() + endIdx);
        threads.emplace_back(&QuestionSix::checkIsSquareNumberBNT, this, partVec, std::ref(bnts));
    }

    for (auto& thread : threads) {
        thread.join();
    }
}

void QuestionSix::checkIsSquareNumberBNT(std::vector<int> squareNumbers, std::vector<BealData>& bnts){
    int xValue = 0;
    int yValue = 0;
    int zValue = 0;
    int aValue = 0;
    int bValue = 0;
    int cValue = 0;
    for (int squareNumber : squareNumbers) {
        bool isFittingToBealConjecture = false;
        
        if (isNumberInFormatPowerOfTwo(squareNumber)){
            isFittingToBealConjecture = true;
            int n = (squareNumber - 7) / 3;
            xValue = n;
            yValue = xValue;
            zValue = n +1;

            aValue = 2;
            bValue = 2;
            cValue = 2;
        }
        else if (isNumberInFormatPowerOfSixteen(squareNumber)) {
            isFittingToBealConjecture = true;
            int n = (squareNumber -18) / 9;
            xValue = 4 * n - 1;
            yValue = xValue;
            zValue = n;

            aValue = 2;
            bValue = 2;
            cValue = 16;
        }

        if (isFittingToBealConjecture){
            BealData bealData(aValue, bValue, cValue, xValue, yValue, zValue);
            bnts.push_back(bealData);
        }

    }
}

std::vector<int> QuestionSix::findSquareNumbersInRange(int start, int end){
    std::vector<int> squareNumbers;
    start = std::max(0, start);

    for (int i = start; i <= end; i++) {
        int root = static_cast<int>(std::sqrt(i));
        if (root * root == i) {
            squareNumbers.push_back(i);
        }
    }

    return squareNumbers;
}
