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
    return;
}