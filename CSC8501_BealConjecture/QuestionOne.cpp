#include "QuestionOne.h"
#include "BealCalculator.h"

namespace {
    constexpr const int BNT_TO_FIND = 5;
}

QuestionOne::QuestionOne(const char* questionText, std::vector<const char*>& answersText, BealCalculator& bealCalculator) : Question(questionText, answersText, bealCalculator){
}

void QuestionOne::findAnswer(){
    int foundBNTCount = 0;
	for (int A = 2; A < 100; A++) {
        for (int B = 2; B < 100; B++){
            for (int x = 3; x < 100; x++){
                for (int y = 3; y < 100; y++){
                    for (int C = 2; C < 100; C++){
                        for (int z = 3; z < 100; z++){
                            if (_bealCalculator->isNumberSetFitsBealConjecture(A, B, C, x, y, z)){
                                BealData* data = new BealData(A, B, C, x, y, z);
                                _answers.push_back(data);
                                foundBNTCount++;
                                if (foundBNTCount == BNT_TO_FIND) {
                                    return;
                                }
                            }
                        }
                    }
                }
            }
        }
      
    }


}