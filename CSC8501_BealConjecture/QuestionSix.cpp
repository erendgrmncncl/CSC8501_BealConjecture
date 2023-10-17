#include "QuestionSix.h"
#include "Question.h"
#include "BealCalculator.h"

namespace {
    constexpr const int MIN_LIMIT = 1000;
    constexpr const int MAX_LIMIT = 10000;
}

QuestionSix::QuestionSix(const char* questionText, std::vector<const char*>& answersText, BealCalculator& bealCalculator) : Question(questionText, answersText, bealCalculator)
{
}

void QuestionSix::findAnswer(){
    std::vector<BealData> bnts;

    for (int A = 2; A < 1000; A++) {
        for (int B = 2; B < A + 1; B++) {
            if (_bealCalculator->haveCommonPrimeFactor(A,B)){
                for (int x = 3; x < 1000; x++) {
                    for (int y = 3; y < 1000; y++) {
                        for (int C = 2; C < 1000; C++) {
                            for (int z = 3; z < 1000; z++) {
                                int tempBNTVal = A + B + C + x + y + z;
                                if (tempBNTVal >= 1000 && tempBNTVal <= 10000 && _bealCalculator->isNumberSetFitsBealConjecture(A, B, C, x, y, z) && _bealCalculator->isSquareNumber(tempBNTVal)) {
                                    BealData bealData(A, B, C, x, y, z);
                                    if (std::find(bnts.begin(), bnts.end(), bealData) == bnts.end()) {
                                        bnts.push_back(bealData);
                                    }
                                }
                            }
                        }
                    }
                }
            }
            
        }
    }

    for (auto& bealData : bnts) {
        BealData* data = new BealData(bealData.A, bealData.B, bealData.C, bealData.x, bealData.y, bealData.z);
        _answers.push_back(data);
    }
}
