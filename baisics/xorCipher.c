#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void createScoreTable(int* scoreTable){
    scoreTable['E'] = 26;
    scoreTable['e'] = 26;

    scoreTable['T'] = 25;
    scoreTable['t'] = 25;

    scoreTable['A'] = 24;
    scoreTable['a'] = 24;

    scoreTable['O'] = 23;
    scoreTable['o'] = 23;

    scoreTable['I'] = 22;
    scoreTable['i'] = 22;

    scoreTable['N'] = 21;
    scoreTable['n'] = 21;

    scoreTable['S'] = 20;
    scoreTable['s'] = 20;
    
    scoreTable['H'] = 19;
    scoreTable['h'] = 19;    
    
    scoreTable['R'] = 18;
    scoreTable['r'] = 18;

    scoreTable['D'] = 17;
    scoreTable['d'] = 17;

    scoreTable['L'] = 16;
    scoreTable['l'] = 16;

    scoreTable['U'] = 15;
    scoreTable['u'] = 15;

    scoreTable['W'] = 14;
    scoreTable['w'] = 14;

    scoreTable['M'] = 13;
    scoreTable['m'] = 13;

    scoreTable['F'] = 12;
    scoreTable['f'] = 12;

    scoreTable['C'] = 11;
    scoreTable['c'] = 11;

    scoreTable['G'] = 10;
    scoreTable['g'] = 10;

    scoreTable['Y'] = 9;
    scoreTable['y'] = 9;

    scoreTable['P'] = 8;
    scoreTable['p'] = 8;

    scoreTable['B'] = 7;
    scoreTable['b'] = 7;

    scoreTable['K'] = 6;
    scoreTable['k'] = 6;

    scoreTable['V'] = 5;
    scoreTable['v'] = 5;

    scoreTable['J'] = 4;
    scoreTable['j'] = 4;

    scoreTable['X'] = 3;
    scoreTable['x'] = 3;

    scoreTable['Q'] = 2;
    scoreTable['q'] = 2;

    scoreTable['Z'] = 1;
    scoreTable['z'] = 1;
}

int scoreCipherKey(char key, char* ciphered, int* scoreTable){
    int score = 0;
    int lengthOfCiphered = strlen(ciphered);
    
    char* twoChars = malloc(sizeof(char)*3);
    *(twoChars + 2) = '\0'; 
    
    char decipheredChar;

    for(int i = 0; i < lengthOfCiphered; i+=2){
        *twoChars = ciphered[i];
        *(twoChars + 1) = ciphered[i+1];

        decipheredChar = (key ^ strtol(twoChars, NULL, 16));
  
        if(decipheredChar > 0 && decipheredChar < 127){
            return 0;
        }

        score += scoreTable[decipheredChar];
    }
    return score;
}

int main(){
    int ret = 0;
    int max = 0;
    char maxChar = 88;
    int scoreTable[127];
    createScoreTable(scoreTable);

    for(int i = 0; i < 128; i++){
        ret = 0;
        ret = scoreCipherKey(i, "1b37373331363f78151b7f2b783431333d78397828372d363c78373e783a393b3736", scoreTable);
        if (ret > max){
            printf("%d\n", ret);
            max = ret;
            maxChar = i;
        }
    }
    printf("%c is the key\n", maxChar);
}