#include <stdio.h>
#include <accctrl.h>
#include "Libr.h"

const char* read_filename1(int k) {
    if(k==1){
        printf("Write the input name of the source file, for example: C:\\Ci\\1.bmp ");
        print_newline();}
    if(k==2){
        printf("Specify the directory where the image will be saved:C:\\Ci\\2.bmp");
        print_newline();}
     char* name;
    name = (char*)calloc(1,sizeof (char)*1001);
    scanf("%1000s",name);
    return name;
    }

