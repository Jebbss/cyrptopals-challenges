#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void convertThreeHexToBase64(char* threeHex, char* base64, int i) {
   char *base64LookUp = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";

   unsigned long convertedHex = strtol(threeHex, NULL, 16);
   unsigned long leftHS = convertedHex >> 6;
   unsigned long rightHS = convertedHex & 0x3f;
   base64[i] = *(base64LookUp + leftHS);
   base64[i+1] = *(base64LookUp + rightHS);
}

char* getThreeCharacters(char* charArray, unsigned int startingPosition){
   char* threeCharacters;
   threeCharacters = malloc(sizeof(char)*3);
   threeCharacters[0] = *(charArray + startingPosition);
   threeCharacters[1] = *(charArray + startingPosition + 1);
   threeCharacters[2] = *(charArray + startingPosition + 2);
   return threeCharacters;
}

char* hexStringToBase64String(char* hexString){
   unsigned long hexStringLength = strlen(hexString);
   char *b;
   char* base64 = malloc(sizeof(char)*hexStringLength);

   int j = 0;
   for(int i = 0; i < hexStringLength; i+=3){
      b = getThreeCharacters(hexString, i);
   
      convertThreeHexToBase64(b, base64, j);
      j += 2;
      free(b);
   }
   
   return base64;
}

int main () {
   char* b64String;
   
   b64String = hexStringToBase64String("f6d");
   printf("%s\n", b64String);
   free(b64String);

   b64String = hexStringToBase64String("6f6f6d");
   printf("%s\n", b64String);
   free(b64String);

   b64String = hexStringToBase64String("49276d206b696c6c696e6720796f757220627261696e206c696b65206120706f69736f6e6f7573206d757368726f6f6d");
   printf("%s\n", b64String);
   free(b64String);
}
