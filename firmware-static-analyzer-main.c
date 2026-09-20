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

    unsigned char buffer[32];

    size_t bytesRead = fread(buffer, 1, sizeof(buffer), file);
    
    printf("First %zu bytes:\n", bytesRead);
    
    for (size_t i = 0; i < bytesRead; i++)
    {
        printf("%02X ", buffer[i]);
    }
    
    printf("\n");

    //printf("File size: %ld bytes\n", fileSize);
    
    fclose(file);

    return 0;
}