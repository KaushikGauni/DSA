// Triplets with Smaller Sum (Medium)
// https://www.geeksforgeeks.org/problems/count-triplets-with-sum-smaller-than-x5549/1
// Correct 2026-09-22 16:00:42 | C++

class Solution {
  public:
    int countTriplets(int sum, vector<int>& arr) {
        // code here
        sort(arr.begin(), arr.end());
        int n = arr.size();
        int res = 0, count = 0;
        for(int i=0;i<n-2;i++){
            int left = i+1;
            int right = n-1;
            
            while(left < right){
                int res = arr[i] + arr[left] + arr[right];
                
                if(res < sum){
                    count += right - left;
                    left++;
                }
                else{
                    right--;
                }
            }
        }
        
        return count;
    }
};