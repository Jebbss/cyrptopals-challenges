#include <stdio.h>
#include <stdlib.h>
#include "xorCipher.h"

int main(){
    int ret = 0;
    int max = 0;
    char maxChar = 0;
    int scoreTable[127];
    createScoreTable(scoreTable);

    for(int i = 0; i < 127; i++){
        ret = 0;
        ret = scoreCipherKey(i, "1b37373331363f78151b7f2b783431333d78397828372d363c78373e783a393b3736", scoreTable);
  
        if (ret > max){
            max = ret;
            maxChar = i;
        }
    }
    printf("%c is the key\n", maxChar);
}