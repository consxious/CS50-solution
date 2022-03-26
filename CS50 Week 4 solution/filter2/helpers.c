#include "helpers.h"
#include <math.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            //Change all color into average
            float total = image[i][j].rgbtRed + image[i][j].rgbtGreen + image[i][j].rgbtBlue;
            int average = (round)(total / 3);
            image[i][j].rgbtRed = average;
            image[i][j].rgbtGreen = average;
            image[i][j].rgbtBlue = average;
        }
    }
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            //Assign variables
            float originalRed = image[i][j].rgbtRed;
            float originalGreen = image[i][j].rgbtGreen;
            float originalBlue = image[i][j].rgbtBlue;

            //Find sepia
            int sepiaRed = (round)(.393 * originalRed + .769 * originalGreen + .189 * originalBlue);
            int sepiaGreen = (round)(.349 * originalRed + .686 * originalGreen + .168 * originalBlue);
            int sepiaBlue = (round)(.272 * originalRed + .534 * originalGreen + .131 * originalBlue);

            //Set the sepia color cap to 255
            if (sepiaRed > 255)
            {
                sepiaRed = 255;
            }

            if (sepiaGreen > 255)
            {
                sepiaGreen = 255;
            }

            if (sepiaBlue > 255)
            {
                sepiaBlue = 255;
            }

            //Assign sepia color code into image[][]
            image[i][j].rgbtRed = sepiaRed;
            image[i][j].rgbtGreen = sepiaGreen;
            image[i][j].rgbtBlue = sepiaBlue;
        }
    }
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width / 2; j++)
        {
            // Swap HALF of the image width (with +1 due to indexing differences)
            RGBTRIPLE temp = image[i][j];
            image[i][j] = image[i][width - (j + 1)];
            image[i][width - (j + 1)] = temp;

        }
    }
}

// Blur image 1
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    //Make a copy of the image
    RGBTRIPLE copy[height][width];

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            copy[i][j] = image[i][j];
        }
    }

    //Loop through copy pixel
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            //Blur inside copy inner area
            //Get pixel from copy image
            if (i >= 1 && i <= height - 2)
            {
                if (j >= 1 && j <= width - 2)
                {
                    float totalRed = copy[i - 1][j - 1].rgbtRed + copy[i - 1][j].rgbtRed + copy[i - 1][j + 1].rgbtRed + copy[i][j - 1].rgbtRed +
                                     copy[i][j].rgbtRed + copy[i][j + 1].rgbtRed + copy[i + 1][j - 1].rgbtRed + copy[i + 1][j].rgbtRed + copy[i + 1][j + 1].rgbtRed;
                    float totalGreen = copy[i - 1][j - 1].rgbtGreen + copy[i - 1][j].rgbtGreen + copy[i - 1][j + 1].rgbtGreen + copy[i][j - 1].rgbtGreen
                                       + copy[i][j].rgbtGreen + copy[i][j + 1].rgbtGreen + copy[i + 1][j - 1].rgbtGreen + copy[i + 1][j].rgbtGreen + copy[i + 1][j +
                                               1].rgbtGreen;
                    float totalBlue = copy[i - 1][j - 1].rgbtBlue + copy[i - 1][j].rgbtBlue + copy[i - 1][j + 1].rgbtBlue + copy[i][j - 1].rgbtBlue +
                                      copy[i][j].rgbtBlue + copy[i][j + 1].rgbtBlue + copy[i + 1][j - 1].rgbtBlue + copy[i + 1][j].rgbtBlue + copy[i + 1][j + 1].rgbtBlue;
                    int averageRed = (round)(totalRed / 9);
                    int averageGreen = (round)(totalGreen / 9);
                    int averageBlue = (round)(totalBlue / 9);

                    //Change image pixels
                    image[i][j].rgbtRed = averageRed;
                    image[i][j].rgbtGreen = averageGreen;
                    image[i][j].rgbtBlue = averageBlue;
                }
            }

            //Blur on 4 corners
            //Get pixel from copy image
            if (i == 0 && j == 0)
            {
                float totalRed = copy[i][j].rgbtRed + copy[i][j + 1].rgbtRed + copy[i + 1][j].rgbtRed + copy[i + 1][j + 1].rgbtRed;
                float totalGreen = copy[i][j].rgbtGreen + copy[i][j + 1].rgbtGreen + copy[i + 1][j].rgbtGreen + copy[i + 1][j + 1].rgbtGreen;
                float totalBlue = copy[i][j].rgbtBlue + copy[i][j + 1].rgbtBlue + copy[i + 1][j].rgbtBlue + copy[i + 1][j + 1].rgbtBlue;
                int averageRed = (round)(totalRed / 4);
                int averageGreen = (round)(totalGreen / 4);
                int averageBlue = (round)(totalBlue / 4);
                image[i][j].rgbtRed = averageRed;
                image[i][j].rgbtGreen = averageGreen;
                image[i][j].rgbtBlue = averageBlue;

            }
            else if (i == 0 && j == width - 1)
            {
                float totalRed = copy[i][width - 2].rgbtRed + copy[i][width - 1].rgbtRed + copy[i + 1][width - 2].rgbtRed + copy[i + 1][width -
                                 1].rgbtRed;
                float totalGreen = copy[i][width - 2].rgbtGreen + copy[i][width - 1].rgbtGreen + copy[i + 1][width - 2].rgbtGreen + copy[i +
                                   1][width - 1].rgbtGreen;
                float totalBlue = copy[i][width - 2].rgbtBlue + copy[i][width - 1].rgbtBlue + copy[i + 1][width - 2].rgbtBlue + copy[i + 1][width -
                                  1].rgbtBlue;
                int averageRed = (round)(totalRed / 4);
                int averageGreen = (round)(totalGreen / 4);
                int averageBlue = (round)(totalBlue / 4);

                //Change image pixels
                image[i][j].rgbtRed = averageRed;
                image[i][j].rgbtGreen = averageGreen;
                image[i][j].rgbtBlue = averageBlue;
            }
            else if (i == height - 1 && j == 0)
            {
                float totalRed = copy[height - 2][j].rgbtRed + copy[height - 2][j + 1].rgbtRed + copy[height - 1][j].rgbtRed + copy[height - 1][j +
                                 1].rgbtRed;
                float totalGreen = copy[height - 2][j].rgbtGreen + copy[height - 2][j + 1].rgbtGreen + copy[height - 1][j].rgbtGreen + copy[height -
                                   1][j + 1].rgbtGreen;
                float totalBlue = copy[height - 2][j].rgbtBlue + copy[height - 2][j + 1].rgbtBlue + copy[height - 1][j].rgbtBlue + copy[height -
                                  1][j + 1].rgbtBlue;
                int averageRed = (round)(totalRed / 4);
                int averageGreen = (round)(totalGreen / 4);
                int averageBlue = (round)(totalBlue / 4);

                //Change image pixels
                image[i][j].rgbtRed = averageRed;
                image[i][j].rgbtGreen = averageGreen;
                image[i][j].rgbtBlue = averageBlue;
            }
            else if (i == height - 1 && j == width - 1)
            {
                float totalRed = copy[height - 2][width - 2].rgbtRed + copy[height - 2][width - 1].rgbtRed + copy[height - 1][width - 2].rgbtRed +
                                 copy[height - 1][width - 1].rgbtRed;
                float totalGreen = copy[height - 2][width - 2].rgbtGreen + copy[height - 2][width - 1].rgbtGreen + copy[height - 1][width -
                                   2].rgbtGreen + copy[height - 1][width - 1].rgbtGreen;
                float totalBlue = copy[height - 2][width - 2].rgbtBlue + copy[height - 2][width - 1].rgbtBlue + copy[height - 1][width - 2].rgbtBlue
                                  + copy[height - 1][width - 1].rgbtBlue;
                int averageRed = (round)(totalRed / 4);
                int averageGreen = (round)(totalGreen / 4);
                int averageBlue = (round)(totalBlue / 4);

                //Change image pixels
                image[i][j].rgbtRed = averageRed;
                image[i][j].rgbtGreen = averageGreen;
                image[i][j].rgbtBlue = averageBlue;
            }

            //Blur of 4 edges
            //Get pixel from copy image
            if (i == 0)
            {
                if (j >= 1 && j <= width - 2)
                {
                    float totalRed = copy[i][j - 1].rgbtRed + copy[i][j].rgbtRed + copy[i][j + 1].rgbtRed + copy[i + 1][j - 1].rgbtRed + copy[i +
                                     1][j].rgbtRed + copy[i + 1][j + 1].rgbtRed;
                    float totalGreen = copy[i][j - 1].rgbtGreen + copy[i][j].rgbtGreen + copy[i][j + 1].rgbtGreen + copy[i + 1][j - 1].rgbtGreen +
                                       copy[i + 1][j].rgbtGreen + copy[i + 1][j + 1].rgbtGreen;
                    float totalBlue = copy[i][j - 1].rgbtBlue + copy[i][j].rgbtBlue + copy[i][j + 1].rgbtBlue + copy[i + 1][j - 1].rgbtBlue + copy[i +
                                      1][j].rgbtBlue + copy[i + 1][j + 1].rgbtBlue;
                    int averageRed = (round)(totalRed / 6);
                    int averageGreen = (round)(totalGreen / 6);
                    int averageBlue = (round)(totalBlue / 6);

                    //Change image pixels
                    image[i][j].rgbtRed = averageRed;
                    image[i][j].rgbtGreen = averageGreen;
                    image[i][j].rgbtBlue = averageBlue;
                }
            }

            if (i >= 1 && i <= height - 2)
            {
                if (j == 0)
                {
                    float totalRed = copy[i - 1][j].rgbtRed + copy[i][j].rgbtRed + copy[i + 1][j].rgbtRed + copy[i - 1][j + 1].rgbtRed + copy[i][j +
                                     1].rgbtRed + copy[i + 1][j + 1].rgbtRed;
                    float totalGreen = copy[i - 1][j].rgbtGreen + copy[i][j].rgbtGreen + copy[i + 1][j].rgbtGreen + copy[i - 1][j + 1].rgbtGreen +
                                       copy[i][j + 1].rgbtGreen + copy[i + 1][j + 1].rgbtGreen;
                    float totalBlue = copy[i - 1][j].rgbtBlue + copy[i][j].rgbtBlue + copy[i + 1][j].rgbtBlue + copy[i - 1][j + 1].rgbtBlue + copy[i][j
                                      + 1].rgbtBlue + copy[i + 1][j + 1].rgbtBlue;
                    int averageRed = (round)(totalRed / 6);
                    int averageGreen = (round)(totalGreen / 6);
                    int averageBlue = (round)(totalBlue / 6);

                    //Change image pixels
                    image[i][j].rgbtRed = averageRed;
                    image[i][j].rgbtGreen = averageGreen;
                    image[i][j].rgbtBlue = averageBlue;
                }
            }

            if (i >= 1 && i <= height - 2)
            {
                if (j == width - 1)
                {
                    float totalRed = copy[i - 1][width - 2].rgbtRed + copy[i - 1][width - 1].rgbtRed + copy[i][width - 2].rgbtRed + copy[i][width -
                                     1].rgbtRed + copy[i + 1][width - 2].rgbtRed + copy[i + 1][width - 1].rgbtRed;
                    float totalGreen = copy[i - 1][width - 2].rgbtGreen + copy[i - 1][width - 1].rgbtGreen + copy[i][width - 2].rgbtGreen +
                                       copy[i][width - 1].rgbtGreen + copy[i + 1][width - 2].rgbtGreen + copy[i + 1][width - 1].rgbtGreen;
                    float totalBlue = copy[i - 1][width - 2].rgbtBlue + copy[i - 1][width - 1].rgbtBlue + copy[i][width - 2].rgbtBlue + copy[i][width -
                                      1].rgbtBlue + copy[i + 1][width - 2].rgbtBlue + copy[i + 1][width - 1].rgbtBlue;
                    int averageRed = (round)(totalRed / 6);
                    int averageGreen = (round)(totalGreen / 6);
                    int averageBlue = (round)(totalBlue / 6);

                    //Change image pixels
                    image[i][j].rgbtRed = averageRed;
                    image[i][j].rgbtGreen = averageGreen;
                    image[i][j].rgbtBlue = averageBlue;
                }
            }

            if (i == height - 1)
            {
                if (j >= 1 && j <= width - 2)
                {
                    float totalRed = copy[height - 2][j - 1].rgbtRed + copy[height - 2][j].rgbtRed + copy[height - 2][j + 1].rgbtRed + copy[height -
                                     1][j - 1].rgbtRed + copy[height - 1][j].rgbtRed + copy[height - 1][j + 1].rgbtRed;
                    float totalGreen = copy[height - 2][j - 1].rgbtGreen + copy[height - 2][j].rgbtGreen + copy[height - 2][j + 1].rgbtGreen +
                                       copy[height - 1][j - 1].rgbtGreen + copy[height - 1][j].rgbtGreen + copy[height - 1][j + 1].rgbtGreen;
                    float totalBlue = copy[height - 2][j - 1].rgbtBlue + copy[height - 2][j].rgbtBlue + copy[height - 2][j + 1].rgbtBlue + copy[height -
                                      1][j - 1].rgbtBlue + copy[height - 1][j].rgbtBlue + copy[height - 1][j + 1].rgbtBlue;
                    int averageRed = (round)(totalRed / 6);
                    int averageGreen = (round)(totalGreen / 6);
                    int averageBlue = (round)(totalBlue / 6);

                    //Change image pixels
                    image[i][j].rgbtRed = averageRed;
                    image[i][j].rgbtGreen = averageGreen;
                    image[i][j].rgbtBlue = averageBlue;
                }
            }
        }
    }
}  