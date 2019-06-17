#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define MAX_STRING 128
#define LENGTH(A) (sizeof(A)/sizeof(A[0]))

typedef char String[MAX_STRING];

typedef enum { mammal, insect, bird, fish, error } AnimalType;

typedef struct {
    String name;
    double size;
    AnimalType type;
} Animal;

void * Malloc(size_t size) {
    void * Memory;
    if((Memory = malloc(size)) == NULL) {
        perror("MEMORY ERROR: Cannot malloc");
        exit(EXIT_FAILURE);
    }
    return Memory;
}

AnimalType checkType(String type) {
    if (!strcmp(type,"mammal")) {
        return mammal;
    }
    if (!strcmp(type,"insect")) {
        return insect;
    }
    if (!strcmp(type,"bird")) {
        return bird;
    }
    if (!strcmp(type,"fish")) {
        return fish;
    }
    return error;
}

void inputData(Animal *arr, int *size) {
    for(;;) {
        Animal newAnimal;
        printf("Enter animal information (\"exit\" to exit)\n");

        String aName;
        printf("What is the name : ");
        scanf("%s", aName);
        if(!strcmp(aName, "exit")) break;
        //newAnimal.name = aName;
        strcpy(newAnimal.name, aName);

        double aSize;
        printf("What is the size : ");
        scanf("%lf", &aSize);
        //if(newAnimal.size == 0) break;
            newAnimal.size = aSize;

        String aType;
        printf("What is the size : ");
        scanf("%lf", &aSize);
        //if(newAnimal.size == 0) break;
        newAnimal.size = aSize;

        String aType;
        printf("What is the type : ");
        scanf("%s", aType);
        //if(!strcmp(aType, "exit")); break;
        newAnimal.type = checkType(aType);

        if((arr = realloc(arr, sizeof(newAnimal)*((*size)+1))) == NULL) {
            printf("MEMORY ERROR: problem reallocating array\n");
            return;
        }

        //printf("Size: %d\n", *size);
        //printf("Arr Size: %d\n", sizeof(arr)/sizeof(arr[0]));
        arr[(*size)-1] = newAnimal;
        (*size)++;
    }
}

char *typeToString(AnimalType type) {
    switch(type) {
        case mammal: return "mammal"; break;
        case insect: return "insect"; break;
        case bird: return "bird"; break;
        case fish: return "fish";
    }
    return "error";
}

void printData(Animal *arr, int size) {
    printf("The following species were found:\n");
    for(int i = 0; i < size-1; i++)
        printf("%s has size %.2lf and is a %s\n", arr[i].name, arr[i].size,
            typeToString(arr[i].type));
}

int main(void) {

    int size = 1;
    Animal *animals = Malloc(sizeof(Animal));

    inputData(animals, &size);
    printData(animals, size);
    free(animals);

    return 0;
}
