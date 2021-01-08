#include "Libr.h"
uint32_t numb_by_xy(const uint64_t width, const uint64_t x, const uint64_t y);
enum read_status read_header( FILE* in,struct bmp_header* bmpHeader1) {
    size_t str=fread(bmpHeader1, sizeof(struct bmp_header), 1, in);
    if ((str!=1) || (bmpHeader1->bfType != 19778) || (bmpHeader1->biBitCount != 24)) {
        printf("Corrupted file: ");
        return READ_INVALID_HEADER;
    }
    return READ_OK;
}//read_header

enum write_status write_header( FILE* file,struct bmp_header bmpHeader){
    size_t st;
    st = fwrite(&bmpHeader, sizeof(bmpHeader), 1, file);
    if (st==1){
        return WRITE_OK;
    }
    return WRITE_ERROR;
}//write_header

enum read_status from_bmp1( FILE* in, struct image* img,struct bmp_header* bmpHeader1) {
    uint32_t i, n;
    uint32_t mx = bmpHeader1->biWidth;
    uint32_t my = bmpHeader1->biHeight;
    uint32_t mx3 = (3*mx+3) & (-4);
    size_t str;
    //считывание файла
    for(i = 0; i < my; ++i){
        n=numb_by_xy(mx, 0, i);
        str=fread(&img->data[n], sizeof(struct pixel), mx, in);
        if (str!=mx){
            return READ_INVALID_BITS;
        }
        uint32_t ost=mx3-mx*3;
        for (uint32_t jj = 0; jj < ost; jj++) {
            uint8_t tmp=0;
            if (fread(&tmp, sizeof(uint8_t), 1, in)!=1){
                return READ_INVALID_BITS;
            }
        }
    }
    return READ_OK;
}//from_bmp

enum write_status to_bmp1(const char* filename,FILE* file, struct image img, uint32_t mx,uint32_t my){
    uint32_t i, j, n;
    uint32_t mx3 = (3*mx+3) & (-4);
    for (j = 0; j < my; j++) {
        for (i = 0; i < mx; i++) {
            n=numb_by_xy(mx, i, j);
            fwrite(&img.data[n], sizeof(struct pixel), 1, file);
        }
        uint32_t ost=mx3-mx*3;
        for (uint32_t jj = 0; jj < ost; jj++) {
            uint8_t tmp=0;
            if (fwrite(&tmp, sizeof(uint8_t), 1, file)==0){
                return WRITE_ERROR;
            }
        }
    }
    return WRITE_OK;
}//to_bmp