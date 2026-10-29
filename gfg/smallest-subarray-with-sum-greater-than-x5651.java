// Smallest Subarray Sum Greater Than x (Easy)
// https://www.geeksforgeeks.org/problems/smallest-subarray-with-sum-greater-than-x5651/1
// Correct 2022-09-25 19:36:58 | Java



//User function Template for Java


class Solution {

    public static int smallestSubWithSum(int a[], int n, int x) {
        // Your code goes here 
        int curr_sum = 0, min_len = n + 1;

        // Initialize starting and ending indexes
        int start = 0, end = 0;
        while (end < n) {
            // Keep adding array elements while current sum
            // is smaller than or equal to x
            while (curr_sum <= x && end < n)
                curr_sum += a[end++];

            // If current sum becomes greater than x.
            while (curr_sum > x && start < n) {
                // Update minimum length if needed
                if (end - start < min_len)
                    min_len = end - start;

                // remove starting elements
                curr_sum -= a[start++];
            }
        }
        return min_len;
    }
}

