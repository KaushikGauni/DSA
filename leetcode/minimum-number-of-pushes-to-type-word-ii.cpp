// Minimum Number of Pushes to Type Word II
// https://leetcode.com/problems/minimum-number-of-pushes-to-type-word-ii/
// Accepted 2026-08-01 | Runtime 15 ms | Memory 25.4 MB

class Solution {
public:
    int minimumPushes(string word) {
        vector<int> freq(26,0);
        for(char ch : word){
            freq[ch-'a']++;
        }
        
        sort(freq.begin(), freq.end(), greater<>());

        int cost = 0;

        for(int i=0;i<26;i++){
            if(freq[i]==0){
                break;
            }
            cost += freq[i] * (i/8 + 1);
        }

        return cost;

    }
};