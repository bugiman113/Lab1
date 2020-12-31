#include "Libr.h"
const char *read_filename1();
const char *read_filename2();
enum read_status from_bmp( FILE* in);
enum write_status to_bmp ( const char* filename);
void rotate();

int main(){
    const char* filename;
    printf("Input filename-source: \n");
    filename = read_filename1();
    FILE* file= fopen(filename,"rb");
    if(file == NULL) {
        printf("File <%s> not found!", filename);
        return 2;
    }
    enum read_status rs=from_bmp(file);
    if (rs==READ_OK){
        rotate();
        clear_pix1();
        printf("Input filename-destination: \n");
        filename = read_filename2();
        enum write_status ws=to_bmp(filename);
        clear_pix2();
        if (ws==WRITE_OK){
            printf("The file <%s> was created successfully", filename);
            return 0;
        }
        return 4;
    }
    return 1;
}