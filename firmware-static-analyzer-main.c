#include <stdio.h>
#include <ctype.h>

void detectSignature(unsigned char buffer[], size_t bytesRead)
{
    if (bytesRead >= 4 &&
        buffer[0] == 0x7F &&
        buffer[1] == 0x45 &&
        buffer[2] == 0x4C &&
        buffer[3] == 0x46)
    {
        printf("Detected: ELF file\n");
    }
    
    if (bytesRead >= 2 &&
    buffer[0] == 0x1F &&
    buffer[1] == 0x8B)
    {
        printf("Detected: gzip data\n");
    }

    if (bytesRead >= 4 &&
    buffer[0] == 0x68 &&
    buffer[1] == 0x73 &&
    buffer[2] == 0x71 &&
    buffer[3] == 0x73)
    {
        printf("Detected: SquashFS filesystem\n");
    }

}

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

    detectSignature(buffer, bytesRead);

    printf("File size: %ld bytes\n", fileSize);
    
    fclose(file);

    return 0;
}