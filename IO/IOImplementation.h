//
// Created by cigan on 15.10.2020.
//

#ifndef PROBLEMSOLVINGARHITECTURE_IOIMPLEMENTATION_H
#define PROBLEMSOLVINGARHITECTURE_IOIMPLEMENTATION_H

#include "IODef.h"

char * AllocMemoryForCircuitPath(int memorySize) {

    return (char *) malloc(memorySize * sizeof(char));
}

char * GetCircuitPathOfMotorcyclesFromFile() {

    FILE * filePointer = fopen(STANDARD_INPUT_FILE_CIRCUIT_PATH, READ_FILE_MODE);
    ValidateFile(filePointer);

    char * circuitPath = AllocMemoryForCircuitPath(STANDARD_LINE_LENGTH);

    fgets(circuitPath, STANDARD_LINE_LENGTH, filePointer);

    fclose(filePointer);

    return circuitPath;
}

struct MotorcycleDataStructure * AllocMemoryForMotorcycles(int memorySize) {

    return (struct MotorcycleDataStructure *) malloc(memorySize * sizeof(struct MotorcycleDataStructure));
}

void SaveBrandInMotorcycleDataStructure(struct MotorcycleDataStructure *Motorcycles, int index, int it,
                                        const char *PointerAtWord) {
    if (index == 1)
        strcpy(Motorcycles[it].Brand, PointerAtWord);
}

void SaveModelInMotorcycleDataStructure(struct MotorcycleDataStructure *Motorcycles, int index, int it,
                                        const char *PointerAtWord) {
    if (index == 2)
        strcpy(Motorcycles[it].Model, PointerAtWord);
}

void SaveCapacityInMotorcycleDataStructure(struct MotorcycleDataStructure *Motorcycles, int index, int it,
                                           const char *PointerAtWord) {
    if (index == 3)
        Motorcycles[it].Capacity = atoi(PointerAtWord);
}

void SaveTypeInMotorcycleDataStructure(struct MotorcycleDataStructure *Motorcycles, int index, int it,
                                       const char *PointerAtWord) {
    if (index == 4)
        strcpy(Motorcycles[it].Type, PointerAtWord);
}

void SaveMaxStraightLineSpeedInMotorcycleDataStructure(struct MotorcycleDataStructure *Motorcycles, int index,
                                                       int it, const char *PointerAtWord) {
    if (index == 5)
        Motorcycles[it].MaxSpeedInStraightLine = atof(PointerAtWord);
}

void SaveMaxCurveSpeedInMotorcycleDataStructure(struct MotorcycleDataStructure *Motorcycles, int index, int it,
                                                const char *PointerAtWord) {
    if (index == 6)
        Motorcycles[it].MaxSpeedInCurve = atof(PointerAtWord);
}

void SaveMotorcycleInDataStructure(struct MotorcycleDataStructure *Motorcycles, int index, int it,
                                   char *PointerAtWord) {
    while (PointerAtWord != NULL) {

        index += 1;

        SaveBrandInMotorcycleDataStructure(Motorcycles, index, it, PointerAtWord);

        SaveModelInMotorcycleDataStructure(Motorcycles, index, it, PointerAtWord);

        SaveCapacityInMotorcycleDataStructure(Motorcycles, index, it, PointerAtWord);

        SaveTypeInMotorcycleDataStructure(Motorcycles, index, it, PointerAtWord);

        SaveMaxStraightLineSpeedInMotorcycleDataStructure(Motorcycles, index, it, PointerAtWord);

        SaveMaxCurveSpeedInMotorcycleDataStructure(Motorcycles, index, it, PointerAtWord);

        PointerAtWord = strtok(NULL, ", ");
    }
}

struct MotorcycleDataStructure * GetMotorcyclesFromFile(int numberOfMotorcycles) {

    assert(numberOfMotorcycles >= 0);

    struct MotorcycleDataStructure * Motorcycles = AllocMemoryForMotorcycles(numberOfMotorcycles);

    FILE * filePointer = fopen(STANDARD_INPUT_FILE_MOTORCYCLES, READ_FILE_MODE);
    ValidateFile(filePointer);

    char lineFromFile[STANDARD_LINE_LENGTH];

    int index = 0;

    for (int it = 0; it < numberOfMotorcycles; ++it) {

        fgets(lineFromFile, sizeof(lineFromFile), filePointer);

        char * PointerAtWord = strtok(lineFromFile, ", ");

        SaveMotorcycleInDataStructure(Motorcycles, index, it, PointerAtWord);

        index = 0;
    }

    fclose(filePointer);

    return Motorcycles;
}

void PutsMotorcycleInConsole(const struct MotorcycleDataStructure *Motorcycles, int it) {

    printf("%s ", Motorcycles[it].Brand);
    printf("%s ", Motorcycles[it].Model);
    printf("%d ", Motorcycles[it].Capacity);
    printf("%s ", Motorcycles[it].Type);
    printf("%f ", Motorcycles[it].MaxSpeedInStraightLine);
    printf("%f ", Motorcycles[it].MaxSpeedInCurve);
}

void OutputMotorcyclesContainer(int numberOfMotorcycles, struct MotorcycleDataStructure * Motorcycles) {

    assert(numberOfMotorcycles >= 0);

    for (int it = 0; it < numberOfMotorcycles; ++it) {

        PutsMotorcycleInConsole(Motorcycles, it);

        INSERT_NEWLINE;
    }
}

void OutputMotorcyclesInBinaryFile(int numberOfMotorcycles, struct MotorcycleDataStructure * Motorcycles) {

    FILE * filePointer = fopen(STANDARD_OUTPUT_BINARY_FILE, WRITE_FILE_BINARY_MODE);
    ValidateFile(filePointer);

    fwrite(Motorcycles, sizeof(struct MotorcycleDataStructure), numberOfMotorcycles, filePointer);

    fseek(filePointer, 0, SEEK_SET);

    fclose(filePointer);
}

#endif //PROBLEMSOLVINGARHITECTURE_IOIMPLEMENTATION_H
