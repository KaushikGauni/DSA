// Sum of Beauty of All Substrings
// https://leetcode.com/problems/sum-of-beauty-of-all-substrings/
// Accepted 2026-06-22 | Runtime 102 ms | Memory 11.3 MB

class Solution {
public:
    int beautySum(string s) {
        int total = 0;
        for(int i=0;i<s.size();i++){
            vector<int> freq(26,0);
            for(int j=i;j<s.size();j++){
                freq[s[j]-'a']++;

                int mx = INT_MIN;
                int mn = INT_MAX;

                for(int k=0;k<26;k++){
                    if(freq[k]>0){
                        mx = max(mx,freq[k]);
                        mn = min(mn,freq[k]);
                    }
                }

                total += mx - mn;
            }
        }

        return total;
    }

};