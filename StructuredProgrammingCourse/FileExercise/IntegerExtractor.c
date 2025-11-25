#include <stdio.h>
#include <stdlib.h> // For malloc and free

int main() {
    char input_string[] = "10 25 -5 100";
    int numbers[10]; // Assuming a maximum of 10 integers
    int count = 0;
    char *ptr = input_string;
    int value;
    int offset;

    while (sscanf(ptr, "%d%n", &value, &offset) == 1) {
        if (count < 10) { // Prevent buffer overflow
            numbers[count++] = value;
        }
        ptr += offset; // Move the pointer past the scanned number and any whitespace
    }

    printf("Extracted integers: ");
    for (int i = 0; i < count; i++) {
        printf("%d ", numbers[i]);
    }
    printf("\n");

    return 0;
}