// Longest Substring Without Repeating Characters
// https://leetcode.com/problems/longest-substring-without-repeating-characters/
// Accepted 2026-09-22 | Runtime 51 ms | Memory 19.3 MB

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int left = 0, right = 0, maxLength = 0;
        unordered_map<char,int> hm;
        for(right = 0;right < s.size();right++){
            hm[s[right]]++;

            while(hm[s[right]]>1){
                hm[s[left]]--;
                left++;
            }

            maxLength = max(maxLength, right - left + 1);
        }

        return maxLength;
    }
};