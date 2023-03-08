#include"./array.h"
#include"./display.h"

int main() {
    t_int_array a = init_int_array(10, 10);
    t_int_array b = init_int_array(10, 10);
    t_int_array dest = init_int_array(10, 10);

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

    t_float_array d = init_float_array(5, 10);
    display_float_array(d);
    deinit_float_array(d);

    t_uchar_array e = init_uchar_array(10, 10);
    display_uchar_array(e);
    deinit_uchar_array(e);

    return 0;
}
