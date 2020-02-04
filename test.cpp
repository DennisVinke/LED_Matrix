#include <stdio.h>
#include "wiringPi.h"
#include "led-matrix.h"

#include <unistd.h>
#include <math.h>
#include <stdio.h>
#include <signal.h>


using rgb_matrix::GPIO;
using rgb_matrix::RGBMatrix;
using rgb_matrix::Canvas; 

int buttons_piloc[] = { 35, 36, 37, 38, 31, 32 }; //Pi pin locations
int buttons[] = { 24, 27, 25, 28, 22, 26 }; //WiPi pin locations
//pin dir eq       ^   v   <   >   A   B

int states[] = { 0,  0,  0,  0,  0,  0 };

const char *bdf_font_file = NULL;
rgb_matrix::Font font;
int x_orig = 0;
int y_orig = 0;
int brightness = 100;
int letter_spacing = 0;
Canvas *canvas;

volatile bool interrupt_received = false;
static void InterruptHandler(int signo) {
	interrupt_received = true;
}

static void DrawOnCanvas(Canvas *canvas) {
	/*
	 * Let's create a simple animation. We use the canvas to draw
	 * pixels. We wait between each step to have a slower animation.
	 */
	canvas->Fill(0, 0, 255);

	for (float a = 0, r = 0; r < radius_max; a += angle_step, r += angle_step) {
		if (interrupt_received)
			return;
		canvas->SetPixel(0, 255, 0, 0);
		usleep(1 * 1000);  // wait a little to slow down things.
	}
}

int main(int argc, char *argv[]) {
	RGBMatrix::Options defaults;
	defaults.hardware_mapping = "regular";  // or e.g. "adafruit-hat"
	defaults.rows = 64;
	defaults.cols = 64;
	defaults.chain_length = 1;
	defaults.parallel = 1;
	defaults.show_refresh_rate = true;
	
	if (bdf_font_file!= NULL && !font.LoadFont(bdf_font_file)) {
		fprintf(stderr, "Couldn't load font '%s'\n", bdf_font_file);
		return 1;
	}

	canvas = rgb_matrix::CreateMatrixFromFlags(&argc, &argv, &defaults);
	if (canvas == NULL)
		return 1;
	
	// It is always good to set up a signal handler to cleanly exit when we
	// receive a CTRL-C for instance. The DrawOnCanvas() routine is looking
	// for that.
	signal(SIGTERM, InterruptHandler);
	signal(SIGINT, InterruptHandler);

	DrawOnCanvas(canvas);    // Using the canvas.

	// Animation finished. Shut down the RGB matrix.
	canvas->Clear();
	delete canvas;

	return 0;
}

void scanButtons()
{

	for (int i = 0; i < 6;i++) {
		states[i] = digitalRead(buttons[i]);
	}

	/*
	printf("  U: %d: - %d,", buttons[UP], digitalRead(buttons[UP]));
	printf("  D: %d: - %d,", buttons[DOWN], digitalRead(buttons[DOWN]));
	printf("  L: %d: - %d,", buttons[LEFT], digitalRead(buttons[LEFT]));
	printf("  R: %d: - %d,", buttons[RIGHT], digitalRead(buttons[RIGHT]));
	printf("  1: %d: - %d,", buttons[FIRE1], digitalRead(buttons[FIRE1]));
	printf("  2: %d: - %d,", buttons[FIRE2], digitalRead(buttons[FIRE2]));
	*/
	//printf("\n");
}

void setupButtons()
{

	wiringPiSetup();

	pinMode(buttons[UP], INPUT); //set input 
	pullUpDnControl(buttons[UP], PUD_UP); //set the pin to use a built-in pull up resistor

	pinMode(buttons[DOWN], INPUT);
	pullUpDnControl(buttons[DOWN], PUD_UP);

	pinMode(buttons[LEFT], INPUT);
	pullUpDnControl(buttons[LEFT], PUD_UP);

	pinMode(buttons[RIGHT], INPUT);
	pullUpDnControl(buttons[RIGHT], PUD_UP);

	pinMode(buttons[FIRE1], INPUT);
	pullUpDnControl(buttons[FIRE1], PUD_UP);

	pinMode(buttons[FIRE2], INPUT);
	pullUpDnControl(buttons[FIRE2], PUD_UP);
}

const char DIYCIE[] = "DIYCIE 2019";
const char NOGO[] = "NOGO?";
const char GO[] = "GO?";


void drawStartScreen() {
	char test = DIYCIE[0];
	// The regular text. Unless we already have filled the background with
		// the outline font, we also fill the background here.
	rgb_matrix::DrawText(canvas, font, x, y + font.baseline(),
		color, outline_font ? NULL : &bg_color, DIYCIE,
		letter_spacing);
}

void drawSelector(int x, int y) {
	for 
}

void drawNoGoScreen() {

}

void drawGoScreen() {

}
