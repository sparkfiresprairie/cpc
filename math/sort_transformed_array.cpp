//
// Created by Xingyuan Wang on 3/17/17.
//

/*
    Given a sorted array of integers nums and integer values a, b and c. Apply a function
    of the form f(x) = ax2 + bx + c to each element x in the array.

    The returned array must be in sorted order.

    Expected time complexity: O(n)

    Example:
    nums = [-4, -2, 2, 4], a = 1, b = 3, c = 5,

    Result: [3, 9, 15, 33]

    nums = [-4, -2, 2, 4], a = -1, b = 3, c = 5

    Result: [-23, -5, 1, 7]
 */

int trans(int x, int a, int b, int c) {
    return a * x * x + b * x + c;
}

vector<int> sortTransformedArray(vector<int>& nums, int a, int b, int c) {
    int n = nums.size();
    vector<int> ans(n, 0);
    int i = 0, j = n - 1;
    int k = a >= 0 ? n - 1 : 0;
    while (i <= j) {
        if (a >= 0) {
            ans[k--] = trans(nums[i], a, b, c) >= trans(nums[j], a, b, c) ? trans(nums[i++], a, b, c) : trans(nums[j--], a, b, c);
        } else {
            ans[k++] = trans(nums[i], a, b, c) >= trans(nums[j], a, b, c) ? trans(nums[j--], a, b, c) : trans(nums[i++], a, b, c);
        }
    }
    return ans;
}

