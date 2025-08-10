#include "helpers.h"
#include <math.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    // It goes through the matrix changing each pixel to gray,
    // taking the average of the three lights and equalizing them.
    for (int y = 0; y < height; y++)
    {
        for (int x = 0; x < width; x++)
        {
            int r = image[y][x].rgbtRed;
            int g = image[y][x].rgbtGreen;
            int b = image[y][x].rgbtBlue;

            int average = (int) ((r + g + b) / 3.0 + 0.5);

            image[y][x].rgbtRed = average;
            image[y][x].rgbtGreen = average;
            image[y][x].rgbtBlue = average;
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    // It will go through the left half of the matrix and each element will change with the opposite
    // on the right side.
    for (int y = 0; y < height; y++)
    {
        for (int x = 0; x < width / 2; x++)
        {
            RGBTRIPLE RGBTemp = image[y][x];
            image[y][x] = image[y][width - x - 1];
            image[y][width - x - 1] = RGBTemp;
        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE RGBTemp[height][width];
    // Create a copy that will save the blurred values
    for (int y = 0; y < height; y++)
    {
        for (int x = 0; x < width; x++)
        {
            int totalRed = 0;
            int totalGreen = 0;
            int totalBlue = 0;
            int count = 0;

            // At each pixel it measures the surrounding pixels and then saves the value of
            // that pixel in the temporary image.
            for (int areaOfY = -1; areaOfY <= 1; areaOfY++)
            {
                for (int areaOfX = -1; areaOfX <= 1; areaOfX++)
                {
                    int adjacentOfX = x + areaOfX;
                    int adjacentOfY = y + areaOfY;

                    if (adjacentOfX >= 0 && adjacentOfX < width && adjacentOfY >= 0 &&
                        adjacentOfY < height)
                    {
                        totalRed += image[adjacentOfY][adjacentOfX].rgbtRed;
                        totalGreen += image[adjacentOfY][adjacentOfX].rgbtGreen;
                        totalBlue += image[adjacentOfY][adjacentOfX].rgbtBlue;
                        count++;
                    }
                }
            }
            RGBTemp[y][x].rgbtRed = round(totalRed / (float) count);
            RGBTemp[y][x].rgbtGreen = round(totalGreen / (float) count);
            RGBTemp[y][x].rgbtBlue = round(totalBlue / (float) count);
        }
    }
    // Browse and copy the temporary image
    for (int y = 0; y < height; y++)
    {
        for (int x = 0; x < width; x++)
        {
            image[y][x] = RGBTemp[y][x];
        }
    }
    return;
}

// Detect edges
void edges(int height, int width, RGBTRIPLE image[height][width])
{
    // Create a copy and create GX and GY (2 kernels)
    RGBTRIPLE RGBTemp[height][width];

    int GX[3][3] = {{-1, 0, 1}, {-2, 0, 2}, {-1, 0, 1}};
    int GY[3][3] = {{-1, -2, -1}, {0, 0, 0}, {1, 2, 1}};

    for (int y = 0; y < height; y++)
    {
        for (int x = 0; x < width; x++)
        {
            int sumRX = 0, sumGX = 0, sumBX = 0;
            int sumRY = 0, sumGY = 0, sumBY = 0;
            // They accumulate the weighted sum of colors with GX and GY.

            for (int areaOfY = -1; areaOfY <= 1; areaOfY++)
            {
                for (int areaOfX = -1; areaOfX <= 1; areaOfX++)
                {
                    // Walk around the 3x3 grid, check the margins and calculate the value of GX and
                    // GY
                    int adjacentOfX = x + areaOfX;
                    int adjacentOfY = y + areaOfY;

                    if (adjacentOfX >= 0 && adjacentOfX < width && adjacentOfY >= 0 &&
                        adjacentOfY < height)
                    {
                        int weightX = GX[areaOfY + 1][areaOfX + 1];
                        int weightY = GY[areaOfY + 1][areaOfX + 1];

                        sumRX += image[adjacentOfY][adjacentOfX].rgbtRed * weightX;
                        sumGX += image[adjacentOfY][adjacentOfX].rgbtGreen * weightX;
                        sumBX += image[adjacentOfY][adjacentOfX].rgbtBlue * weightX;

                        sumRY += image[adjacentOfY][adjacentOfX].rgbtRed * weightY;
                        sumGY += image[adjacentOfY][adjacentOfX].rgbtGreen * weightY;
                        sumBY += image[adjacentOfY][adjacentOfX].rgbtBlue * weightY;
                    }
                }
            }
            // calculates the final value according to the function: √(Gx² + Gy²)
            // and limits the values so that they do not exceed 255, which is the limit
            int red = round(sqrt(sumRX * sumRX + sumRY * sumRY));
            int green = round(sqrt(sumGX * sumGX + sumGY * sumGY));
            int blue = round(sqrt(sumBX * sumBX + sumBY * sumBY));

            RGBTemp[y][x].rgbtRed = (red > 255) ? 255 : red;
            RGBTemp[y][x].rgbtGreen = (green > 255) ? 255 : green;
            RGBTemp[y][x].rgbtBlue = (blue > 255) ? 255 : blue;
        }
    }
    // Browse and copy the temporary image
    for (int y = 0; y < height; y++)
    {
        for (int x = 0; x < width; x++)
        {
            image[y][x] = RGBTemp[y][x];
        }
    }
    return;
}
