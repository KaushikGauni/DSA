// Minimum Platforms (Medium)
// https://www.geeksforgeeks.org/problems/minimum-platforms-1587115620/1
// Correct 2026-08-05 14:27:48 | C++

class Solution {
  public:
    int minPlatform(vector<int>& arr, vector<int>& dep) {
        // code here
        sort(arr.begin(),arr.end());
        sort(dep.begin(), dep.end());
        int platforms = 0, maxi = 0;
        int i=0,j=0;
        while(i<arr.size() && j<dep.size()){
            if(arr[i]<=dep[j]){
                platforms++;
                maxi = max(maxi,platforms);
                i++;
            }
            else{
                platforms--;
                j++;
            }
        }
        return maxi;
    }
};
