/**
 * programming assignment #4
 * Tyler Frisinger , Owen Crone , Gavin Brown
 * 04/13/2023
 *
 * The goal of this project was too have a user input a file and then we take that file and use a token to find certain pieces of information,
 * we then use that information to calculate the power and then compare the cars in a matrix, we print that information out to the terminal.
 * Then we write different information to a output file that lists each car along with each piece of data such as power at 60,70,80 that we got from the input file.
 *
 *
*/


#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>



typedef struct car_struct {
        char cName[50];
        double drag;
        double aCar;
        double p60;
        double p70;
        double p80;
} carData;


carData calculatePower(carData car) { // fix equation
    double area = car.aCar;
    double drag = car.drag;
    double fluid = 0.44704; // m/s for every 1 mph
    car.p60 = drag * 0.59 * (26.8224*26.8224)* area;
    car.p60 = car.p60 * 26.8224;
    car.p70 = drag * 0.59 * ((70*fluid)*(70*fluid)) * area;
    car.p70 = car.p70 * (70 * fluid);
    car.p80 = drag * 0.59 * ((80 * fluid)*(80 * fluid)) * area;
    car.p80 = car.p80 * (80 * fluid);
    return car;
}

int main(int argc, char **argv) {

    int i;
    char tempBuffer[100];
    carData tempCar;


    if(argc != 3) {
        printf("USAGE: inputFile outputFile\n"); // needs to fulfil the command line requirements
        exit(1);
    }
    char *inputFilename = argv[1];
    char *outputFilename = argv[2];
    printf( "Welcome to the automobile calculator\n");
    printf( "Processing text file [%s]....\n",inputFilename);


    //open input file and quit if it fails
    FILE *infile = fopen(inputFilename, "r");
    if(infile == NULL) {
        printf( "Failure to open file\n");
        exit(2);
    }

    int numLines = 0; // get total number of lines the program is reading
    int numCars = 0; // get number of lines that fit the paramater's
    while(fgets(tempBuffer, sizeof(tempBuffer), infile) != NULL) {
        char *name = strtok(tempBuffer, ",");
        char *drag = strtok(NULL, ",");
        double area = atof(strtok(NULL, ","));
            numLines++;
        if(area > 0) {
            numCars++;
        }
    }
    rewind(infile); // reads file again

    printf("---Completed reading %d lines of data.\n",numLines); // how many lines were read oveall?
    printf( "Computing the power requirements at 60, 70 and 80 mph ...\n");
    printf( "Writing out all automobiles that have a positive drag area to output file [%s] ...\n", outputFilename);
    printf( "---Completed writing %d lines\n", numCars); // number of lines that fit the parameters
    printf( "Computing pair-based comparisons w.r.t. to drag coefficiants and power @ 60 mph ...\n");

    carData *carList = (carData*)malloc(sizeof(carData) * numCars); //alocating memory for array structure carData


    i = 0;
    while (fgets(tempBuffer, sizeof(tempBuffer), infile) != NULL) { // read each line and when it sees a "," it inputs the word or number right before hand and then it redoes it and has everything null before the next token
        // remove the endline character from the line
        tempBuffer[strlen(tempBuffer) - 1] = '\0';
        // tokenize the line, breaking along commas:
        char *nameToken = strtok(tempBuffer, ",");
        strcpy(tempCar.cName, nameToken);
        char *dragToken = strtok(NULL, ",");
        double drag = atof( dragToken);
        char *areaToken = strtok(NULL, ",");
        double aCar = atof(areaToken);
        tempCar.drag = drag;
        tempCar.aCar = aCar;


        if(aCar > 0) { //if the area of the car is greater then 0 (not -1) then calculate the power of the car
            tempCar = calculatePower(tempCar);
            carList[i] = tempCar; //changing structure to an array so I can go through every line of code and every car, drag, area....
            i++;
        }
    }
    fclose(infile); // close the reading file


    for(int i = 0; i < numCars; i++) {
        carData a1 = carList[i];
        for(int j = 0; j < numCars; j++) {
            if(i != j) {
                carData a2 = carList[j];
                if(a1.aCar > a2.aCar && a1.p60 < a2.p60 ) {
                    printf( "--- %s has a larger drag area than %s, but a smaller power requirement.\n", a1.cName, a2.cName);
                }
            }
        }
    }
    printf("Thank you using the system.\n");

    FILE *outputStream = fopen(outputFilename, "w"); // output file / open writing file

    for(int i = 0; i < numCars; i++) {
        fprintf(outputStream, "%s, %.2lf, %.2lf, %.2lf, %.2lf, %.2lf\n", carList[i].cName, carList[i].drag, carList[i].aCar, carList[i].p60, carList[i].p70, carList[i].p80);
    }

    fclose(outputStream); // close writing file / close output file

    return 0;
}