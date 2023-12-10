#include <stdio.h>
#include <string.h>

struct Dices {
    int greenDices;
    int redDices;
    int blueDices;
};

int parseNumberOfGame(char *str) {
    char numberOfGameStr[4] = {""};
    int numberOfGame = 0, numberOfGameStrLength = 0, length = strlen(str);

    strncpy(numberOfGameStr, &str[5], length-5);
    numberOfGameStrLength = strlen(numberOfGameStr) - 1;
    
    for (int i = 0; i < strlen(numberOfGameStr); i++) {
        numberOfGame += (numberOfGameStrLength - i) * 10 * ((int)numberOfGameStr[i] - 48);
    }
    numberOfGame += (int)numberOfGameStr[numberOfGameStrLength] - 48;
    return numberOfGame;
}

struct Dices countDices(struct Dices dices, char *str) {
    char buffer[100];
    size_t pos = 0;
    size_t len = strlen(str);

    while (pos < len) {
        int n = strcspn(str + pos, ","); // Znajduje pierwszy przecinek lub koniec ciągu
        strncpy(buffer, str + pos, n);   // Kopiuje do bufora
        buffer[n] = '\0';                // Dodaje znak końca ciągu

        printf("%s\n", buffer);          // Tu można dodać logikę przetwarzania

        pos += n + (str[pos + n] != '\0'); // Przesuwa pozycję za przecinek
    }

    return dices;
}

void problem1() {
    FILE *fptr;

    fptr = fopen("example1.txt", "r");
    if (fptr == NULL) {
        perror("Error opening file");
        return;
    }

    char line[300], *pch;
    struct Dices dices = {0, 0, 0};

    while (fgets(line, 300, fptr)) {
        int numberOfGame = 0;
        char round[100];

        pch = strtok(line, ":");
        if (pch != NULL) {
            numberOfGame = parseNumberOfGame(pch);

            while ((pch = strtok(NULL, ";\n")) != NULL) {
                strcpy(round, pch);
                printf("Round: %s\n", round);
                dices = countDices(dices, round);
            }
        }
    }

    fclose(fptr);
}

int main() {
    problem1();
    return 0;
}

