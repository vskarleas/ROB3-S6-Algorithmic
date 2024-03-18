// #############################################################################
// # File bitmap.h
// # UE Infomatics for Robotics - Polytech Sorbonne - 2023/2024 - S6
// # Authors: Yanis Sadoun, Vasileios Filippos Skarleas - All rights reserved.
// #############################################################################

#ifndef H_BITMAP
#define H_BITMAP

/* It writes an EPS file for BitMap image creation - postscript */
void create_postscript_file(int **pixels, char *file_name, int hauteur, int largeur);

#endif