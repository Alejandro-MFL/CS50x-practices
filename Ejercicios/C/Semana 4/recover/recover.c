#include <cs50.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    // Accept a single command-line argument
    if (argc != 2)
    {
        printf("Usage: ./recover FILE\n");
        return 1;
    }

    // Open the memory card
    FILE *card = fopen(argv[1], "r");

    // Create a buffer for a block of data
    uint8_t buffer[512];

    // Variables to create the images
    FILE *img = NULL;
    char imageName[8];
    int imageCount = 0;
    bool working = false;

    // While there's still data left to read from the memory card
    while (fread(buffer, 1, 512, card) == 512)
    {
        // Checks if the buffer starts an image file, if it starts, it activates working,
        // if not, it closes the previous image.
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff &&
            (buffer[3] & 0xf0) == 0xe0)
        {
            if (working)
            {
                fclose(img);
            }
            else
            {
                working = true;
            }
            // Create JPEGs from the data
            sprintf(imageName, "%03i.jpg", imageCount);
            img = fopen(imageName, "w");
            imageCount++;
        }
        if (working)
        {
            fwrite(buffer, 1, 512, img);
        }
    }
    // To finish, make sure to close the last image if it is open and close the search file.
    if (img != NULL)
    {
        fclose(img);
    }
    fclose(card);
}
