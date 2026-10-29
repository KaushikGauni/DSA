// Number of Substrings Containing All Three Characters
// https://leetcode.com/problems/number-of-substrings-containing-all-three-characters/
// Accepted 2026-08-03 | Runtime 4 ms | Memory 11.1 MB

class Solution {
public:
    int numberOfSubstrings(string s) {
        vector<int> count(3,0);
        int res = 0;
        int left = 0, right = 0;
        for(right=0;right<s.size();right++){
            count[s[right]-'a']++;

            while(count[0] && count[1] && count[2]){
                count[s[left]-'a']--;
                left++;
            }

            res += left;
        }

        return res;
    }
};