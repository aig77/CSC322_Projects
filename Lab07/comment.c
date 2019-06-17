#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

#define STRING_LENGTH 1000

typedef char String[STRING_LENGTH];

int main(void) {

    char curr;
    char prev;
    int idx = 0;
    bool inString = false;
    bool maybeCommentStart = false;
    bool maybeCommentEnd = false;
    bool inComment = false;
    String result;

 while((curr = getchar()) != EOF) {
    // prev char in valid comment is * but curr isnt /
    if(!inString && inComment && maybeCommentEnd && curr != '/') {
        result[idx++] = prev;

    }
    switch(curr) {
        case '/':
        // check if comment start
        if(!inString && !inComment) {
            maybeCommentStart = true;
        }
        // validify end comment
        else if(!inString && inComment && maybeCommentEnd) {
            inComment = false;
            maybeCommentEnd = false;
            // \n after end of comment to look a bit better
            result[idx++] = '\n';
        }
        // check if its a lone /
        else if(!inString && inComment && !maybeCommentEnd)
            result[idx++] = curr;

        break;

        case '*':
            // validify comment start
            if(!inString && !inComment && maybeCommentStart) {
                inComment = true;
                maybeCommentStart = false;
            }
            // check if comment end
            else if(!inString && inComment && !maybeCommentEnd) {
                maybeCommentEnd = true;
                prev = curr;
            }

            break;
        case '\"':
            if(!inComment && !inString)
                inString = true;
            else if(!inComment && inString)
                inString = false;
            else if(inComment)
                result[idx++] = curr;
            break;

        default:
            if(inComment)
                result[idx++] = curr;
        }
        //printf("%c ", curr);
    }

    printf("%s\n", result);
    return 0;

}
