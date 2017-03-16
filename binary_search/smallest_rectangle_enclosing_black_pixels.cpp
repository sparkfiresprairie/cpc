//
// Created by Xingyuan Wang on 3/15/17.
//

/*
    An image is represented by a binary matrix with 0 as a white pixel and 1
    as a black pixel. The black pixels are connected, i.e., there is only one
    black region. Pixels are connected horizontally and vertically. Given the
    location (x, y) of one of the black pixels, return the area of the smallest
    (axis-aligned) rectangle that encloses all black pixels.

    For example, given the following image:

    [
      "0010",
      "0110",
      "0100"
    ]
    and x = 0, y = 2,
    Return 6.
 */

#include "BinarySearch.h"

int searchColumns(vector<vector<char>> const& image, int i, int j, int top, int bottom, bool opt) {
    while (i < j) {
        int k = top, mid = i + (j - i) / 2;
        while (k < bottom && image[k][mid] == '0') ++k;
        // opt == true: find first black pixel in the left part
        // opt == false: find first white pixel in the right part
        if (k < bottom == opt) {
            j = mid;
        } else {
            i = mid + 1;
        }
    }
    return i;
}

int searchRows(vector<vector<char>> const& image, int i, int j, int left, int right, bool opt) {
    while (i < j) {
        int k = left, mid = i + (j - i) / 2;
        while (k < right && image[mid][k] == '0') ++k;
        if (k < right == opt) {
            j = mid;
        } else {
            i = mid + 1;
        }
    }
    return i;
}

// top = search row [0...x], find first row contain 1,
// bottom = search row[x+1, row], find first row contian all 0
// left = search col[0...y], find first col contain 1,
// right = search col[y+1, col], find first col contain all 0
int minArea(vector<vector<char>>& image, int x, int y) {
    if (image.empty() || image[0].empty()) return 0;
    int m = image.size(), n = image[0].size();
    int left = searchColumns(image, 0, y, 0, m, true);
    // here it should be n instead of n - 1, since it should be [left, right)
    int right = searchColumns(image, y + 1, n, 0, m, false);
    int top = searchRows(image, 0, x, 0, n, true);
    // here it should be m instead of m - 1, since it should be [top, bottom)
    int bottom = searchRows(image, x + 1, m, 0, n, false);
    return (right - left) * (bottom - top);
}

