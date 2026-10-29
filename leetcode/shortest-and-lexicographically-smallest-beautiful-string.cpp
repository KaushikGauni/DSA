// Shortest and Lexicographically Smallest Beautiful String
// https://leetcode.com/problems/shortest-and-lexicographically-smallest-beautiful-string/
// Accepted 2026-08-26 | Runtime 2 ms | Memory 8.7 MB

class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        string ans;
        int left = 0, right = 0, count = 0;
        for(right = 0;right<s.size();right++){
            if(s[right]=='1'){
                count++;
            }

            while(count > k){
                if(s[left]=='1'){
                    count--;
                }
                left++;
            }

            if(count == k){
                while(s[left]=='0'){
                    left++;
                }
                string sub = s.substr(left, right-left+1);
                if(ans=="" || sub.size()<ans.size() || (sub.size()==ans.size() && sub < ans)){
                    ans = sub;
                }
            }
        }
        
        return ans;
    }
};