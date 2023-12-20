#include <stdio.h>
#include <string.h>

#define LEN_OF_LINE 100


size_t countLines(FILE *file) {

    size_t length = 0;
    size_t pos = ftell(file);
    fseek(file, 0, SEEK_SET);
    char line[LEN_OF_LINE];

    while(fgets(line,LEN_OF_LINE,file)) {
        length++;
    }

    fseek(file, pos, SEEK_SET);
    return length;

}

int problem1(FILE *file) {

    size_t rowCount = countLines(file);
    
    char line[LEN_OF_LINE]; 

    fgets(line, LEN_OF_LINE, file);
    int columnCount = strlen(line)-1, matrix[columnCount][rowCount], row = 0;
    fseek(file, 0, SEEK_SET);

    while (fgets(line,LEN_OF_LINE,file)) {
        printf("%s", line);
        for (int column = 0; column < columnCount; column++) {
            int isMarked = strcspn(&line[column], "+-_!@#$%^&*");
            matrix[row][column] = (!isMarked) ? 1 : 0;
            printf("%i",matrix[row][column]);
        }
        row++;
        printf("\n");
    }

    fseek(file, 0, SEEK_SET);

    while (fgets(line,LEN_OF_LINE,file)) {
        printf("%s", line);
        
        for (int column = 0; column < columnCount; column++) {
            int isNumber = strcspn(&line[column], "1234567890");
            if(!isNumber) {
            
            } 
            printf("%i",matrix[row][column]);
        }
        row++;
        printf("\n");
    }


    printf("%zu", rowCount);
    fclose(file);

    return 0; 
}

int main() {
    
    FILE *file;
    file = fopen("example.txt", "r");

    problem1(file);


    return 0;
}
