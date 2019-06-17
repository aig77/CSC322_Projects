#include <stdio.h>
#include <stdlib.h>

#define ODD(X) ((X) & 01)
#define BITON(X,N) ((X >> N) & 1)
#define NUM(A,B) (((1 << (B+1)) - 1) ^ ((1 << A) - 1))
#define ALLON(X,S,E) (NUM(S,E) == (X & NUM(S,E)) ? 1 : 0)

int main(void) {

 unsigned int U1,BitNumber,Start,End;

 printf("Enter an integer : ");
 scanf("%ud",&U1);
 printf("%u is %s\n",U1,ODD(U1)?"odd":"even");

 printf("Enter an integer and a bit number : ");
 scanf("%u %d",&U1,&BitNumber);
 printf("%u has bit %d %s\n",U1,BitNumber,BITON(U1,BitNumber)?"on":"off");

 printf("Enter an integer, start and end bit numbers : ");
 scanf("%u %u %u",&U1,&Start,&End);
 printf("%u has %s those bits on\n",U1,ALLON(U1,Start,End)?"all":"not all");

 return(EXIT_SUCCESS);
}
