#include "Libr.h"

enum read_status header_read(FILE* in, struct bmp_header* bmpHeader1) {
    size_t str=fread(bmpHeader1, sizeof(struct bmp_header), 1, in);
    if ((str!=1) || (bmpHeader1->bfType != 'BM') || (bmpHeader1->biBitCount != 24)) {
        fprintf(stderr,"Corrupted file ");
        return READ_INVALID_HEADER;
    }
    return READ_OK;
}//header_read

enum write_status header_write(FILE* file, struct bmp_header bmpHeader){
    size_t st;
    st = fwrite(&bmpHeader, sizeof(bmpHeader), 1, file);
    if (st==1){
        return WRITE_OK;
    }
    return WRITE_ERROR;
}//header_write

struct bmp_header header_bmp_create(const uint64_t w, const uint64_t h){
    struct bmp_header bmpHeader;
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