// Majority Element (Medium)
// https://www.geeksforgeeks.org/problems/majority-element-1587115620/1
// Correct 2026-09-22 15:43:06 | C++

class Solution {
  public:
    int majorityElement(vector<int>& arr) {
        // code here
        int count = 0, candidate = -1;
        for(int i : arr){
            if(count==0){
                candidate = i;
            }
            
            if(candidate == i){
                count++;
            }
            else{
                count--;
            }
        }
        
        count = 0;
        
        for(int i : arr){
            if(i == candidate){
                count++;
            }
        }
        
        
        return count>arr.size()/2 ? candidate : -1;
    }
};