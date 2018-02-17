/* Exercise 1-5
 * Modify the temperature conversion proram to print the table in reverse
 * order, that is from 300 degrees to 0.
 */

#include <stdio.h>

main()
{
    int fahr, celsius;
    int lower, upper, step;

    lower = 0;      /* lower limit of temperature scale */
    upper = 300;    /* upper limit */
    step = 20;      /* step size */

    fahr = upper;
    printf("Fahrenheit Celsius\n==================\n");
    while (fahr >= lower)
    {
        celsius = 5 * (fahr - 32) / 9;
        printf("%10i %7i\n", fahr, celsius);
        fahr -= step;
    }
}
