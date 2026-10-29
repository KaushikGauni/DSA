// Valid Number
// https://leetcode.com/problems/valid-number/
// Accepted 2026-08-25 | Runtime 0 ms | Memory 8.2 MB

class Solution {
public:
    bool isNumber(string s) {
        bool seenDigit = false;
        bool seenDot = false; //AI
        bool seenExponent = false;

        for (int i = 0; i < s.length(); ++i) {
            char c = s[i];

            if (isdigit(c)) {
                seenDigit = true;
            } 
            else if (c == '+' || c == '-') {
                // A sign is only valid at the start or immediately after 'e'/'E'
                if (i > 0 && s[i - 1] != 'e' && s[i - 1] != 'E') {
                    return false;
                }
            } 
            else if (c == '.') {
                // Dot cannot appear twice or after an exponent
                if (seenDot || seenExponent) {
                    return false;
                }
                seenDot = true;
            } 
            else if (c == 'e' || c == 'E') {
                // Exponent cannot appear twice and must follow at least one digit
                if (seenExponent || !seenDigit) {
                    return false;
                }
                seenExponent = true;
                seenDigit = false; // Reset to require digits after exponent
            } 
            else {
                return false; // Any other character is invalid
            }
        }

        return seenDigit;
    }
};