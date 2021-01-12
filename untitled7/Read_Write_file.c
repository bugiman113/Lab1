#include "Libr.h"
uint32_t account_xy(const uint64_t width, const uint64_t x, const uint64_t y);

enum read_status bmp_read(FILE* in, struct image* img, struct bmp_header* bmpHeader1) {
    uint32_t mx = bmpHeader1->biWidth;
    uint32_t my = bmpHeader1->biHeight;
    uint32_t mx3 = (3*mx+3) & (-4);
    size_t str;
    //считывание файла
    for(uint32_t i = 0; i < my; ++i){
        uint32_t n= account_xy(mx, 0, i);
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
}//bmp_read

enum write_status bmp_create(FILE* file, struct image img, uint32_t mx, uint32_t my){
    uint32_t mx3 = (3*mx+3) & (-4);
    for (uint32_t j = 0; j < my; j++) {
        for (uint32_t i = 0; i < mx; i++) {
            uint32_t n= account_xy(mx, i, j);
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
}//bmp_create

