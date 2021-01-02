#include "Libr.h"

void create_img(struct image *image, const uint64_t w, const uint64_t h){
    image->width = w;
    image->height = h;
    image->data = (struct pixel*)calloc(w * h, sizeof(struct pixel));
}
void destroy_img(struct image *image){
    if(image->data!=NULL){
        free(image->data);
    }
    image->data=NULL;
}
/* создаёт копию изображения, которая повёрнута на 90 градусов */
struct image rotate1(struct image const source) {
    struct image dest;
    uint32_t my=source.width;
    uint32_t mx=source.height;
    uint32_t x;
    uint32_t y;
    uint32_t n1, n2;
    struct pixel p;
    create_img(&dest, my, mx);
    for (x = 0; x < mx ; x++) {
        for (y = 0; y < my; y++) {
            n1=numb_by_xy(mx, x, y);//для источника
            n2=numb_by_xy(my, my-y-1, x);//для адресата
            p=source.data[n1];
            dest.data[n2]=p;
        }
    }
    return dest;
}
