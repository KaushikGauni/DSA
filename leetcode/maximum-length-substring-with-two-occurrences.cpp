// Maximum Length Substring With Two Occurrences
// https://leetcode.com/problems/maximum-length-substring-with-two-occurrences/
// Accepted 2026-08-18 | Runtime 3 ms | Memory 9.7 MB

class Solution {
public:
    int maximumLengthSubstring(string s) {
        int left = 0, right = 0, res = 0;
        unordered_map<char,int> hm;
        for(right = 0; right < s.size(); right++){
            hm[s[right]]++;

            while(hm[s[right]]>2){
                hm[s[left]]--;
                left++;
            }

            res = max(res, right-left+1);
        }

        return res;
    }
};