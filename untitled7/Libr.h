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
struct image image_turn(struct image const source, uint32_t my, uint32_t mx);

struct image image_create(struct image* image, const uint64_t w, const uint64_t h);
void image_destroy(struct image *img);
struct bmp_header header_bmp_create(const uint64_t w, const uint64_t h);
void print_newline();
void error_message(int32_t e);

enum read_status header_read(FILE* in, struct bmp_header* bmpHeader1);
enum write_status header_write(FILE* file, struct bmp_header bmpHeader);
enum read_status bmp_read(FILE* in, struct image* img, struct bmp_header* bmpHeader1);
enum write_status bmp_create(FILE* file, struct image img, uint32_t mx, uint32_t my);

const char* read_filename1(char s[]);
const char* read_filename2(char s[]);
void checkingFile1(FILE* file,const char* filename);
enum read_status checkingFile2(FILE* file,const char* filename,struct image image0);
#endif