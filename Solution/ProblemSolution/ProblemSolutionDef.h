//
// Created by cigan on 15.10.2020.
//

#ifndef PROBLEMSOLVINGARHITECTURE_PROBLEMSOLUTIONDEF_H
#define PROBLEMSOLVINGARHITECTURE_PROBLEMSOLUTIONDEF_H

#include "../Validations/ValidationsImplementation.h"
#include "../DataStructures/DataStructures.h"
#include "../IO/IOImplementation.h"

int CountNumberOfMotorcycles();
int CountStraightLinePartsOfCircuitPath(char * circuitPath);
int CountCurvePartsOfCircuitPath(char * circuitPath);

float GetAverageSpeedOfMotorcycle(struct MotorcycleDataStructure Motorcycle);

void GetMotorcyclesPositionInTable(int numberOfMotorcycles, struct MotorcycleDataStructure * Motorcycles);

#endif //PROBLEMSOLVINGARHITECTURE_PROBLEMSOLUTIONDEF_H
