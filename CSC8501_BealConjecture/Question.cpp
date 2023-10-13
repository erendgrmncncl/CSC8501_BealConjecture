#include "Question.h"
#include "BealCalculator.h"

namespace {
    constexpr const int A_INDEX = 0;
    constexpr const int X_INDEX = 1;
    constexpr const int B_INDEX = 2;
    constexpr const int Y_INDEX = 3;
    constexpr const int C_INDEX = 4;
    constexpr const int Z_INDEX = 5;
}

Question::Question(const char* questionText, const char* answersText){
    _questionText = (char*)questionText;
    parseAnswerTextToBealData(answersText);
}

void Question::parseAnswerTextToBealData(const char* answersText){
    int values[6] = { 0 };

    int parsed = sscanf(answersText, "%*d: %d, %d, %d, %d, %d, %d",
        &values[A_INDEX], &values[X_INDEX], &values[B_INDEX],
        &values[Y_INDEX], &values[C_INDEX], &values[Z_INDEX]);
    
    _bealData = new BealData(values[A_INDEX], values[X_INDEX], values[B_INDEX], values[Y_INDEX], values[C_INDEX], values[Z_INDEX]);
}
