#include "Libr.h"
uint32_t account_xy(const uint64_t width, const uint64_t x, const uint64_t y){
    return width*y+x;
}

void print_newline(){
    printf("\n");
}