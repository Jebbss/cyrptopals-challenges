#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "xorCipher.h"

int main()
{
    FILE* file = fopen("singleCharXor.txt", "r");
    char line[256];
    int lineNumber = 1;
    int curLineScore = 0;
    char curbestScoringChar;
    int maxLineScore = 0;
    
    int scoreTable[256];
    createScoreTable(scoreTable);

    while (fgets(line, sizeof(line), file)) {
        curLineScore = 0;
        curLineScore = scoreLine(line, &curbestScoringChar, scoreTable);
        if(curLineScore > maxLineScore){
            maxLineScore = curLineScore;
            printf("High Score %d, with key %c, at line %d\n", maxLineScore, curbestScoringChar, lineNumber);
            printDecipheredLine(curbestScoringChar, line);
        }
        lineNumber++;
    }
    fclose(file);
    return 0;
}
