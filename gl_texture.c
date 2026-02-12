#include "gl_texture.h"
#include "loadpng.h"

/* Draw rectangle with current bound texture */
void Draw_Rect(Rect *Rct) {
    glBegin(GL_POLYGON);
        glTexCoord2f(0.0f, 0.0f);
        glVertex2f((int)Rct->Left,  (int)Rct->Bottom);
        glTexCoord2f(1.0f, 0.0f);
        glVertex2f((int)Rct->Right, (int)Rct->Bottom);
        glTexCoord2f(1.0f, 1.0f);
        glVertex2f((int)Rct->Right, (int)Rct->Top);
        glTexCoord2f(0.0f, 1.0f);
        glVertex2f((int)Rct->Left,  (int)Rct->Top);
    glEnd();
}

/* Upload image pixels to current OpenGL texture */
void Map_Texture(Image* img) {
    glTexImage2D(GL_TEXTURE_2D,
                 0,
                 GL_RGBA,
                 img->w,
                 img->h,
                 0,
                 GL_RGBA,
                 GL_UNSIGNED_BYTE,
                 img->img);
}

/* Load PNG without vertical swap */
void Load_Texture(Image* img, const char* path) {
    unsigned char* data;
    unsigned w, h;

    Load_Png(&data, &w, &h, path);

    img->img = data;
    img->w = w;
    img->h = h;
}

/* Load PNG and vertically flip it */
void Load_Texture_Swap(Image* img, const char* path) {
    unsigned char* data;
    unsigned w, h;

    Load_Png_Swap(&data, &w, &h, path);

    img->img = data;
    img->w = w;
    img->h = h;
}

/* Nearest-neighbor zoom of image by integer scale */
void Zoom_Image(Image* img, int scale) {
    Image zoomed;
    int newW, newH;
    int x, y;
    int srcX, srcY;
    int dstI, srcI;

    if (scale <= 1) return;

    newW = img->w * scale;
    newH = img->h * scale;

    Create_Image(&zoomed, newW, newH);

    for (y = 0; y < newH; ++y) {
        for (x = 0; x < newW; ++x) {
            srcX = x / scale;
            srcY = y / scale;

            dstI = (y * newW + x) * 4;
            srcI = (srcY * img->w + srcX) * 4;

            zoomed.img[dstI + 0] = img->img[srcI + 0];
            zoomed.img[dstI + 1] = img->img[srcI + 1];
            zoomed.img[dstI + 2] = img->img[srcI + 2];
            zoomed.img[dstI + 3] = img->img[srcI + 3];
        }
    }

    Delete_Image(img);
    *img = zoomed;
}
