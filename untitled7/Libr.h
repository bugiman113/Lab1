#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <windows.h>
#ifndef UNTITLED7_LIBR_H
#define UNTITLED7_LIBR_H
#pragma pack(push, 1)

struct bmp_header {
    uint16_t bfType;
    uint32_t bfileSize;
    uint32_t bfReserved;
    uint32_t bOffBits;
    uint32_t biSize;
    uint32_t biWidth;
    uint32_t biHeight;
    uint16_t biPlanes;
    uint16_t biBitCount;
    uint32_t biCompression;
    uint32_t biSizeImage;
    uint32_t biXPelsPerMeter;
    uint32_t biYPelsPerMeter;
    uint32_t biClrUsed;
    uint32_t biClrImportant;
};
#pragma pack(pop)
enum read_status  {
    READ_OK = 0,
    READ_INVALID_BITS = 2,
    READ_INVALID_HEADER = 3,
    FILE_NOT_FOUND = 4,
    READ_INVALID_SIGNATURE = 1,
};
enum  write_status  {
    WRITE_OK = 0,
    WRITE_ERROR = 1
};

struct image {
    uint64_t width, height;
    struct pixel* data;
};
struct pixel { uint8_t r, g, b; };
struct image rotate1(const struct image source);

void create_img(struct image *image, const uint64_t w, const uint64_t h);
void destroy_img(struct image *img);
struct bmp_header create_bmp_header(const uint64_t w, const uint64_t h, struct bmp_header bmpHeader);
void print_newline();
void error(FILE* file,const char* filename,struct image image0,struct image image1,int32_t e);

enum read_status read_header( FILE* in,struct bmp_header* bmpHeader1);
enum write_status write_header( FILE* file,struct bmp_header bmpHeader);
enum read_status from_bmp1( FILE* in, struct image* img,struct bmp_header* bmpHeader1);
enum write_status to_bmp1( const char* filename,FILE* file, struct image img, uint32_t mx,uint32_t my);

const char *read_filename1(int k);
int checkingFile1(FILE* file,const char* filename);
enum read_status checkingFile2(FILE* file,const char* filename,struct image image0);
#endif