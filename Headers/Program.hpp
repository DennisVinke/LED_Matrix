#include "led-matrix.h"

#include <unistd.h>
#include <math.h>
#include <stdio.h>
#include <signal.h>


//Iets doen met de framebuffer en die doorgeven

class Program {
public:
	Program();
	~Program();
	virtual void display() = 0;
	virtual void update() = 0;
	void quitApplication();
private:
	void swapBuffer();

};