// Scramble String
// https://leetcode.com/problems/scramble-string/
// Accepted 2026-08-25 | Runtime 11 ms | Memory 18.2 MB

class Solution {
public:
    unordered_map<string, bool> memo;
    bool isScramble(string s1, string s2) {
        if (s1 == s2) return true;
        
        string key = s1 + "_" + s2;
        if (memo.count(key)) return memo[key];

        int n = s1.length();

        // Pruning: Return false if character frequencies do not match
        vector<int> count(26, 0);
        for (int i = 0; i < n; i++) {
            count[s1[i] - 'a']++;
            count[s2[i] - 'a']--;
        }
        for (int c : count) {
            if (c != 0) return memo[key] = false;
        }

        // Try splitting s1 and s2 at every possible index i
        for (int i = 1; i < n; i++) {
            // Case 1: Without Swap
            bool withoutSwap = isScramble(s1.substr(0, i), s2.substr(0, i)) &&
                               isScramble(s1.substr(i), s2.substr(i));
            
            if (withoutSwap) return memo[key] = true;

            // Case 2: With Swap
            bool withSwap = isScramble(s1.substr(0, i), s2.substr(n - i)) &&
                            isScramble(s1.substr(i), s2.substr(0, n - i));

            if (withSwap) return memo[key] = true;
        }

        return memo[key] = false; //written by AI
    }
};