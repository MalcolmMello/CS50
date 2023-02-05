#include "helpers.h"
#include <math.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for(int i = 0; i < height; i++)
    {
        for(int j = 0; j < width; j++)
        {
            float average = (image[i][j].rgbtRed + image[i][j].rgbtGreen + image[i][j].rgbtBlue) / 3.00;
            int newAverage = round(average);

            image[i][j].rgbtRed = newAverage;
            image[i][j].rgbtGreen = newAverage;
            image[i][j].rgbtBlue = newAverage;
        }
    }

    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    for(int row = 0; row < height; row++)
    {
        for(int col = 0; col < width/2; col++)
        {
            int tmpRed = image[row][width - 1 - col].rgbtRed;
            int tmpGreen = image[row][width - 1 - col].rgbtGreen;
            int tmpBlue = image[row][width - 1 - col].rgbtBlue;

            image[row][width - 1 - col].rgbtRed = image[row][col].rgbtRed;
            image[row][width - 1 - col].rgbtGreen = image[row][col].rgbtGreen;
            image[row][width - 1 - col].rgbtBlue = image[row][col].rgbtBlue;

            image[row][col].rgbtRed = tmpRed;
            image[row][col].rgbtGreen = tmpGreen;
            image[row][col].rgbtBlue = tmpBlue;
        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    for(int row = 0; row < height; row++)
    {
        for(int col = 0; col < width; col++)
        {
            int red = 0;
            int green = 0;
            int blue = 0;

            for(int rgb = 0; rgb < 3; rgb++)
            {
                float top_line_average = 0;
                float current_line_average = 0;
                float bottom_line_average = 0;

                int total_values = 0;

                if(rgb == 0) //red
                {
                    if(row != 0)
                    {
                        if(col != width && col != 0)
                        {
                            top_line_average = image[row - 1][col - 1].rgbtRed + image[row - 1][col].rgbtRed + image[row - 1][col + 1].rgbtRed;
                            total_values += 3;
                        }
                        else if(col == width)
                        {
                            top_line_average = image[row - 1][col - 1].rgbtRed + image[row - 1][col].rgbtRed;
                            total_values += 2;
                        }
                        else
                        {
                            top_line_average = image[row - 1][col].rgbtRed + image[row - 1][col + 1].rgbtRed;
                            total_values += 2;
                        }

                    }

                    if(col != width && col != 0)
                    {
                        current_line_average = image[row][col - 1].rgbtRed + image[row][col + 1].rgbtRed;
                        total_values += 2;
                    }
                    else if(col == width)
                    {
                        current_line_average = image[row][col - 1].rgbtRed;
                        total_values += 1;
                    }
                    else
                    {
                        current_line_average = image[row][col + 1].rgbtRed;
                        total_values += 1;
                    }



                    if(row != height)
                    {
                        if(col != width && col != 0)
                        {
                             bottom_line_average = image[row + 1][col - 1].rgbtRed + image[row + 1][col].rgbtRed + image[row + 1][col + 1].rgbtRed;
                             total_values += 3;
                        }
                        else if(col == width)
                        {
                            bottom_line_average = image[row + 1][col - 1].rgbtRed + image[row + 1][col].rgbtRed;
                            total_values += 2;
                        }
                        else
                        {
                             bottom_line_average = image[row + 1][col].rgbtRed + image[row + 1][col + 1].rgbtRed;
                             total_values += 2;
                        }

                    }

                    red = round((top_line_average + current_line_average + bottom_line_average) / total_values); //red values
                }

                else if(rgb == 1) //green
                {
                    if(row != 0)
                    {
                        if(col != width && col != 0)
                        {
                            top_line_average = image[row - 1][col - 1].rgbtGreen + image[row - 1][col].rgbtGreen + image[row - 1][col + 1].rgbtGreen;
                            total_values += 3;
                        }
                        else if(col == width)
                        {
                            top_line_average = image[row - 1][col - 1].rgbtGreen + image[row - 1][col].rgbtGreen;
                            total_values += 2;
                        }
                        else
                        {
                            top_line_average = image[row - 1][col].rgbtGreen + image[row - 1][col + 1].rgbtGreen;
                            total_values += 2;
                        }

                    }

                    if(col != width && col != 0)
                    {
                        current_line_average = image[row][col - 1].rgbtGreen + image[row][col + 1].rgbtGreen;
                        total_values += 2;
                    }
                    else if(col == width)
                    {
                        current_line_average = image[row][col - 1].rgbtGreen;
                        total_values += 1;
                    }
                    else
                    {
                        current_line_average = image[row][col + 1].rgbtGreen;
                        total_values += 1;
                    }



                    if(row != height)
                    {
                        if(col != width && col != 0)
                        {
                             bottom_line_average = image[row + 1][col - 1].rgbtGreen + image[row + 1][col].rgbtGreen + image[row + 1][col + 1].rgbtGreen;
                             total_values += 3;
                        }
                        else if(col == width)
                        {
                            bottom_line_average = image[row + 1][col - 1].rgbtGreen + image[row + 1][col].rgbtGreen;
                            total_values += 2;
                        }
                        else
                        {
                             bottom_line_average = image[row + 1][col].rgbtGreen + image[row + 1][col + 1].rgbtGreen;
                             total_values += 2;
                        }

                    }

                    green = round((top_line_average + current_line_average + bottom_line_average) / total_values); //green values
                }

                else //blue
                {
                    if(row != 0)
                    {
                        if(col != width && col != 0)
                        {
                            top_line_average = image[row - 1][col - 1].rgbtBlue + image[row - 1][col].rgbtBlue + image[row - 1][col + 1].rgbtBlue;
                            total_values += 3;
                        }
                        else if(col == width)
                        {
                            top_line_average = image[row - 1][col - 1].rgbtBlue + image[row - 1][col].rgbtBlue;
                            total_values += 2;
                        }
                        else
                        {
                            top_line_average = image[row - 1][col].rgbtBlue + image[row - 1][col + 1].rgbtBlue;
                            total_values += 2;
                        }

                    }

                    if(col != width && col != 0)
                    {
                        current_line_average = image[row][col - 1].rgbtBlue + image[row][col + 1].rgbtBlue;
                        total_values += 2;
                    }
                    else if(col == width)
                    {
                        current_line_average = image[row][col - 1].rgbtBlue;
                        total_values += 1;
                    }
                    else
                    {
                        current_line_average = image[row][col + 1].rgbtBlue;
                        total_values += 1;
                    }



                    if(row != height)
                    {
                        if(col != width && col != 0)
                        {
                             bottom_line_average = image[row + 1][col - 1].rgbtBlue + image[row + 1][col].rgbtBlue + image[row + 1][col + 1].rgbtBlue;
                             total_values += 3;
                        }
                        else if(col == width)
                        {
                            bottom_line_average = image[row + 1][col - 1].rgbtBlue + image[row + 1][col].rgbtBlue;
                            total_values += 2;
                        }
                        else
                        {
                             bottom_line_average = image[row + 1][col].rgbtBlue + image[row + 1][col + 1].rgbtBlue;
                             total_values += 2;
                        }

                    }

                    blue = round((top_line_average + current_line_average + bottom_line_average) / total_values); //red values
                }

            }

            image[row][col].rgbtRed = red;
            image[row][col].rgbtGreen = green;
            image[row][col].rgbtBlue = blue;
        }
    }
    return;
}

// Detect edges
void edges(int height, int width, RGBTRIPLE image[height][width])
{
    //Create a copy of the image

   RGBTRIPLE temp[height][width];

   for(int i = 0; i < height; i++)
    {
        for(int j = 0; j < width; j++)
        {
            temp[i][j] = image[i][j];
        }
    }

    //Initializing Gx and Gy

    int Gx[3][3] = {{-1, 0, 1}, {-2, 0, 2}, {-1, 0, 1}};

    int Gy[3][3] = {{-1, -2, -1}, {0, 0, 0}, {1, 2, 1}};

    // Loop through each row and column

    for(int i = 0; i < height; i++)
    {
        for(int j = 0; j < width; j++)
        {
            int redX = 0;
            int greenX = 0;
            int blueX = 0;
            int redY = 0;
            int greenY = 0;
            int blueY = 0;

            // Loop through each pixel for neighbouring pixels
            for(int x = 0; x < 3; x++)
            {
                for(int y = 0; y < 3; y++)
                {
                    // Check for valid pixels
                    if(i - 1 + x < 0 || i - 1 + x > height - 1 || j - 1 + y > width - 1)
                    {
                        continue;
                    }

                    //Calculate Gx for each column

                    redX = redX + (image[i - 1 + x][j - 1 + y].rgbtRed * Gx[x][y]);
                    greenX = greenX + (image[i - 1 + x][j - 1 + y].rgbtGreen * Gx[x][y]);
                    blueX = blueX + (image[i - 1 + x][j - 1 + y].rgbtBlue * Gx[x][y]);

                    //Calculate Gy for each column

                    redY = redY + (image[i - 1 + x][j - 1 + y].rgbtRed * Gy[x][y]);
                    greenY = greenY + (image[i - 1 + x][j - 1 + y].rgbtGreen * Gy[x][y]);
                    blueY = blueY + (image[i - 1 + x][j - 1 + y].rgbtBlue * Gy[x][y]);
                }
            }

            // Calculate square root of Gx2 and Gy2

            int red = round(sqrt((redX * redX) + (redY * redY)));
            int green = round(sqrt((greenX * greenX) + (greenX * greenX)));
            int blue = round(sqrt((blueX * blueX) + (blueX * blueX)));


            // Cap value at 255 if exceeds
            if(red > 255)
            {
                red = 255;
            }
            if(green > 255)
            {
                green = 255;
            }
            if(blue > 255)
            {
                blue = 255;
            }

            // Copy values into temp image

            temp[i][j].rgbtRed = red;
            temp[i][j].rgbtGreen = green;
            temp[i][j].rgbtBlue = blue;

        }
    }

    // Copy new pixels into original image

    for(int i = 0; i < height; i++)
    {
        for(int j = 0; j < width; j++)
        {

            image[i][j].rgbtRed  = temp[i][j].rgbtRed;
            image[i][j].rgbtGreen  = temp[i][j].rgbtGreen;
            image[i][j].rgbtBlue  = temp[i][j].rgbtBlue;
        }
    }
    return;
}