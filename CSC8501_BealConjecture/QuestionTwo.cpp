#include "QuestionTwo.h"
#include "BealCalculator.h"

namespace {
    constexpr const int BNT_TO_FIND = 5;
}

QuestionTwo::QuestionTwo(const char* questionText, std::vector<const char*>& answersText, BealCalculator& bealCalculator) : Question(questionText, answersText, bealCalculator){

}

void QuestionTwo::findAnswer(){
    std::vector<BealData> bnts;

    for (int A = 2; A < 20; A++) {
        for (int B = 2; B < 20; B++) {
            for (int x = 3; x < 20; x++) {
                for (int y = 3; y < 20; y++) {
                    for (int C = 2; C < 20; C++) {
                        for (int z = 3; z < 20; z++) {                            
                            if (_bealCalculator->isNumberSetFitsBealConjecture(A, B, C, x, y, z) && _bealCalculator->isPrimeNumber(A+B+C+x+y+z)){
                                BealData bealData(A, B, C, x, y, z);
                                _bealCalculator->checkAndAddBNTToMinimumVec(bnts, bealData, BNT_TO_FIND);
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
