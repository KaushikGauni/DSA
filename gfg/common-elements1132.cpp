// Common in 3 Sorted (Easy)
// https://www.geeksforgeeks.org/problems/common-elements1132/1
// Correct 2026-09-22 15:17:03 | C++

class Solution {
  public:
    vector<int> commonElements(vector<int> &a, vector<int> &b, vector<int> &c) {
        // code here
        int i = 0, j= 0, k = 0;
        
        vector<int> res;
        
        while(i< a.size() && j<b.size() && k<c.size()){
            if(a[i]==b[j] && b[j]==c[k]){
                if(res.empty() || res.back()!=a[i])
                res.push_back(a[i]);
                i++;
                j++;
                k++;
                continue;
            }
            if(a[i]<b[j]) i++;
            else if(b[j]<c[k]) j++;
            else k++;
        }
        
        
        return res;
    }
};