#include "Libr.h"
void checkingFile1(FILE* file,const char* filename){
    if(file == NULL) {
        fprintf(stderr,"File <%s> not found\n", filename);
        fprintf(stderr,"The program is completed(-_-)");
        exit(2);
    }
}
enum read_status checkingFile2(FILE* file,const char* filename,struct image image0) {
    if (file == NULL) {
        fprintf(stderr, "Error writing to file <%s>", filename);
        print_newline();
        fprintf(stderr, "The program is completed(-_-)");
        fclose(file);
        image_destroy(&image0);
        exit(4);
    } else{return READ_OK;}
}
void error_message(int32_t e){
    if (e==1){
        fprintf(stderr,"Error Header in file");
        print_newline();
        fprintf(stderr, "The program is completed(-_-)");
        exit (1);
    }
    if (e==3){
        fprintf(stderr,"Error image in file");
        print_newline();
        fprintf(stderr, "The program is completed(-_-)");
        exit(3);
    }
    if (e==4){
        fprintf(stderr,"Error writing to file ");
        print_newline();
        fprintf(stderr, "The program is completed(-_-)");
        exit(4);
    }
    if(e==5){
        fprintf(stderr,"Error writing to file ");
        print_newline();
        fprintf(stderr, "The program is completed(-_-)");
        exit(5);
    }
}