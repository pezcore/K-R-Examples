/* Exercise 1-15
 * Rewrite the temperature conversion program of Section 1.2 to use a function
 * for conversion.
 */

#include <stdio.h>

double fahr2cels(double fahr);

main()
{
   double fahr, celsius;
   
   int lower, upper, step;
   lower = 0;      /* lower limit of temperatuire scale */
   upper = 300;    /* upper limit */
   step = 20;      /* step size */
   
   for (fahr = lower; fahr <= upper; fahr += step)
   {
       celsius = fahr2cels(fahr);
       printf("%3.0f %6.1f\n", fahr, celsius);
   }
}

double fahr2cels(double fahr){
    return (5.0/9.0) * (fahr-32.0);
}
