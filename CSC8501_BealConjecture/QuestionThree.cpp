#include "QuestionThree.h"
#include "BealCalculator.h"
#include "IsPrimeTemplate.h"

namespace {
    constexpr const int BNT_TO_FIND = 5;
}

QuestionThree::QuestionThree(const char* questionText, std::vector<const char*>& answersText, BealCalculator& bealCalculator) : Question(questionText, answersText, bealCalculator){

}

void QuestionThree::findAnswer(){
    std::vector<BealData> bnts;

    for (int A = 2; A < 20; A++) {
        for (int B = 2; B < 20; B++) {
            for (int x = 3; x < 15; x++) {
                for (int y = 3; y < 15; y++) {
                    for (int C = 2; C < 20; C++) {
                        for (int z = 3; z < 15; z++) {
                            if (_bealCalculator->isNumberSetFitsBealConjecture(A, B, C, x, y, z) && isPrime(A + B + C + x + y + z)) {
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

    for (auto& bealData : bnts) {
        BealData* data = new BealData(bealData.A, bealData.B, bealData.C, bealData.x, bealData.y, bealData.z);
        _answers.push_back(data);
    }
}
