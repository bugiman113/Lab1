#include "Libr.h"

void rotate() {
    struct pixel k;
    uint32_t m=bmpHeader.biHeight;
    uint32_t n=bmpHeader.biWidth;
    uint32_t x=0;
    uint32_t y=0;
    for (x = 0; x < n ; ++x) {
        for (y = 0; y < m; ++y) {
            pix2[x][y] = pix1[y][x];
        }
    }

}
