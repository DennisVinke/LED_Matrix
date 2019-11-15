#include "led-matrix.h"

#include <unistd.h>
#include <math.h>
#include <stdio.h>
#include <signal.h>

class Program {
public:
	Program();
	~Program();
	virtual void display() = 0;
	virtual void update() = 0;
private:
	void swapBuffer();

};