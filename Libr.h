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
}bmpHeader;
#pragma pack(pop)
enum read_status  {
    READ_OK = 0,
    READ_INVALID_BITS = 2,
    READ_INVALID_HEADER = 3,
    //FILE_NOT_FOUND = 4
    READ_INVALID_SIGNATURE = 1,
};
enum  write_status  {
    WRITE_OK = 0,
    WRITE_ERROR = 1
};

struct image {
    uint64_t width, height;
    struct pixel* data;
}image0, image1;
struct pixel { uint8_t r, g, b; };
struct bmp_header* bmpHeader1;
struct image rotate1(const struct image source);

void create_img(struct image *image, const uint64_t w, const uint64_t h);
void destroy_img(struct image *img);
void create_bmp_header( const uint64_t w, const uint64_t h);
void check_Header();
void check_pix(struct pixel const pix);
void print_newline();

enum read_status read_header( FILE* in);
enum write_status write_header( FILE* file);
enum read_status from_bmp1( FILE* in, struct image img);
enum write_status to_bmp1( const char* filename,FILE* file, struct image img );

const char *read_filename1();
const char *read_filename2();
uint32_t numb_by_xy(const uint64_t width, const uint64_t x, const uint64_t y);
#endif