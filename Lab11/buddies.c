#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define MAX_STRING 128
typedef char String[MAX_STRING];

typedef struct list_node {
    String name;
    struct list_node *next;
    struct list_node *buddy;
} NodeType;

typedef NodeType *Node;

void Free(void ** Memory) {
    free(*Memory);
    *Memory = NULL;
}

void printList(Node head) {
    while(head != NULL) {
        printf("%s's best buddy is %s\n", head->name, head->buddy->name);
        head = head->next;
    }
}

void freeList(Node *head) {
    Node curr;
    while(*head != NULL) {
        curr = *head;
        head = &((*head)->next);
        Free((void **)&curr);
    }
}

Node find(Node head, char *word) {
    while(head != NULL && strcmp(head->name, word))
        head = head->next;
        return head;
}

int main(void) {

    Node head = NULL;
    Node newNode;
    String userInput;
    int size = 0;

    // Create list / set names for each node
    printf("READ DIRECTIONS TO USE PROPERLY\n");
    printf("Enter data, type forward slash (/) when finished inputting names\n");
    printf("Enter person's name: ");
    scanf("%s", userInput);
    //fgets(userInput, sizeof(userInput), stdin);
    //printf("%s", userInput);
    while(strcmp(userInput, "/")) {
        newNode = (Node)malloc(sizeof(NodeType));
        strcpy(newNode->name, userInput);
        newNode->next = head;
        head = newNode;
        size++;
        printf("Enter person's name: ");
        scanf("%s", userInput);

        //fgets(userInput, sizeof(userInput), stdin);
    }

    // Set each person's buddy
    Node curr = head;
    while(curr != NULL) {
        printf("Enter %s's buddy: ", curr->name);
        scanf("%s", userInput);
        Node temp = head;
        curr->buddy = find(temp, userInput);
        curr = curr->next;
    }

    printList(head);
    freeList(&head);

    return 0;
}
