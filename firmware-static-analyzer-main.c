#include <stdio.h>

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("Usage: %s <firmware_file>\n", argv[0]);
        return 1;
    }
    FILE *file = fopen(argv[1], "rb");

    if (file == NULL)
    {
        printf("Could not open file.\n");
        return 1;
    }
    printf("Opened: %s\n", argv[1]);
    
    fseek(file, 0, SEEK_END);

    long fileSize = ftell(file);

    fseek(file, 0, SEEK_SET);

    printf("File size: %ld bytes\n", fileSize);
    
    fclose(file);

    return 0;
}