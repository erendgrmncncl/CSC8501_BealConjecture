#include "Question.h"

class QuestionTwo : public Question {
public:
	QuestionTwo(const char* questionText, std::vector<const char*>& answersText, BealCalculator& bealCalculator);
	void findAnswer() override;
};