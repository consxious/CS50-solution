#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

// New type to store a byte of data
typedef uint8_t BYTE;

// Number of "block size" 512
const int BLOCK_SIZE = 512;

int main(int argc, char *argv[])
{
    // Check for 2 command-line arguments
    if (argc != 2)
    {
        printf("Usage: ./recover IMAGE\n");
        return 1;
    }

    // Open card.raw file
    FILE *input = fopen(argv[1], "r");

    // Check for fail to open
    if (input == NULL)
    {
        printf("Couldn't open the file.\n");
        return 1;
    }

    // 1 block size = 512 Bytes
    BYTE buffer[BLOCK_SIZE];

    // Count image
    int count_image = 0;

    // Assign NULL to output_file
    FILE *output = NULL;

    // Declare filename
    char filename[8];

    // Read till end of memory
    // fread / fwrite can use &buffer / buffer
    while (fread(buffer, sizeof(BYTE), BLOCK_SIZE, input) == BLOCK_SIZE)
    {
        // Check first 4 blocks for JPEG format
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0)
        {
            // Only for first image, generate new filename and write into it
            if (count_image == 0)
            {
                // Generate a new file with sequence name
                sprintf(filename, "%03i.jpg", count_image);

                // Open new file
                output = fopen(filename, "w");

                // fwrite
                fwrite(buffer, sizeof(BYTE), BLOCK_SIZE, output);

                // Add counter
                count_image++;
            }

            // For subsequence new repeat JPG images
            // Close output file, generate new file, and write into it
            else if (count_image > 0)
            {
                // fclose current writing files
                fclose(output);

                // Generate a new file with sequence name
                sprintf(filename, "%03i.jpg", count_image);

                // Open new file
                output = fopen(filename, "w");

                // fwrite
                fwrite(buffer, sizeof(BYTE), BLOCK_SIZE, output);

                // Add counter
                count_image++;
            }
        }
        // Not fulfill the 4 bytes JPG condition, keep writing to the same filename
        else if (count_image > 0)
        {
            fwrite(buffer, sizeof(BYTE), BLOCK_SIZE, output);
        }
    }
    fclose(output);
    fclose(input);
}
