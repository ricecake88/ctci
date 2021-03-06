// CompressString1.5.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <string>
using namespace std;

#define TRUE 1
#define FALSE 0

void compressString(char * str, int length, char ** strOut) {

  int count = 1;
  int j, i, indexNewString = 0;
  int hasRepeats = FALSE;
  char * tempStr = (char *)malloc(sizeof(char)*length);
  printf("length: %d\n", length);
  for (i = 0; i < length; i++) {
    j = i;
    while (j < length) {
      if (tolower(str[i]) == tolower(str[j+1])) {
        count++;
        j++;
      } else {
        // next character no longer matches
        if (count > 1) {
          tempStr[indexNewString] = str[i];
          tempStr[indexNewString+1] = count + '0';
          i += count - 1; // continue search from next character
          indexNewString+=2;
          hasRepeats = TRUE;
          count = 1;
        } else {
          tempStr[indexNewString] = str[i];
          indexNewString++;
        }
        break;
      }
    }
  }

  tempStr[indexNewString] = '\0';
  if (!hasRepeats) *strOut = (char *)str;
  else *strOut = (char *)tempStr;
}

int main()
{
  char stringOne[] = "aabbcc";
  char stringTwo[] = "abc";
  int stringLengthOne = strlen(stringOne);
  int stringLengthTwo = strlen(stringTwo);
  char stringThree[] = "tessstiiing";
  int stringLength = strlen(stringThree);
  
 
  char * stringOutput;
  compressString(stringOne, stringLengthOne, &stringOutput);
  printf("Compressed String: %s\n", stringOutput);
  compressString(stringTwo, stringLengthTwo, &stringOutput);
  printf("Compressed String: %s\n", stringOutput);
  compressString(stringThree, stringLength, &stringOutput);
  printf("Compressed String: %s\n", stringOutput);
    return 0;
}

