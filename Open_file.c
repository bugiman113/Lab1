#include "Libr.h"

void clear_pix1() {
    for( uint32_t ii = 0; ii < bmpHeader.biHeight; ++ii)
        free(pix1[ii]);
    free(pix1);
}
void clear_pix2() {
    for( uint32_t ii = 0; ii < bmpHeader.biHeight; ++ii)
        free(pix2[ii]);
    free(pix2);
}
enum read_status from_bmp( FILE* in) {
    uint32_t i, j;
    size_t str=fread(&bmpHeader, sizeof(bmpHeader), 1, in);
    if (str==0){
        return READ_INVALID_SIGNATURE;//!!!
    }
    if (bmpHeader.bfType != 19778 ) {//|| bmpHeader.bitPixel != 24
        printf("Corrupted file ");
        return READ_INVALID_HEADER;
    }
    uint32_t my = bmpHeader.biHeight;
    uint32_t mx = bmpHeader.biWidth;
    uint32_t mx3 = (3*mx+3) & (-4);
    uint32_t my3 = (3*my+3) & (-4);

    //выделили память
    pix1 = (struct pixel**)calloc(my, sizeof(*pix1));
    //считывание файла
    for(i = 0; i < my; ++i){
        pix1[i] = (struct pixel*)calloc(mx*3, sizeof(uint8_t));
        str=fread(pix1[i], sizeof(struct pixel), mx, in);
        if (str==0){
            clear_pix1();
            return READ_INVALID_BITS;//!!!
        }
        uint32_t ost=mx3-mx*3;
        for (uint32_t jj = 0; jj < ost; jj++) {
            uint8_t tmp=0;
            if (fread(&tmp, sizeof(uint8_t), 1, in)==0){
                clear_pix1();
                return READ_INVALID_BITS;//!!!
            }
        }
    }
    pix2 = (struct pixel**)calloc(mx, sizeof(*pix2));
    for(i = 0; i < mx; ++i)
        pix2[i] = (struct pixel*)calloc(my3, sizeof(uint8_t));
    return READ_OK;
}
