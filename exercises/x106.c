/* Exercise 1-6
 * Verify that `getchar() != EOF` is 0 or 1.
 */

#include <stdio.h>

main()
{
    printf("%d\n", getchar() != EOF);
}
