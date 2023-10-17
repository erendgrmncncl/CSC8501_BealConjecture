#include "QuestionOne.h"
#include "BealCalculator.h"

namespace {
    constexpr const int BNT_TO_FIND = 5;
}

QuestionOne::QuestionOne(const char* questionText, std::vector<const char*>& answersText, BealCalculator& bealCalculator) : Question(questionText, answersText, bealCalculator){
}

void QuestionOne::findAnswer(){
    std::vector<BealData> bnts;

	for (int A = 2; A < 10; A++) {
		for (int B = 2; B < A + 1; B++) {
			if (_bealCalculator->haveCommonPrimeFactor(A, B))
			{
				for (int C = 2; C < 10; C++) {
					if (_bealCalculator->haveCommonPrimeFactor(_bealCalculator->getGreatestCommonDivisior(A, B), C))
					{
						for (int x = 3; x < 10; x++) {
							for (int y = 3; y < 10; y++) {
								for (int z = 3; z < 10; z++) {
									if (_bealCalculator->isNumberSetFitsBealConjecture(A, B, C, x, y, z)) {
										BealData bealData(A, B, C, x, y, z);
										_bealCalculator->checkAndAddBNTToMinimumVec(bnts, bealData, BNT_TO_FIND);
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