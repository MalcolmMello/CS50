#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

typedef uint8_t BYTE;

int main(int argc, char *argv[])
{
    //Check usage

    if(argc != 2)
    {
        return 1;
    }

    //Open file

    FILE *file = fopen(argv[1], "r");

    if(!file)
    {
        return 1;
    }

    //Output img

    FILE *img = NULL;

    //Read 512 bytes

    BYTE buffer[512];

    int number_of_jpeg = 0;

    char *filename = malloc(8 * sizeof(char));

    while(fread(buffer, sizeof(BYTE), 512, file))
    {
        if(buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0)
        {
            sprintf(filename, "%03i.jpg", number_of_jpeg);

            img = fopen(filename, "w");


            number_of_jpeg++;
        }

        if(img != NULL)
        {
            fwrite(buffer, sizeof(BYTE), 512, img);
        }

    }

    free(filename);
    fclose(img);
    fclose(file);

    return 0;
}