#include <stdlib.h>
#include <stdio.h>

#define FT_PER_ATMOS 33.0
#define MAXIMAL_PART_P 1.4
#define CONT_MAXIMAL_PART_P 1.6

float calcAmbientPressure(int depth) {
    return (depth / FT_PER_ATMOS) + 1;
}

float calcPartialPressure(int percO2, float ambPressure) {
    return ((float)percO2 / 100.0) * ambPressure;
}

char calcOPressureGroup(float partPressure) {
    int buffer = (int)(partPressure * 10);
    return 'A' + buffer;
}

int main(void) {
    int depth, percO2;
    printf("\nEnter depth and percentage O2: ");
    scanf("%d %d", &depth, &percO2);

    float ambPressure = calcAmbientPressure (depth);
    float partPressure = calcPartialPressure(percO2, ambPressure);
    char group = calcOPressureGroup(partPressure);
    printf("\nAmbient pressure: %.1f \n", ambPressure);
    printf("O2 Pressure: %.2f \n", partPressure);
    printf("O2 Group: %c \n", group);

    printf("\nExceeds maximal O2 pressure: ");
    printf(partPressure > MAXIMAL_PART_P ? "true\n" : "false\n");
    printf("Exceeds contingency O2 pressure: ");
    printf(partPressure > CONT_MAXIMAL_PART_P ? "true\n\n" : "false\n\n");

    return (EXIT_SUCCESS);
}
