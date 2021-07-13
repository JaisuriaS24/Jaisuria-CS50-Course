#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <cs50.h>
#include <stdbool.h>

#define BLOCK_SIZE 512 //This part is used to create a data set of 512 bytes.

typedef uint8_t BYTE;

int main(int argc, char *argv[])
{
    if (argc != 2) //This part checks if there are 2 arguments.
    {
        printf("Usage: ./recover");
        return 1;
    }

    char *rawfile = argv[1];
    FILE *file_input = fopen(rawfile, "r");
    if (file_input == NULL) //This part is programmed to open the given filename.
    {
        printf("Could not open %s.\n", rawfile);
        return 1;
    }

    BYTE buffer[512];

    int counter = 0;

    char title[8];

    bool open = false;
    FILE *file_output;

    while (fread(&buffer, 512, 1, file_input) > 0)
    {
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && ((buffer[3] & 224) == 0xe0))  //(224 = 0xe0 = 11100000 in binary)
        {
            sprintf(title, "%d%d%d.jpg", counter / 100, (counter % 100) / 10, counter % 10);
            file_output = fopen(title, "w");
            open = true;

            fwrite(buffer, 512, 1, file_output);
            counter++;
        }
        else if (open == true)
        {
            fwrite(buffer, 512, 1, file_output);
        }
    }

    fclose(file_output);

    fclose(file_input); //This part helps with closing all the open files.
}