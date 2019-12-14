#include <stdio.h>
#include <stdlib.h>
#include "xorCipher.h"

int main(){
    int scoreTable[256];
    createScoreTable(scoreTable);

    char bestScoringChar;
    char* line = "1b37373331363f78151b7f2b783431333d78397828372d363c78373e783a393b3736";

    scoreLine(line, &bestScoringChar, scoreTable);

    printf("%c is the key\n", bestScoringChar);
}