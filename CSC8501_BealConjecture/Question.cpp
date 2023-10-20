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

Question::Question(const char* questionText, std::vector<const char*>& answers, BealCalculator& bealCalculator){
    _questionText = questionText;
    _bealCalculator = &bealCalculator;
    for (auto* answer : answers) {
        if (answer != nullptr){
            parseAnswerTextToBealData(answer);
        }
    }
}

const char* Question::getQuestionText(){
    return _questionText;
}

std::vector<BealData>& Question::getAnswers(){
    return _answers;
}

void Question::findAnswer(){
}

void Question::parseAnswerTextToBealData(const char* answersText){
    int values[6] = { 0 };

    int parsed = sscanf_s(answersText, "%*d: %d, %d, %d, %d, %d, %d",
        &values[A_INDEX], &values[X_INDEX], &values[B_INDEX],
        &values[Y_INDEX], &values[C_INDEX], &values[Z_INDEX]);
    
    BealData answer(values[A_INDEX], values[X_INDEX], values[B_INDEX], values[Y_INDEX], values[C_INDEX], values[Z_INDEX]);
    _answers.push_back(answer);
}

