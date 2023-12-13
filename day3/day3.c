#include <stdio.h>
#include <string.h>

#define LEN_OF_LINE 100

struct Position {
    int x;
    int y;
};

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

char createBitMatrix(FILE *file, size_t length) {
    
}


int problem1(FILE *file) {

    size_t length = countLines(file);
    
    char line[LEN_OF_LINE], matrix[LEN_OF_LINE][length];
    struct Position positions[LEN_OF_LINE*length];

    while (fgets(line,LEN_OF_LINE,file)) {
        int n = strcspn(line, "!@#$%^&*");
        printf("%s", line);
    }
    printf("%zu", length);
    
    fclose(file);
    
    return 0; 
}

int main() {
    
    FILE *file;
    file = fopen("example.txt", "r");

    problem1(file);


    return 0;
}
