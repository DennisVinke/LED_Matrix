#include "Program.hpp"
#include <vector>

class ApplicationManager {
public:
	ApplicationManager();
	~ApplicationManager();
	void display();
	void update();
private:
	void switchProgramms();

	std::vector<Program> applications;
	int index;
};