#include "Libr.h"
int checkingFile1(FILE* file,const char* filename){
    if(file == NULL) {
        printf("File <%s> not found", filename);
        print_newline();
        printf("The program is completed(-_-)");
        return 2;
    }
    return 1;
}
enum read_status checkingFile2(FILE* file,const char* filename,struct image image0) {
    if (file == NULL) {
        printf("Error writing to file <%s>", filename);
        print_newline();
        printf("The program is completed(-_-)");
        fclose(file);
        destroy_img(&image0);
        return FILE_NOT_FOUND;
    } else{return READ_OK;}
}
void error(FILE* file,const char* filename,struct image image0,struct image image1,int32_t e){
    if (e==1){
        printf("Error Header in file <%s>", filename);
        print_newline();
        printf("The program is completed(-_-)");
        fclose(file);
        exit (1);
    }
    if (e==3){
        printf("Error image in file <%s>", filename);
        print_newline();
        printf("The program is completed(-_-)");
        destroy_img(&image0);
        exit(3);
    }
    if (e==4){
        destroy_img(&image1);
        printf("Error writing to file <%s>", filename);
        print_newline();
        printf("The program is completed(-_-)");
        exit(4);
    }
    if(e==5){
        printf("Error writing to file <%s>", filename);
        print_newline();
        printf("The program is completed(-_-)");
        exit(5);
    }
}