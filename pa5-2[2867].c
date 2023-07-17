/**
 * programming assignment #5
 * Tyler Frisinger , Owen Crone , Gavin Brown
 * 05/11/2023
 *
 *
 *
 *
*/
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>



typedef struct Rec_usage{
        char section[50];
        int capacity;
        double smallLock;       // changed lockers from doubles to integer
        double medLock;
        double largeLock;
        double turf;
        double pool;
        double gym;
        double weight;
       // double smallLockPercent;
} recData;
/*
void myFunction(struct Rec_usage* recptr){ // may not need
     double smallLock = recptr->weight / recptr->smallLock * 100;
     double weight = recptr->weight;
     double medLock = recptr->medLock;
     double gym = recptr->gym;
     double turf = recptr->turf;
     double pool = recptr->pool;
     double largeLock = recptr->largeLock;


    recptr->smallLock = recptr->smallLock;
    recptr->medLock = gym / medLock * 100;
    recptr->largeLock = (pool + turf) / largeLock * 100;

    return;
}
*/
recData calculatePercent(recData rec) {
    int capacity = rec.capacity;
    double largeLock = rec.largeLock;      // changed lockers from doubles to integers
    double medLock = rec.medLock;
    double smallLock = rec.smallLock;
    double turf = rec.turf;
    double pool = rec.pool;
    double gym = rec.gym;
    double weight = rec.weight;

//rec.smallLockPercent = weight / smallLock * 100;

    rec.smallLock = weight / smallLock * 100; // wrong
    rec.medLock = gym / medLock * 100; // wrong
    rec.largeLock = (pool + turf) / largeLock * 100; // wrong           THIS IS THE SECTION WEHRE OUR CALCULATIONS ARE NOT WORKING, WE NEED THESE
    rec.turf = turf / capacity * 100;     //                            CALCULATIONS ON LINES 201, 205, 209. Our expected output should be 20% for
    rec.pool = pool / capacity * 100;//                                 line 201 (small locker), for line 205 we expect 33.33% (medium Lockers),
    rec.gym = gym / capacity * 100;     //                              and for line 209 we expect 97.5% (Large Lockers).
    rec.weight = weight / capacity * 100;

    //rec.smallLockPercent = weight / smallLock * 100;

    return rec;
    }

    double BMR(char Sex, double Height, double Weight, int Age, int Activity) { // extra credit
    double calories;
    double activityMultiplier;
    switch(Activity) {
        case 0:
            activityMultiplier = 1.2;
            break;
        case 1:
            activityMultiplier = 1.375;
            break;
        case 2:
            activityMultiplier = 1.55;
            break;
        case 3:
            activityMultiplier = 1.725;
            break;
        case 4:
            activityMultiplier = 1.9;
            break;
        default:
            activityMultiplier = 1;
    }
    if (Sex == 'f') {
        calories = ((Weight * 10) + (Height * 6.25) - (Age * 5) - 161) * activityMultiplier;
    }
    else {
        calories = ((Weight * 10) + (Height * 6.25) - (Age * 5) + 5) * activityMultiplier;
    }

    return calories;
    }

    double ActivityCalorieBurn(int time, double MET, double weight) {
        int calories;
        calories = (time * MET * weight * 3.5) / 200;
        return calories;
    }
// end extra credit


int main(int argc, char **argv) {

    char userInput;
    int unitMeasurement;
    double userHeight;
    double userWeight;
    char userGender;
    int userAge;
    int userActivity;
    double userBMR;

    if(argc != 2){
        printf("Failure to provide input file\n");
        exit(1);
    }

    char *inputFilename = argv[1];

    FILE *infile = fopen(inputFilename,"r");
    if(infile == NULL){
        printf("Failure to get current Rec center information\n");
        exit(2);
    }

    int numLines = 8; //  have 8 lines in the input text file
    recData tempRec;
    recData *reclist = (recData*)malloc(sizeof(*reclist) * numLines);
    //recData *recptr = (recData*)malloc(sizeof(*recptr) * numLines); // may not need
    char tempBuffer[100];
    int i = 0;

    while (fgets(tempBuffer, sizeof(tempBuffer), infile) != NULL) {
        char *newline = strchr(tempBuffer, '\n');
        if (newline) {
            *newline = '\0';
        }

        char *sectionToken = strtok(tempBuffer, ",");
        strcpy(tempRec.section, sectionToken);
        char *valueToken = strtok(NULL, ",");

        double value = atof(valueToken);
        if (strcmp(tempRec.section, "Capacity") == 0) {
            tempRec.capacity = (int)value;
            tempRec.smallLock = 0;
            tempRec.medLock = 0;
            tempRec.largeLock = 0;
            tempRec.turf = 0;
            tempRec.pool = 0;
            tempRec.gym = 0;
            tempRec.weight = 0;
        } else if (strcmp(tempRec.section, "Small Lockers") == 0) {
            tempRec.smallLock = value;
        } else if (strcmp(tempRec.section, "Medium Lockers") == 0) {
            tempRec.medLock = value;
        } else if (strcmp(tempRec.section, "Large Lockers") == 0) {
            tempRec.largeLock = value;
        } else if (strcmp(tempRec.section, "Turf") == 0) {
            tempRec.turf = value;
        } else if (strcmp(tempRec.section, "Pool") == 0) {
            tempRec.pool = value;
        } else if (strcmp(tempRec.section, "Gym") == 0) {
            tempRec.gym = value;
        } else if (strcmp(tempRec.section, "Weight room") == 0) {
            tempRec.weight = value;
        }
        reclist[i] = tempRec;

        //recptr[i] = tempRec;

        i++;
    }

    fclose(infile);

//myFunction(&*recptr); // may not need

    // Call calculatePercent after all values are read
    for(i = 0; i < numLines; i++){
        reclist[i] = calculatePercent(reclist[i]);
    }

        printf("Welcome to the Campus Rec current facility usage page.\n");

    for(i = 0; i < 1; i++){
        printf("The %s of the campus rec is currently at %d people.\n", reclist[i].section, reclist[i].capacity);
    }

    for(i = 1; i < 2; i++){
        printf("There are %.0lf %s at the campus rec and %.2lf%% are being used at this time.\n",tempRec.smallLock, reclist[i].section, reclist[i].smallLock);
    }

    for(i = 2; i < 3; i++){
        printf("There are %.0lf %s at the campus rec and %.2lf%% are being used at this time.\n",tempRec.medLock, reclist[i].section,reclist[i].medLock);
    }

    for(i = 3; i < 4; i++){
        printf("There are %.0lf %s at the campus rec and %.2lf%% are being used at this time.\n",tempRec.largeLock, reclist[i].section,reclist[i].largeLock);
    } //percentage is not right for the code above ....have to fix in equation somehow

    for(i = 4; i < 5; i++){
        printf("There are %.0lf people at the %s and make up for %.2lf%% of the current capacity.\n",tempRec.turf, reclist[i].section,reclist[i].turf);
    }

    for(i = 5; i < 6; i++){
        printf("There are %.0lf people at the %s and make up for %.2lf%% of the current capacity.\n",tempRec.pool, reclist[i].section,reclist[i].pool);
    }

    for(i = 6; i < 7; i++){
        printf("There are %.0lf people at the %s and make up for %.2lf%% of the current capacity.\n",tempRec.gym, reclist[i].section,reclist[i].gym);
    }

    for(i = 7; i < numLines; i++){

        printf("There are %.0lf people at the %s and make up for %.2lf%% of the current capacity.\n",tempRec.weight, reclist[i].section,reclist[i].weight);
       // printf(" weight number %.2lf\n",reclist[i].weight);
    }

    free(reclist); // free the array

// extra credit portion
    printf("Would you like to use the calorie calulator? (y/n): ");
    scanf("%c", &userInput);
if (userInput == 'y') {
    printf("0: Metric\n1: Imperial\nEnter preferred measurement: ");
    scanf("%d", &unitMeasurement);
    if (unitMeasurement == 1) {
        printf("Enter your Height (Inches): ");
        scanf("%lf", &userHeight);
        userHeight = userHeight * 2.54;
        printf("Enter your Weight (Pounds): ");
        scanf("%lf", &userWeight);
        userWeight = userWeight * 0.453592;
    }
    else {
        printf("Enter your Height (Centimeters): ");
        scanf("%lf", &userHeight);
        printf("Enter your Weight (Kilograms): ");
        scanf("%lf", &userWeight);
    }
    printf("Enter your gender (m/f): ");
    scanf(" %c", &userGender);
    printf("Enter your age (Years): ");
    scanf("%d", &userAge);
    printf("0: Sedentary            (Little to no exercise)\n");
    printf("1: Light Activity       (Light exercise/sports 1-3 days per week)\n");
    printf("2: Moderate Activity    (Moderate exercise/sports 3-5 days per week)\n");
    printf("3: Very Active          (Hard exercise/sports 6-7 days per week)\n");
    printf("4: Extra Active         (Very hard exercise/sports and physical job)\n");
    printf("Enter activity level: ");
    scanf("%d", &userActivity);

    userBMR = BMR(userGender, userHeight, userWeight, userAge, userActivity);

    printf("\nYour Basal Metabolic Rate (BMR) is an estimate of how many calories you burn in a day\n");
    printf("Your BMR is %.0lf calories\n", userBMR);
    printf("\nHere are some ways you can burn calories at the Rec:\n");
    printf("An hour of walking burns %.0lf calories\n", ActivityCalorieBurn(60, 2.5, userWeight));
    printf("An hour of jogging burns %.0lf calories\n", ActivityCalorieBurn(60, 8.0, userWeight));
    printf("An hour of running burns %.0lf calories\n", ActivityCalorieBurn(60, 10.0, userWeight));
    printf("An hour of cycling burns %.0lf calories\n", ActivityCalorieBurn(60, 5.5, userWeight));
    printf("An hour of playing basketball burns %.0lf calories\n", ActivityCalorieBurn(60, 5.0, userWeight));
    printf("An hour of active swimming burns %.0lf calories\n", ActivityCalorieBurn(60, 7.0, userWeight));
    printf("An hour of light weight training burns %.0lf calories\n", ActivityCalorieBurn(60, 3.0, userWeight));
    printf("An hour of vigorous weight training burns %.0lf calories\n", ActivityCalorieBurn(60, 6.0, userWeight));
}


    return 0;
}
