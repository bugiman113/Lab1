#include "Libr.h"

int main(){
    const char* filename;
    struct image image0, image1;
    char str[1001];
    struct bmp_header bmpHeader;
    struct bmp_header* bmpHeader1;

    /* open file and checking an open file */
    filename = read_filename1(str);
    FILE* file= fopen(filename,"rb");
    checkingFile1(file,filename); // �஢�ઠ 䠩��,checkingFile
    bmpHeader1 = (struct bmp_header*)calloc(1, sizeof(struct bmp_header));
    enum read_status rs= header_read(file, bmpHeader1);
    if (rs!=READ_OK){error_message(1);fclose(file);}

    /* reading the image */
    uint64_t width = bmpHeader1->biWidth;
    uint64_t height = bmpHeader1->biHeight;
    image_create(&image0, height, width);
    rs= bmp_read(file, &image0, bmpHeader1);
    free(bmpHeader1);
    fclose(file);
    if (rs!=READ_OK){image_destroy(&image0);error_message(3);}

    /* image changes */
    filename = read_filename2(str);
    fopen(filename,"wb");
    checkingFile2(file,filename,image0);//checkingFile
    image_create(&image1, width, height);
    image1= image_turn(image0, width, height);
    image_destroy(&image0);
    bmpHeader = header_bmp_create(width, height);

    /* saving a new image */
    enum write_status ws = header_write(file, bmpHeader);
    if (ws!=WRITE_OK){image_destroy(&image1);error_message(4);}
    ws = bmp_create(file, image1, width, height);
    image_destroy(&image1);
    fclose(file);
    if (ws==WRITE_OK){
    printf("The file was created successfully");
     return 0;
     } else error_message(5);//program termination with an error
    }