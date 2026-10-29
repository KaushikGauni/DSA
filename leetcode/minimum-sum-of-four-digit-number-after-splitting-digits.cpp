// Minimum Sum of Four Digit Number After Splitting Digits
// https://leetcode.com/problems/minimum-sum-of-four-digit-number-after-splitting-digits/
// Accepted 2025-10-09 | Runtime 0 ms | Memory 7.9 MB

class Solution {
public:
    int minimumSum(int num) {
        string s = to_string(num);
        sort(s.begin(), s.end());
        int minsum = 0;
        minsum = ((s[0]-'0') + (s[1]-'0')) * 10 + ((s[3]-'0') + (s[2]-'0'));
        return minsum;
    }
};