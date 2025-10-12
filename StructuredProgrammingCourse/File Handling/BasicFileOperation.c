

#include <stdio.h>

int main() {
    FILE *filePointer = fopen("newfile.py", "a");
    fprintf(filePointer, "\nprint(\"auto generated file\")");
    fclose(filePointer);

    filePointer = fopen("newfile.py", "r");
    if (!filePointer) {
        printf("Error opening file!\n");
        return 1;
    }

    char fileContent[100];
    while (fgets(fileContent, sizeof(fileContent), filePointer)) {
        printf("%s", fileContent);
    }

    fclose(filePointer);
    return 0;
}
