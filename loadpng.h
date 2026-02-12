#ifndef LOADPNG_H
#define LOADPNG_H

#include "lodepng.h"

#ifdef __cplusplus
extern "C" {
#endif

void Swap_Image(unsigned char *img, unsigned w, unsigned h);
void Load_Png(unsigned char** img, unsigned* w, unsigned* h, const char* filename);
void Load_Png_Swap(unsigned char** img, unsigned* w, unsigned* h, const char* filename);

#ifdef __cplusplus
}
#endif

#endif // LOADPNG_H
