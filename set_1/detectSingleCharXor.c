#include <stdio.h>
#include <stdlib.h>
#include "xorCipher.h"

void printDecipheredLine(char key, char* line){
    int lengthOfCiphered = strlen(line);
    
    char* twoChars = malloc(sizeof(char)*3);
    *(twoChars + 2) = '\0'; 
    
    int decipheredChar;

    for(int i = 0; i < lengthOfCiphered; i+=2){
        *twoChars = line[i];
        *(twoChars + 1) = line[i+1];

        decipheredChar = (key ^ strtol(twoChars, NULL, 16));
        printf("%c", decipheredChar);
    }
    printf("\n");
}

int main()
{
    FILE* file = fopen("singleCharXor.txt", "r");
    char line[256];
    int lineNumber = 1;
    int curLineScore = 0;
    char curbestScoringChar;
    char bestScoringChar;
    int maxLineScore = 0;
    int scoreTable[256];
    createScoreTable(scoreTable);

    while (fgets(line, sizeof(line), file)) {
        // printf("%s\n", line);
        curLineScore = 0;
        curLineScore = scoreLine(line, &curbestScoringChar, scoreTable);
        if(curLineScore > maxLineScore){
            maxLineScore = curLineScore;
            bestScoringChar = curbestScoringChar;
            printf("High Score %d, with key %c, at line %d\n", maxLineScore, bestScoringChar, lineNumber);
            printDecipheredLine(bestScoringChar, line);
        }
        lineNumber++;
    }

    fclose(file);

    return 0;
}
