#include <stdio.h>
#include <string.h>

struct Position {
    int x;
    int y;
};

size_t countLines(FILE *file) {
    
    size_t length = 0;
    size_t pos = ftell(file);
    fseek(file, 0, SEEK_SET);
    char line[100];
    while(fgets(line,100,file)) {
        length++;
    }
    fseek(file, pos, SEEK_SET);
    return length;
}

int problem1(FILE *file) {

    size_t length = countLines(file);
    
    char line[100], matrix[100][length];
    struct Position positions[100*length];

    while (fgets(line,100,file)) {
        int n = strcspn(line, "*&");
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
