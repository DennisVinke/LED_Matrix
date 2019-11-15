
#include <math.h>
#include <stdio.h>
#include <signal.h>


//Iets doen met de framebuffer en die doorgeven
//Hallo reflection implementatie.
//Wat leuk dat je er komt
//Wat jammer dat je er niet al bent
//Wat na het implementeren ga ik huilen als een vent
https://stackoverflow.com/questions/582331/is-there-a-way-to-instantiate-objects-from-a-string-holding-their-class-name
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