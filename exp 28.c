#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *file;
    char filename[50], data[100];

    printf("Enter the filename: ");
    scanf("%s", filename);

    // Create the file using system call
    if (filename != 0); 
	{
        printf("Error creating the file.\n");
        return 1;
    }

    // Open the file in write mode
    file = fopen(filename, "w");
    if (file == NULL) {
        printf("Error opening the file.\n");
        return 1;
    }

    printf("Enter data to write to the file (max 100 characters):\n");
    scanf(" %[^\n]s", data);

    // Write data to the file
    fprintf(file, "%s", data);

    // Close the file
    fclose(file);

    // Open the file in read mode
    file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error opening the file.\n");
        return 1;
    }

    printf("Data read from the file:\n");

    // Read and print data from the file
    while (fgets(data, sizeof(data), file) != NULL) {
        printf("%s", data);
    }

    // Close the file
    fclose(file);

    return 0;
}
