//
// Created by cigan on 15.10.2020.
//

#ifndef PROBLEMSOLVINGARHITECTURE_IODEF_H
#define PROBLEMSOLVINGARHITECTURE_IODEF_H

#include "../DataStructures/DataStructures.h"
#include "../Validations/ValidationsImplementation.h"

char * AllocMemoryForCircuitPath(int memorySize);
char * GetCircuitPathOfMotorcyclesFromFile();

struct MotorcycleDataStructure * AllocMemoryForMotorcycles(int memorySize);

void SaveBrandInMotorcycleDataStructure(struct MotorcycleDataStructure *Motorcycles, int index, int it,
                                        const char *PointerAtWord);

void SaveModelInMotorcycleDataStructure(struct MotorcycleDataStructure *Motorcycles, int index, int it,
                                        const char *PointerAtWord);

void SaveCapacityInMotorcycleDataStructure(struct MotorcycleDataStructure *Motorcycles, int index, int it,
                                           const char *PointerAtWord);

void SaveTypeInMotorcycleDataStructure(struct MotorcycleDataStructure *Motorcycles, int index, int it,
                                       const char *PointerAtWord);

void SaveMaxStraightLineSpeedInMotorcycleDataStructure(struct MotorcycleDataStructure *Motorcycles, int index,
                                                       int it, const char *PointerAtWord);
void SaveMaxCurveSpeedInMotorcycleDataStructure(struct MotorcycleDataStructure *Motorcycles, int index, int it,
                                                const char *PointerAtWord);

void SaveMotorcycleInDataStructure(struct MotorcycleDataStructure *Motorcycles, int index, int it,
                                   char *PointerAtWord);

struct MotorcycleDataStructure * GetMotorcyclesFromFile(int numberOfMotorcycles);

void PutsMotorcycleInConsole(const struct MotorcycleDataStructure *Motorcycles, int it);
void OutputMotorcyclesContainer(int numberOfMotorcycles, struct MotorcycleDataStructure * Motorcycles);

void OutputMotorcyclesInBinaryFile(int numberOfMotorcycles, struct MotorcycleDataStructure * Motorcycles);

#endif //PROBLEMSOLVINGARHITECTURE_IODEF_H
