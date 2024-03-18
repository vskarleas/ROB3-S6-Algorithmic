// #############################################################################
// # File bitmap.c
// # UE Infomatics for Robotics - Polytech Sorbonne - 2023/2024 - S6
// # Authors: Yanis Sadoun, Vasileios Filippos Skarleas - All rights reserved.
// #############################################################################

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "bitmap.h"

/* It writes an EPS file for BitMap image creation - postscript */
void create_postscript_file(int **pixels, char *file_name, int hauteur, int largeur)
{
    // Extension managment
    char *no_extension = strtok(file_name, ".");
    char *with_extension = malloc(strlen(no_extension) + 4);
    strcpy(with_extension, no_extension);
    strcat(with_extension, ".eps"); // concantenation

    // File managemnent
    FILE *fptr;
    fptr = fopen(with_extension, "w");
    if (fptr == NULL)
    {
        printf("EPS File Error!");
        exit(1);
    }
    // File redaction (modified for pixels array)
    fprintf(fptr, "%%!PS-Adobe-3.0 EPSF-3.0\n");
    fprintf(fptr, "%%%%BoundingBox:   %d   %d   %d   %d\n", 0, 0, largeur, hauteur);
    fprintf(fptr, "\n");

    // Iterate through the pixels array
    for (int y = 0; y < hauteur; y++)
    {
        for (int x = 0; x < largeur; x++)
        {
            if (pixels[y][x] == 1)
            { // Assuming 1 indicates a filled pixel
                fprintf(fptr, "%.0d %.0d moveto ", x, hauteur - y);
                // If connected pixels form contours, write lines and fill
            }
        }
    }

    // Fill and close the file
    fprintf(fptr, "fill\n");
    fprintf(fptr, "\n");
    fprintf(fptr, "showpage\n");
    fclose(fptr);
}
