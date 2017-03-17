//
// Created by Xingyuan Wang on 3/17/17.
//

/*
    Total Accepted: 27645
    Total Submissions: 94778
    Difficulty: Easy
    Contributors: Admin
    The API: int read4(char *buf) reads 4 characters at a time from a file.

    The return value is the actual number of characters read. For example, it returns
    3 if there is only 3 characters left in the file.

    By using the read4 API, implement the function int read(char *buf, int n) that
    reads n characters from the file.

    Note:
    The read function will only be called once for each test case.
 */

#include "String.h"

// Forward declaration of the read4 API.
int read4(char *buf);

/**
 * @param buf Destination buffer
 * @param n   Maximum number of characters to read
 * @return    The number of characters read
 */
int read(char *buf, int n) {
    bool eof = false;  // end of file flag
    int total = 0;      // total bytes read
    char* tmp = new char[4];
    while (!eof && total < n) {
        int count = read4(tmp);

        // check if it's the end of the file
        eof = count < 4;

        // get the actual count
        count = min(count, n - total);

        for (int i = 0; i < count; ++i) {
            buf[total++] = tmp[i];
        }
    }
    return total;
}
