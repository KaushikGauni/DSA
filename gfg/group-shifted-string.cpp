// Group Shifted String (Medium)
// https://www.geeksforgeeks.org/problems/group-shifted-string/1
// Correct 2026-09-17 16:56:05 | C++


class Solution {
  public:
    vector<vector<string>> groupShiftedString(vector<string> &arr) {
        // Your code here
        vector<string> temp = arr;
        for(auto &str : temp){
            char first = str[0];
            for(int i=0;i<str.size();i++){
                str[i] = str[i] - first + 'a';
            
                if(str[i]<'a'){
                    str[i] += 26;
                }
            }
        }
        
        unordered_map<string,vector<string>> hm;
        
        for(int i=0;i<arr.size();i++){
            hm[temp[i]].push_back(arr[i]);    
        }
        
        vector<vector<string>> res;
        
        for(auto a : hm){
            res.push_back(a.second);
        }
        
        return res;
    }
};