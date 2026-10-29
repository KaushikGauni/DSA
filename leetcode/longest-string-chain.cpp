// Longest String Chain
// https://leetcode.com/problems/longest-string-chain/
// Accepted 2026-07-25 | Runtime 1884 ms | Memory 640.4 MB

class Solution {
public:

    bool isPredec(string word1, string word2){
        if(word1.size() != word2.size()+1){
            return false;
        }
        int i=0, j=0;
        while(i<word1.size()){
            if(j<word2.size() && word1[i]==word2[j]){
                i++;
                j++;
            }
            else{
                i++;
            }
        }

        return j==word2.size();
    }

    int longestStrChain(vector<string>& words) {
        int n = words.size();
        sort(words.begin(), words.end(), [](auto &a, auto &b){
            return a.size() < b.size();
        });
        vector<int> dp(n,1);
        int ans = 1;
        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++){
                if(isPredec(words[i],words[j])==1){
                    dp[i] = max(dp[i],1+dp[j]);
                }
            }
            ans = max(ans,dp[i]);
        }

        return ans;
    }
};