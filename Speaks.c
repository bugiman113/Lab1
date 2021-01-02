#include <stdio.h>
const char *read_filename1() {
    static char filename[1001];
    scanf("%1000s", filename);
    return filename;
}

const char *read_filename2() {
    static char filename[1001];
    scanf("%1000s", filename);
    return filename;
}
