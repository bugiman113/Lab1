#include <stdio.h>
#include "Libr.h"

const char* read_filename1(char* str){
    char *name;
    printf("Write the input name of the source file, for example: C:\\Ci\\1.bmp ");
    print_newline();
    fgets( str, 1000, stdin );
    int32_t i = strlen(str)-1;
    if(str[i]=='\n') str[i] = '\0';
    name=str;
    fflush(stdin);
    return name;
}

const char* read_filename2(char* str){
    char *name;
    printf("Specify the directory where the image will be saved:C:\\Ci\\2.bmp");
    print_newline();
    fgets( str, 1000, stdin );
    int32_t i = strlen(str)-1;
    if(str[i]=='\n') str[i] = '\0';
    name=str;
    fflush(stdin);
    return name;
}

