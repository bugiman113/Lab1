#include "Libr.h"

uint32_t numb_by_xy(const uint64_t width, const uint64_t x, const uint64_t y){
    return width*y+x;
}

void create_bmp_header( const uint64_t w, const uint64_t h){
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

}
void check_Header(){
    if (
            (bmpHeader.bfType < 0) || (
                    bmpHeader.bfileSize < 0) || (
                    bmpHeader.bfReserved < 0) || (
                    bmpHeader.bOffBits < 0) || (
                    bmpHeader.biSize < 0) || (
                    bmpHeader.biWidth < 0) || (
                    bmpHeader.biHeight < 0) || (
                    bmpHeader.biPlanes < 0) || (
                    bmpHeader.biBitCount < 0) || (
                    bmpHeader.biCompression < 0) || (
                    bmpHeader.biSizeImage < 0) || (
                    bmpHeader.biXPelsPerMeter < 0) || (
                    bmpHeader.biYPelsPerMeter < 0) || (
                    bmpHeader.biClrUsed < 0) || (
                    bmpHeader.biClrImportant < 0)){

    }
}
void check_pix(struct pixel const pix){
    if ((pix.r<0)||(pix.g<0)||(pix.b<0)){}
}
void print_newline(){
    printf("\n");
}