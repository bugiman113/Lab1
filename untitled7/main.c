#include "Libr.h"

int main(){
    const char* filename;
    int32_t int32;
    int32_t e;
    struct image image0, image1;
    struct bmp_header bmpHeader;
    struct bmp_header* bmpHeader1;
    filename = read_filename1(1);
    FILE* file= fopen(filename,"rb");
    int32=checkingFile1(file,filename);
    if (int32==2){return 2;} //checkingFile
    bmpHeader1 = (struct bmp_header*)calloc(1, sizeof(struct bmp_header));
    enum read_status rs=read_header(file,bmpHeader1);
    if (rs==READ_OK){
        uint64_t width = bmpHeader1->biWidth;
        uint64_t height = bmpHeader1->biHeight;
        create_img(&image0, height, width);
        rs=from_bmp1(file, &image0,bmpHeader1);
        fclose(file);
        if (rs==READ_OK){
            filename = read_filename1(2);
            fopen(filename,"wb");
            rs = checkingFile2(file,filename,image0);//checkingFile
            if (rs==READ_OK){
                create_img(&image1, width, height);
                image1=rotate1(image0);
                destroy_img(&image0);
                bmpHeader = create_bmp_header(width, height,bmpHeader);
            }
            enum write_status ws = write_header(file,bmpHeader);
            if (ws==WRITE_OK){
                ws = to_bmp1(filename,file, image1,width,height);
                destroy_img(&image1);
                fclose(file);
                if (ws==WRITE_OK){
                    printf("The file <%s> was created successfully", filename);
                    return 0;
                } else e=5;
            } else e = 4;
        } else e=3;
    } else e=1;
    error(file,filename,image0,image1,e); //program termination with an error
}