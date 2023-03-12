#include"./array.h"
#include"./display.h"

int main() {
    int_array_t a = init_int_array(10, 10);
    int_array_t b = init_int_array(10, 10);
    int_array_t dest = init_int_array(10, 10);

    a.array[0][4] = 1;
    b.array[6][8] = 727;

    int ret = add_int_array(a, b, dest);
    if(ret != 0) {
        return -1;
    }

    display_int_array(dest);
    deinit_int_array(a);
    deinit_int_array(b);
    deinit_int_array(dest);

    float_array_t d = init_float_array(5, 10);
    display_float_array(d);
    deinit_float_array(d);

    uchar_array_t e = init_uchar_array(10, 10);
    display_uchar_array(e);
    deinit_uchar_array(e);

    return 0;
}
