//
// Created by Xingyuan Wang on 3/1/17.
//

/*
    Find the total area covered by two rectilinear rectangles in a 2D plane.

    Each rectangle is defined by its bottom left corner and top right corner as shown in the figure.

    Rectangle Area
    Assume that the total area is never beyond the maximum possible value of int.
 */

#include "Math.h"

/*
ACEG => 0
ACEG => CE
AECG => EC
EACG => AC
EAGC => AG
EGAC => 0
*/

int overlap_length(int A, int C, int E, int G) {
    if (C < E || A > G) return 0;
    return min(C, G) - max(A, E);
}

int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
    int abcd = (A - C) * (B - D);
    int efgh = (E - G) * (F - H);
    int common = overlap_length(A, C, E, G) * overlap_length(B, D, F, H);
    return abcd + efgh - common;

}


