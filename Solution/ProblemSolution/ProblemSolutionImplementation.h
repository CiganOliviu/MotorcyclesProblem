//
// Created by cigan on 15.10.2020.
//

#ifndef PROBLEMSOLVINGARHITECTURE_PROBLEMSOLUTIONIMPLEMENTATION_H
#define PROBLEMSOLVINGARHITECTURE_PROBLEMSOLUTIONIMPLEMENTATION_H

#include "ProblemSolutionDef.h"

int CountNumberOfMotorcycles() {

    FILE * filePointer = fopen(STANDARD_INPUT_FILE_MOTORCYCLES, READ_FILE_MODE);

    char lineFromFile[STANDARD_LINE_LENGTH];

    int numberOfMotorcycles = 0;

    while ( fgets(lineFromFile, sizeof(lineFromFile), filePointer))
        numberOfMotorcycles += 1;

    fclose(filePointer);

    return numberOfMotorcycles;
}

int CountStraightLinePartsOfCircuitPath(char * circuitPath) {

    int result = 0;

    for (int it = 0; it < strlen(circuitPath); ++it)
        if (circuitPath[it] == '_')
            result += 1;

    return result;
}

int CountCurvePartsOfCircuitPath(char * circuitPath) {

    int result = 0;

    for (int it = 0; it < strlen(circuitPath); ++it)
        if (circuitPath[it] == 's')
            result += 1;

    return result;
}

float GetAverageSpeedOfMotorcycle(struct MotorcycleDataStructure Motorcycle) {

    char * circuitPath = GetCircuitPathOfMotorcyclesFromFile();
    int numberOfStraightLineParts = CountStraightLinePartsOfCircuitPath(circuitPath);
    int numberOfCurveLineParts = CountCurvePartsOfCircuitPath(circuitPath);

    float result = numberOfStraightLineParts * Motorcycle.MaxSpeedInStraightLine + numberOfCurveLineParts * Motorcycle.MaxSpeedInCurve;

    return result;
}

void SwapPlacesOfMotorcycles(struct MotorcycleDataStructure * FirstMotorcycle, struct MotorcycleDataStructure * SecondMotorcycle) {

    struct MotorcycleDataStructure * AuxPlaceOfMotorcycle = AllocMemoryForMotorcycles(STANDARD_SIZE);

    * AuxPlaceOfMotorcycle = * FirstMotorcycle;
    * FirstMotorcycle = * SecondMotorcycle;
    * SecondMotorcycle = * AuxPlaceOfMotorcycle;
}

void GetMotorcyclesPositionInTable(int numberOfMotorcycles, struct MotorcycleDataStructure * Motorcycles) {

    for (int it = 0; it < numberOfMotorcycles; ++it)
        for (int jit = it; jit < numberOfMotorcycles; ++jit)
            if (GetAverageSpeedOfMotorcycle(Motorcycles[it]) < GetAverageSpeedOfMotorcycle(Motorcycles[jit]))
                SwapPlacesOfMotorcycles(&Motorcycles[it], &Motorcycles[jit]);
}

#endif //PROBLEMSOLVINGARHITECTURE_PROBLEMSOLUTIONIMPLEMENTATION_H
