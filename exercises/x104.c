/* Exercise 1-4
 * Write a program to print the corresponding Celsius to Fahrenheit table.
 */

#include <stdio.h>

/* print Fahrenheit-Celsius table for fahr = 0, 20, ..., 300 */
main()
{
    float fahr, celsius;
    int lower, upper, step;

    lower = 0;      /* lower limit of temperature table */
    upper = 300;    /* upper limit */
    step = 20;      /* step size */

    celsius = lower;
    printf("Celsius\tFahrenheit\n==================\n");
    while (celsius <= upper)
    {
        /* celsius = (5.0/9.0) * (fahr-32); */
        fahr = (9.0/5.0) * celsius + 32;
        printf("%7.0f %10.1f\n", celsius, fahr);
        celsius += step;
    }
}
