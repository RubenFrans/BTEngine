#pragma once
#include <SDL_stdinc.h>
struct RGBColor {
	Uint8 r;
	Uint8 g;
	Uint8 b;
	RGBColor(Uint8 r, Uint8 g, Uint8 b)
		:r{r}, g{g}, b{b}
	{}
};