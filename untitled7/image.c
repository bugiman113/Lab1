#include "Libr.h"
uint32_t account_xy(const uint64_t width, const uint64_t x, const uint64_t y);

struct image image_create(struct image* image, const uint64_t w, const uint64_t h){
    image->width = w;
    image->height = h;
    image->data = (struct pixel*)calloc(w * h, sizeof(struct pixel));
    return *image;
}

void image_destroy(struct image *image){
    if(image->data!=NULL){
        free(image->data);
    }
    image->data=NULL;
}

struct image image_turn(struct image const source, uint32_t my, uint32_t mx) {
    struct image dest;
    uint32_t n1, n2;
    struct pixel p;
    image_create(&dest, my, mx);
    for (uint32_t x = 0; x < mx ; x++) {
        for (uint32_t y = 0; y < my; y++) {
            n1= account_xy(mx, x, y);//для источника
            n2= account_xy(my, my - y - 1, x);//для адресата
            p=source.data[n1];
            dest.data[n2]=p;
        }
    }
    return dest;
}
