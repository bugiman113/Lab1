#include "Libr.h"
struct pixel** pix2;
//const char* filename
enum write_status to_bmp(const char* filename ,FILE* file, struct image img){
    int i, j;
    uint32_t t = bmpHeader.biHeight;
    bmpHeader.biHeight=bmpHeader.biWidth;
    bmpHeader.biWidth=t;
    uint32_t my = bmpHeader.biWidth;
    uint32_t mx = bmpHeader.biHeight;
    uint32_t my3 = (3*my+3) & (-4);
    //FILE* file = fopen(filename,"wb");
    if(file == NULL) {
        printf("Error writing to file <%s>!", filename);
        fclose(file);
        return WRITE_ERROR;
    }
    for (i = 0; i < mx; i++) {
        for (j = my-1; j >= 0; j--) {
            fwrite(&pix2[i][j], sizeof(pix2[i][j]), 1, file);
        }
        uint32_t ost=my3-my*3;
        for (uint32_t jj = 0; jj < ost; jj++) {
            uint8_t tmp=0;
            if (fwrite(&tmp, sizeof(uint8_t), 1, file)==0){
                return WRITE_ERROR;
            }
        }
    }
    fclose(file);
    return WRITE_OK;
}
