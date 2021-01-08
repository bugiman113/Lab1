#include "Libr.h"
uint32_t numb_by_xy(const uint64_t width, const uint64_t x, const uint64_t y){
    return width*y+x;
}
struct bmp_header create_bmp_header(const uint64_t w, const uint64_t h, struct bmp_header bmpHeader){
    uint32_t mx3 = (3*w+3) & (-4);
    bmpHeader.bfType= 19778;
    bmpHeader.bfileSize= 54 + mx3 * h;
    bmpHeader.bfReserved=0;
    bmpHeader.bOffBits=54;
    bmpHeader.biSize=40;
    bmpHeader.biWidth=h;
    bmpHeader.biHeight=w;
    bmpHeader.biPlanes=1;
    bmpHeader.biBitCount=24;
    bmpHeader.biCompression=0;
    bmpHeader.biSizeImage= bmpHeader.bfileSize - bmpHeader.bOffBits;
    bmpHeader.biXPelsPerMeter=4724;
    bmpHeader.biYPelsPerMeter=4724;
    bmpHeader.biClrUsed=0;
    bmpHeader.biClrImportant=0;
    return bmpHeader;
}

void print_newline(){
    printf("\n");
}