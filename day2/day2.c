#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Dices {
    int greenDices;
    int redDices;
    int blueDices;
};

int countDices(char *str) {
    char turn[100]; 
    size_t pointer = 0, strLen = strlen(str);
    struct Dices dices = {0,0,0};
    int isPossible = 0;
    while (pointer < strLen) {
        int n = strcspn(&str[pointer], ",");
        strncpy(turn, &str[pointer], n);
        turn[n] = '\0';
        //printf("%s\n", turn);
        int m = strcspn(&turn[1], " ");
        char countStr[5] = {""};
        strncpy(countStr,&turn[1],m);
        int count = atoi(countStr);
        m++;
        int colorLen = strlen(turn) - m - 1;
        //printf("%i\n", colorLen);
        switch (colorLen) {
            case 3:
                dices.redDices += count;
                break;
            case 4:
                dices.blueDices += count;
                break;
            case 5:
                dices.greenDices += count;
                break;
            default:
                printf("We got problem!!!");
                break;
        }
        pointer += n+1;
    }
    if (dices.redDices <= 12 && dices.greenDices <= 13 && dices.blueDices <= 14) {
        isPossible++; 
    }

    return isPossible;
}

int max(int a, int b) {
    return (a >= b) ? a : b;
}

struct Dices minimumDiceCount(char *str, struct Dices dices) {
    char turn[100]; 
    size_t pointer = 0, strLen = strlen(str);
    while (pointer < strLen) {
        int n = strcspn(&str[pointer], ",");
        strncpy(turn, &str[pointer], n);
        turn[n] = '\0';
        //printf("%s\n", turn);
        int m = strcspn(&turn[1], " ");
        char countStr[5] = {""};
        strncpy(countStr,&turn[1],m);
        int count = atoi(countStr);
        m++;
        int colorLen = strlen(turn) - m - 1;
        //printf("%i\n", colorLen);
        switch (colorLen) {
            case 3:
                dices.redDices = max(dices.redDices, count);
                break;
            case 4:
                dices.blueDices = max(dices.blueDices, count);
                break;
            case 5:
                dices.greenDices = max(dices.greenDices, count);
                break;
            default:
                printf("We got problem!!!");
                break;
        }
        pointer += n+1;
    }

    return dices;
}


void problem2() {
    FILE *fptr;

    fptr = fopen("input1.txt", "r");

    char line[300], *pch;
    int result = 0;

    while (fgets(line, 300, fptr)) {
        struct Dices dices = {0, 0, 0};
        int numberOfGame = 0;
        pch = strtok(line,":");
        numberOfGame = atoi(&pch[5]);
        printf("Game: %i\n", numberOfGame);

        while ((pch = strtok(NULL, ";\n")) != NULL) {
            dices = minimumDiceCount(pch, dices);
        }
        printf("Min dices count: red %i, blue %i, green %i\n", dices.redDices, dices.blueDices, dices.greenDices);
        
        result += dices.redDices * dices.blueDices * dices.greenDices;
    }
    printf("Result: %i \n", result);
    fclose(fptr);
}

void problem1() {
    FILE *fptr;

    fptr = fopen("input1.txt", "r");

    char line[300], *pch;
    int result = 0;

    while (fgets(line, 300, fptr)) {
        
        int numberOfGame = 0, isPossible = 1;
        pch = strtok(line,":");
        numberOfGame = atoi(&pch[5]);
        printf("Game: %i\n", numberOfGame);

        while ((pch = strtok(NULL, ";\n")) != NULL) {
            printf("Round: %s\n", pch);
            if(!countDices(pch)) {
                isPossible--;
                break;
            }
        }
        if (isPossible) {
            result += numberOfGame;
        }
        
    }
    printf("Result: %i \n", result);
    fclose(fptr);
}

int main() {
    //problem1();
    problem2();
    return 0;
}
