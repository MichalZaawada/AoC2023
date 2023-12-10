#include <stdio.h>
#include <string.h>

long int problem1(){

    FILE *fptr;

    fptr = fopen("input.txt", "r");

    char line[200];
    long int result = 0;

    while (fgets(line, 200, fptr)) {
        //printf("%s", line);
        int length = strlen(line);
        for (int i = 0; i < length; i++) {
            if (line[i] >= 48 && line[i] <= 57) {
                //printf("%i \n", (int)line[i] - 48); 
                result += ((int)line[i] - 48)*10; 
                break;
            }
        }
        for (int i = length - 1; i >= 0; i--) {
            if (line[i] >= 48 && line[i] <= 57) {
                //printf("%i \n", (int)line[i] - 48); 
                result += (int)line[i] - 48; 
                break;
            }
        }
    }
    return result;
}

int wordToNumber(char str[]) {
    char numbers[10][10] = {"zero", "one" , "two", "three",
        "four", "five", "six", "seven",
        "eight", "nine"};
    for (int i = 0; i < 10; i++) {
        /* word to number conversion */
        if (strcasecmp(str, numbers[i]) == 0) {
            return i;
        }
    }
    return 0;
}

long int problem2(){

    FILE *fptr;

    fptr = fopen("input.txt", "r");

    char line[200];
    long int result = 0;

    while (fgets(line, 200, fptr)) {
        //printf("%s", line);
        int length = strlen(line);
        for (int i = 0; i < length; i++) {
            if (line[i] >= 48 && line[i] <= 57) {
                //printf("%i \n", (int)line[i] - 48); 
                result += ((int)line[i] - 48)*10; 
                break;
            }
            for (int j = 2; j<5; j++) {
                if (i + j < length) {
                    char word[5] = {};
                    strncpy(word, &line[i], j+1);
                    //printf("%s \n", word);
                    int parseNumber = wordToNumber(word);
                    if (parseNumber != 0) {
                        //printf("%i \n", parseNumber);
                        result += parseNumber*10;
                        i = length;
                        break;
                    }
                }
            }
        }
        for (int i = length-1; i >= 0; i--) {
            if (line[i] >= 48 && line[i] <= 57) {
                //printf("%i \n", (int)line[i] - 48); 
                result += ((int)line[i] - 48); 
                break;
            }
            for (int j = 2; j<5; j++) {
                if (i + j < length) {
                    char word[5] = {};
                    strncpy(word, &line[i], j+1);
                    //printf("%s \n", word);
                    int parseNumber = wordToNumber(word);
                    if (parseNumber != 0) {
                        //printf("%i \n", parseNumber);
                        result += parseNumber;
                        i = -1;
                        break;
                    }
                }
            }
        }



    }
    return result;
}

int main() {

    //long int result1 = problem1();
    //printf("Result of problem1: %li \n", result1);
    long int result2 = problem2();
    printf("Result of problem2: %li \n", result2);
    
    return 0;
}

