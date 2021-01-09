#include "IO/IOImplementation.h"
#include "Testing/TestingImplementation.h"

void RunTests() {

    Test_CountNumberOfMotorcycles_();
    Test_CountStraightLinePartsOfCircuitPath_();
    Test_CountCurvePartsOfCircuitPath_();
}

int main() {

    int numberOfMotorcycles = CountNumberOfMotorcycles();
    struct MotorcycleDataStructure * Motorcycles = GetMotorcyclesFromFile(numberOfMotorcycles);

    OutputMotorcyclesContainer(numberOfMotorcycles, Motorcycles);

    GetMotorcyclesPositionInTable(numberOfMotorcycles, Motorcycles);

    INSERT_NEWLINE;

    OutputMotorcyclesContainer(numberOfMotorcycles, Motorcycles);

    OutputMotorcyclesInBinaryFile(numberOfMotorcycles, Motorcycles);

    return 0;
}
