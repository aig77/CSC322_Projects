#include <stdio.h>
#include <stdlib.h>

#define ROAD_WIDTH .01
#define ROADKILL_PROB 1.47

    float RooDensity(float roos, float side_length) {
        return roos / (side_length * side_length);
    }

    float RoadSurfaceArea(float length) {
        return length * ROAD_WIDTH;
    }

int main(void) {
    
    float side_length;
    float road_length;
    float roos;

    printf("Enter side of square in km: ");
    scanf("%f", &side_length);
    printf("Enter roads length in km: ");
    scanf("%f", &road_length);
    printf("Enter number of 'roos: ");
    scanf("%f", &roos);

    float answer = RooDensity(roos, side_length) * RoadSurfaceArea(road_length) *    ROADKILL_PROB;
    printf("Expected number of kills is: %.1f\n", answer);

    return (EXIT_SUCCESS);
}
