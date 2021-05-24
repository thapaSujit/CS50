#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>

//defining a new byte representing an 8 bit unsigned char anf a block_size of 512 bytes
#define Block_Size 512
typedef uint8_t BYTE;

int main(int argc, char *argv[])
{
    // ensuring only one comand line arguement, if not printing "Usage: ./recover image"
    if (argc != 2)
    {
        printf("Usage: ./recover image\n");
        return 1;
    }

    //opening the memory card in the "r" mode
    char *input_file = argv[1];
    FILE *inpptr = fopen(input_file, "r");

    //to check if we got the legitimate pointer back
    if (inpptr == NULL)
    {
        printf("could not get back legitimate pointer back\n");
        return 1;
    }

    BYTE buffer[Block_Size];
    int jpeg_count = 0;
    bool is_jpeg = false;
    FILE *outptr = NULL;

    //reading through the whole block untill no further blocks are found. after reading the blocks if the required signature for the Jpeg is found then setting
    //the is_jpeg file to true then it should start writing the file that was read. At the end of the block the files should be closed
    while (fread(buffer, Block_Size, 1, inpptr) != 0)
    //On success, fread() and fwrite() return the number of items read or written. This number equals the number of bytes transferred only when size is 1. If an
    //error occurs, or the end of the file is reached, the return value is a short item count (or zero).
    {

        // looking for the beginning of the JPEG file and if jpeg file is found setting is_jpeg true and start writing
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0)
        {
            is_jpeg = true;

            //as the file name = 03i.jpg + '\0' which makes it 8 bytes so setting filenme with 8 bytes.
            char filename[8];
            sprintf(filename, "%03i.jpg", jpeg_count);

            //creating a new file to write the data we find on the memory card
            outptr = fopen(filename, "w");
            jpeg_count++;

        }

        //when the jpegs are found then writing it into the new files
        if (is_jpeg == true)
        {
            fwrite(buffer, Block_Size, 1, outptr);
        }
    }

    //closing the file when reached end of file
    if (outptr == NULL)
    {
        fclose(outptr);
    }

    if (inpptr == NULL)
    {
        fclose(inpptr);
    }
}
//fgets() reads in at most one less than size characters from stream and stores them into the buffer pointed to by s. Reading stops after an EOF or a newline. If a newline is read, it is stored into the buffer. A terminating null byte ('\0') is stored after the last character in the buffer.
//fgets() returns s on success, and NULL on error or when end of file occurs while no characters have been read.