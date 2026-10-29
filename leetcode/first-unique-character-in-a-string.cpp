// First Unique Character in a String
// https://leetcode.com/problems/first-unique-character-in-a-string/
// Accepted 2026-10-14 | Runtime 0 ms | Memory 14.5 MB

class Solution {
public:
    int firstUniqChar(string s) {
        vector<int> freq(26);
        for(int i=0;i<s.size();i++){
            freq[s[i]-'a']++;
        }

        for(int i=0;i<s.size();i++){
            if(freq[s[i]-'a'] == 1) return i;
        }

        return -1;
    }
};