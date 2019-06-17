#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define MAX_STRING 1024
#define STARTING_IDX

typedef char String[MAX_STRING];

void removeEnter(String word) {
    int len = strlen(word);
    if(word[len-1] == '\n')
        word[len-1] = '\0';
}

void removeLastComma(String oldStr, String newStr) {
    if(strlen(oldStr) > 2) {
        for(int i = 0; i < MAX_STRING - 2; i++) {
            if(oldStr[i+2] == '\0') {
                newStr[i] == '\0';
                newStr[i+1] == '\0';
                break;
            } else
                newStr[i] = oldStr[i];
        }
    }
}

int main(void) {

    String input;
    String qualities;
    String theQuality;
    String realOutput;
    int C1;
    FILE *InputQualities;
    FILE *OutputQualities;

    if((InputQualities = fopen("MyQualities.txt", "w")) == NULL) {
        printf("Error opening file for writing");
        return 1;
    }

    printf("Please enter sentences, . to end.\n");
    fgets(input, MAX_STRING, stdin);
    while(strcmp(input, ".\n") && strlen(qualities) < 1024) {
        //printf("Input before remove enter: %s\n", input);
        removeEnter(input);
        //printf("Input after remove enter: %s\n", input);

        //String theQuality;
        if(strstr(input, "I am") && strlen(input) > 4) {
            //printf("1\n");
            strcpy(theQuality, &(input[5]));
            //printf("theQuality: %s\n", theQuality);
            strncat(qualities, theQuality, strlen(theQuality));
            //printf("Qualities: %s\n", qualities);

            // writes theQuality to file (InputQualities)
            // also includes \n char at the end of each line
            if(fputs(theQuality, InputQualities) == EOF ||
                    fputc('\n', InputQualities) == EOF) {
                printf("Error writing to file");
                return 1;
            }

            strncat(qualities, ", ", 2);
        }

        fgets(input, MAX_STRING, stdin);
    }

    fclose(InputQualities);

    // fix qualities string so that last comma is removed and print
    removeLastComma(qualities, realOutput);
    printf("The qualities are %s.\n", realOutput);

    // open reading file (OutputQualities)
    if((OutputQualities = fopen("MyQualities.txt", "r")) == NULL) {
        printf("Error opening file for reading");
        return 1;
    }

    // read output file to print qualities
    printf("Confirming the saved qualities ...\n");
    while((C1 = fgetc(OutputQualities)) != EOF)
        printf("%c", C1);

    fclose(OutputQualities);

    return 0;

}
