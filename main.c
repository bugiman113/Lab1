#include "Libr.h"

int main(){
    const char* filename;
    printf("Write the input name of the source file, for example: C:\\Ci\\1.bmp ");
    print_newline();
    filename = read_filename1();
    FILE* file= fopen(filename,"rb");
    if(file == NULL) {
        printf("File <%s> not found", filename);
        print_newline();
        printf("The program is completed(-_-)");
        return 2;
    }
    bmpHeader1 = (struct bmp_header*)calloc(1, sizeof(struct bmp_header));
    enum read_status rs=read_header(file);
    if (rs==READ_OK){
        //rotate();
        uint64_t width = bmpHeader1->biWidth;
        uint64_t height = bmpHeader1->biHeight;
        create_img(&image0, height, width);
        rs=from_bmp1(file, image0);
        fclose(file);
        free(bmpHeader1);
        if (rs==READ_OK){
            printf("Specify the directory where the image will be saved:C:\\Ci\\2.bmp");
            print_newline();
            filename = read_filename2();
            fopen_s(&file,filename,"wb");
            if(file == NULL) {
                printf("Error writing to file <%s>", filename);
                print_newline();
                printf("The program is completed(-_-)");
                fclose(file);
                destroy_img(&image0);
                return WRITE_ERROR;
            }
            create_img(&image1, width, height);
            image1=rotate1(image0);
            destroy_img(&image0);
            create_bmp_header(width, height);
            check_Header();
            check_pix(image1.data[0]);
            enum write_status ws = write_header(file);
            if (ws==WRITE_OK){
                ws = to_bmp1(filename,file, image1);
                destroy_img(&image1);
                fclose(file);
                if (ws==WRITE_OK){
                    printf("The file <%s> was created successfully", filename);
                    return 0;
                }
                printf("Error writing to file <%s>", filename);
                print_newline();
                printf("The program is completed(-_-)");
                return 5;
            }
            destroy_img(&image1);
            printf("Error writing to file <%s>", filename);
            print_newline();
            printf("The program is completed(-_-)");
            return 4;
        }
        printf("Error image in file <%s>", filename);
        print_newline();
        printf("The program is completed(-_-)");
        destroy_img(&image0);
        return 3;
    }
    printf("Error Header in file <%s>", filename);
    print_newline();
    printf("The program is completed(-_-)");
    fclose(file);
    return 1;
}


