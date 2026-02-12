#ifndef GL_TEXTURE_H
#define GL_TEXTURE_H

#ifdef __cplusplus
extern "C" {
#endif

#include "process_image.h"  /* defines struct Image */
#include <GL/glut.h>

typedef struct Rect {
    float Left, Right, Bottom, Top;
} Rect;

/* Prototypes only – no function bodies here */
void Load_Texture(Image* img, const char* path);
void Load_Texture_Swap(Image* img, const char* path);
void Map_Texture(Image* img);
void Draw_Rect(Rect *Rct);
void Zoom_Image(Image* img, int scale);

#ifdef __cplusplus
}
#endif

#endif /* GL_TEXTURE_H */
