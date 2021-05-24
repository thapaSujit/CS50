#include "helpers.h"
#include <math.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    //using nested loop to get access to individual pixel in the image
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            //calculating the average pixel value
            int grey_value = round((image[i][j].rgbtBlue + image[i][j].rgbtGreen + image[i][j].rgbtRed) / (float)3);

            //setting each color value of average value calculaed above
            image[i][j].rgbtBlue = grey_value;
            image[i][j].rgbtGreen = grey_value;
            image[i][j].rgbtRed = grey_value;
        }
    }
}

//upper_value function defination
int upper_value(int RGB_vlue);
// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    //using nested loop to get access to individual pixel in the image
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            //calculating each new color value using the sepia formula
            int rgbtRedSepia = round((0.393 * image[i][j].rgbtRed) + (0.769 * image[i][j].rgbtGreen) + (0.189 * image[i][j].rgbtBlue));
            int rgbtGreenSepia = round((0.349 * image[i][j].rgbtRed) + (0.686 * image[i][j].rgbtGreen) + (0.168 * image[i][j].rgbtBlue));
            int rgbtBlueSepia = round((0.272 * image[i][j].rgbtRed) + (0.534 * image[i][j].rgbtGreen) + (0.131 * image[i][j].rgbtBlue));

            // ensuring that the result is an integer between 0 - 255=>inclusive
            image[i][j].rgbtRed = upper_value(rgbtRedSepia);
            image[i][j].rgbtGreen = upper_value(rgbtGreenSepia);
            image[i][j].rgbtBlue = upper_value(rgbtBlueSepia);
        }
    }
}

// setting the upper value to 255 even if its higher
int upper_value(int RGB_vlue)
{
    if (RGB_vlue > 255)
    {
        return 255;
    }
    return RGB_vlue;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    //creating a temporary array to swap the variables
    RGBTRIPLE tmp[height][width];

    //using loops to get access to individual pixel in the image
    for (int i = 0; i < height; i++)
    {

        // iterating each pixel until halfway, and using a temporary variable to store the left half pixel.  We are storing the left side pixel in a new variable because
        //we need to swap the right side pixel with the left side pixel and again lefft side pixel with right side pixel. if we dnt save the left side pixel in the temporary variable,
        //lefft side pixel will be lost when we swap right side pixel to left side pixel and as a result we can not swap left side pixel with right side pxel.
        for (int j = 0; j < width / 2; j++)
        {
            //storing left side pixel in a new variable tmp
            tmp[i][j] = image[i][j];
            //swapping right sie pixel with left side [1(0) 2(1) 3(2) 4(3)]->to swap 4 with 1 -> index of 4 i.e 3 is to be substracted with add (index of 1(0) +1) and so on for other
            image[i][j] = image[i][width - (j + 1)];
            //swapping left side pixel(temp-> image[i][j]) to right side
            image[i][width - (j + 1)] = tmp[i][j];

        }
    }
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    //creating a temporary array to swap the variables. if we dnt create a tmp variable when we calculate the one blurry color value, we will use that blurry
    //color value to calculate the blurry value of another pixel which is incorrect. we have to use original RGB to calculate the blur value.
    RGBTRIPLE temp[height][width];

    ////using loops to get access to individual pixel in the image
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            //set count, sum of blue, green and red to 0
            int count = 0;
            int sum_of_blue = 0;
            int sum_of_green = 0;
            int sum_of_red = 0;

            //adding values of the pixel and other 8 neighboring ones && -> skipping iteration if it goes ouside the pic. If the surrounding pixels are not
            //within the picture, we donot need to add them, however if they are within the image we have to take them while calculating the average of
            //the aount of RGB. To make picture blur, need to add alltogether 9 pixel to calculate averae if they are within the image.
            //[1 2 3]
            //[4 5 6]
            //[7 8 9] -> if current pixel is 5, we need to add all the pixel to calculate the average and make picture blurry
            for (int s = -1; s < 2; s++)
            {
                // to eliminate edges outside the image above or bottom--> column
                //[1 2 3] -> if current pixel is 1, from the row side we just add 1 and 2.
                //[4 5 6]
                //[7 8 9]
                if (i + s < 0)  //--> it seems like here is bug however do not know how to correct.***
                {
                    // moveing to the next iteration
                    continue;
                }
                // loop in the column of pixel matrix 3x3 -1 0 1
                for (int t = -1; t < 2; t++)
                {
                    // to elimiate pixels beyond left and right side outside the image --> row
                    //[1 2 3]-> if current pixel is 1, from the column side we just add 1 and 4.
                    //[4 5 6]
                    //[7 8 9]
                    if (j + t < 0) //--> it seems like here is bug however do not know how to correct. come back to it again
                    {
                        // moveing to the next iteration
                        continue;
                    }
                    //summing up the value of all the pixels
                    sum_of_blue += image[i + s][j + t].rgbtBlue;
                    sum_of_green += image[i + s][j + t].rgbtGreen;
                    sum_of_red += image[i + s][j + t].rgbtRed;
                    count++;
                }
            }
            //taking the average to make the image blurries
            temp[i][j].rgbtBlue = round(sum_of_blue / (float)count);
            temp[i][j].rgbtGreen = round(sum_of_green / (float)count);
            temp[i][j].rgbtRed = round(sum_of_red / (float)count);


        }
    }
    //using loops to get access to individual pixel in the image
    //copying values from tmp
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            image[i][j].rgbtBlue = temp[i][j].rgbtBlue;
            image[i][j].rgbtGreen = temp[i][j].rgbtGreen;
            image[i][j].rgbtRed = temp[i][j].rgbtRed;
        }
    }
}