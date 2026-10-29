// Smallest Window with All (Hard)
// https://www.geeksforgeeks.org/problems/smallest-window-in-a-string-containing-all-the-characters-of-another-string-1587115621/1
// Correct 2026-10-06 12:09:21 | C++

class Solution {
  public:
    string minWindow(string &s, string &p) {
        // code here
        unordered_map<char,int> hm;
        
        for(char c : p){
            hm[c]++;
        }
        
        int right = 0, left = 0, minLen = INT_MAX, start = 0;
        int required = p.size();
        
        for(right = 0; right<s.size();right++){
            if(hm[s[right]] > 0) required--;
            
            hm[s[right]]--;
            
            while(required == 0){
                if(right-left+1 < minLen){
                    minLen = right-left+1;
                    start = left;
                }
                
                hm[s[left]]++;
                
                if(hm[s[left]]>0) required++;
                
                left++;
            }
        }
        
        return minLen == INT_MAX ? "" : s.substr(start,minLen);
        
    }
};