#include "QuestionOne.h"
#include "BealCalculator.h"

namespace {
    constexpr const int BNT_TO_FIND = 5;
}

QuestionOne::QuestionOne(const char* questionText, std::vector<const char*>& answersText, BealCalculator& bealCalculator) : Question(questionText, answersText, bealCalculator)
{
}

void QuestionOne::findAnswer(){
    int foundBNTCount = 0;
	for (int A = 3; foundBNTCount < BNT_TO_FIND; A++) {
        for (int B = A + 1; B <= A * 2; B++) {
            int C = A + B;
            for (int x = 3; x < 100; x++) {
                for (int y = x + 1; y < 100; y++) {
                    for (int z = y + 1; z < 100; z++) {
                        if (_bealCalculator->haveCommonPrimeFactor(A, B)) {
                            BealData* data = new BealData(A, B, C, x, y, z);
                            _answers.push_back(data);
                            foundBNTCount++;
                            if (foundBNTCount == 5)
                                return;
                        }
                    }
                }
            }
        }
    }


}