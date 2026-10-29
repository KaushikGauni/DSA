// Minimum Window Substring
// https://leetcode.com/problems/minimum-window-substring/
// Accepted 2026-08-25 | Runtime 4 ms | Memory 11.4 MB

class Solution {
public:
    string minWindow(string s, string t) {
        vector<int> count(128, 0);
        for (char c : t) count[c]++;
        
        int required = t.length();
        int minLen = INT_MAX, start = 0;
        int left = 0, right = 0;
        
        while (right < s.length()) {
            if (count[s[right]] > 0) required--;
            count[s[right]]--;
            right++;
            
            // Try to shrink the window from the left when all characters are matched
            while (required == 0) {
                if (right - left < minLen) {
                    minLen = right - left;
                    start = left;
                }
                
                count[s[left]]++;
                if (count[s[left]] > 0) required++;
                left++;
            }
        }
        
        return minLen == INT_MAX ? "" : s.substr(start, minLen); //written by AI
    }
};