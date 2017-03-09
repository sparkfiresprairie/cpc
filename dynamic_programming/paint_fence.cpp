//
// Created by Xingyuan Wang on 3/8/17.
//

/*
    There is a fence with n posts, each post can be painted with one of the k colors.

    You have to paint all the posts such that no more than two adjacent fence posts
    have the same color.

    Return the total number of ways you can paint the fence.

    Note:
    n and k are non-negative integers.
 */

int numWays(int n, int k) {
    if (n == 0) return 0;
    if (n == 1) return k;
    int diff_color_count = k * (k - 1);
    int same_color_count = k;
    for (int i = 2; i < n; ++i) {
        int t = diff_color_count;
        diff_color_count = (diff_color_count + same_color_count) * (k - 1);
        same_color_count = t;
    }
    return diff_color_count + same_color_count;
}

// time: O(n)
// space: O(1)