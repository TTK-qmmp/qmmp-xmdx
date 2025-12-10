// fade 
// BouKiCHi 2021

#include "fade.h"

Fade::Fade() {}

Fade::Fade(int audioRate, int startSeconds)
{
	enable = true;
	rate = audioRate;
	volume = 1.0f;
	count = 0;
	start = startSeconds * rate;
	length = rate * 3;
	left = length;
	mode = false;
}

void Fade::Step(int frames) {
	count += frames;
	if (!enable) return;

	if (mode) {
		volume = ((double)left / length);
		if (left > 0) left--;
	}

	if (!mode && start <= count) { mode = true; }
}
