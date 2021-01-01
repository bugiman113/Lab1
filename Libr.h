#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <windows.h>
#ifndef UNTITLED7_LIBR_H
#define UNTITLED7_LIBR_H
#pragma pack(push, 1)

struct bmp_header
{
    uint16_t bfType;
    uint32_t  bfileSize;
    uint32_t bfReserved;
    uint32_t bOffBits;
    uint32_t biSize;
    uint32_t biWidth;
    uint32_t  biHeight;
    uint16_t  biPlanes;
    uint16_t biBitCount;
    uint32_t biCompression;
    uint32_t biSizeImage;
    uint32_t biXPelsPerMeter;
    uint32_t biYPelsPerMeter;
    uint32_t biClrUsed;
    uint32_t  biClrImportant;
}bmpHeader;
#pragma pack(pop)
enum read_status  {
    READ_OK = 0,
    READ_INVALID_SIGNATURE = 1,
    READ_INVALID_BITS = 2,
    READ_INVALID_HEADER = 3,
    FILE_NOT_FOUND = 4
    /* коды других ошибок  */
};

enum  write_status  {
    WRITE_OK = 0,
    WRITE_ERROR = 1
    /* коды других ошибок  */
};

struct pixel { uint8_t r, g, b; };
//struct pixel** pix;
struct pixel** pix1;
struct pixel** pix2;
unsigned char* img1,img2;
unsigned char** img;
void clear_pix1();
void clear_pix2();
#endif //UNTITLED7_LIBR_H
