// Counting Sort (Easy)
// https://www.geeksforgeeks.org/problems/counting-sort/1
// Correct 2026-09-22 15:08:41 | C++

class Solution {
  public:
    string countSort(string s) {
        // code here
        vector<int> count(26,0);
        for(char c : s){
            count[c-'a']++;
        }
        
        string res = "";
        
        for(int i=0;i<26;i++){
            while(count[i]>0){
                res += (i+'a');
                count[i]--;
            }
        }
        
        return res;
    }
};