// Longest Repeating Character Replacement
// https://leetcode.com/problems/longest-repeating-character-replacement/
// Accepted 2026-08-12 | Runtime 1 ms | Memory 10.9 MB

class Solution {
public:
    int characterReplacement(string s, int k) {
        int left = 0, right = 0, res = 0;
        int maxFreq = 0;
        unordered_map<char,int> hm;
        for(right=0;right<s.size();right++){
            hm[s[right]]++;
            maxFreq = max(maxFreq, hm[s[right]]);

            while(right-left+1-maxFreq > k){
                hm[s[left]]--;
                left++;
            }

            res = max(res,right-left+1);
        }   

        return res;
    }
};