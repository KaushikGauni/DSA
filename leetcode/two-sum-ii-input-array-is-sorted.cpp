// Two Sum II - Input Array Is Sorted
// https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/
// Accepted 2025-12-18 | Runtime 0 ms | Memory 19.6 MB

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int i = 0, j = numbers.size()-1;
        while(i<=j){
            if(numbers[i]+numbers[j]>target){
                j--;
            }
            else if(numbers[i]+numbers[j]<target){
                i++;
            }
            else{
                return {i+1,j+1};
            }
        }
        return {};
    }
};