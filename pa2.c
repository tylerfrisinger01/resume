/**
 * programming assignment #2
 * Tyler Frisinger , Owen Crone , Gavin Brown
 * 03/09/2023
 *
 * our goal is to prompt the user to enter values of the toxic waste concentration levels, we then use this information in the calculator as an
 * exponential decay function to find the R and the K values along with the time it will take to reach the safe toxin level.
 *
*/


#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>


double calcK(double a){ // function for computing k

    return exp(a);
}

double concT(double r, double k, double concLvl){ // function for computing minutes

    double minutes = (1 / r) * log(concLvl / k);

    return minutes;
}

int main(int argc, char **argv) {

int t = 0;
double userInput;
double concLvl;
double m;
double a;
double summationX = 0;
double summationY = 0;
double summationXY = 0;
double summationX2 = 0;
double k;
double r;

    printf("Welcome to our Calculator\n");
    printf("please enter the concentrations for each time, when you are done enter -1!\n");
    scanf("%lf", &userInput); //user prompted for concentration

    while(userInput != -1){ // while loop as long as userInput is not -1
        printf("concentration at time %d min: %.1lf\n",t, userInput); // userInput prompt

            summationX += t; //summation of x

            summationY += log(userInput); // summation of y

            summationXY += (t * log(userInput)); // summatin of ln(y * x)

            summationX2 += (t * t); // summation of x^2

        t = t + 1; // add 1 minute
        scanf("%lf", &userInput); // reprompt user for input


}

    //printf("summationX: %.2lf\n",summationX);
    //printf("summationY: %.2lf\n",summationY);
    //printf("summationXY: %.2lf\n",summationXY);
    //printf("summationX2: %.2lf\n",summationX2);
    // testing to make sure summations work and are accurate

    int n = t; // change t to n in order for it to match equation exactly

m = ((n * summationXY) - (summationX * summationY)) / ((n * summationX2) - pow(summationX,2)); //m

a = (summationY - (m * summationX))/ n; //a

    //printf("print m: %.4lf\n", m);
   // printf("print a: %.4lf\n", a);
   // testing to make sure value m and value a work and are accurate


    printf("Please enter the safe concentration threshold for discharge?\n");
        scanf("%lf", &concLvl);



r = m; // m is the same as r
    printf("The r value of the curve: %.4lf\n",r);


k = calcK(a); // function to calculate k value
    printf("The k value of the curve: %.4lf\n",k);




double minutes = concT(r, k, concLvl); // function to calculate minutes
    printf("Time needed to reach threshold for discharge: %.4lf minutes\n", minutes);


// final print message
printf("Thank you for using our toxic waste calculator!\n");


    return 0;
}