#include <stdio.h>
const char *read_filename1() {
    //return "C:\\Ci\\1.bmp";
    static char filename[1001];
    scanf("%1000s", filename);
    return filename;
}

const char *read_filename2() {
    //return "C:\\Ci\\2.bmp";
    static char filename[1001];
    scanf("%1000s", filename);
    return filename;
}
