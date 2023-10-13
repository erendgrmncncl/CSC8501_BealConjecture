#pragma once

class CommandLineManager {
public:
	void handleCommandLine();
private:
	void init(const char* );
	void handleMainMenu();
	void handleQuestionsMenu();
};