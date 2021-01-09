//
// Created by cigan on 15.10.2020.
//

#ifndef PROBLEMSOLVINGARHITECTURE_TESTINGIMPLEMENTATION_H
#define PROBLEMSOLVINGARHITECTURE_TESTINGIMPLEMENTATION_H

#include "TestingDef.h"

void Test_CountNumberOfMotorcycles_() {

    assert(CountNumberOfMotorcycles() == 7);
}

void Test_CountStraightLinePartsOfCircuitPath_() {

    char * circuitPath = GetCircuitPathOfMotorcyclesFromFile();

    assert(CountStraightLinePartsOfCircuitPath(circuitPath) == 8);
}

void Test_CountCurvePartsOfCircuitPath_() {

    char * circuitPath = GetCircuitPathOfMotorcyclesFromFile();

    assert(CountCurvePartsOfCircuitPath(circuitPath) == 10);
}

#endif //PROBLEMSOLVINGARHITECTURE_TESTINGIMPLEMENTATION_H
