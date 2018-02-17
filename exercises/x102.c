/* Exercise 1-2
 * Experiment to find out what happens when `printf`'s argument string contains
 * `\c` where `c` is some other character not listed above
 */

#include <stdio.h>

main()
{
    printf("\i");
    /* answer: compiler warns "unknown escape sequence: '\i'" but successfully
     * compiles. program just prints the "I"
     */
}
