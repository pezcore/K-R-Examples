#include <stdio.h>


main(){
    int a[3];       /* declare array of 3 ints */
    a[5] = 10;      /* set 6th element of that array to 10 */
    printf("%d\n", a[5]); /* print */

    /* Why is no complaint made about the fact that I accessed an array
     * element that is out of bounds? In lines 6 & 7 I access the sixth
     * element of array a, a[5] for write and read respectively */
}
