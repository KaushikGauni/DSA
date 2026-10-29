// Distribute Elements Into Two Arrays I
// https://leetcode.com/problems/distribute-elements-into-two-arrays-i/
// Accepted 2026-08-20 | Runtime 3 ms | Memory 23.6 MB

class Solution {
public:
    vector<int> resultArray(vector<int>& nums) {
        int k = 2, i = 0, j = 0;
        vector<int> arr1;
        vector<int> arr2;
        arr1.push_back(nums[0]);
        arr2.push_back(nums[1]);
        while(k<nums.size()){
            if(arr1[i]>arr2[j]){
                arr1.push_back(nums[k]);
                i++;
            }
            else{
                arr2.push_back(nums[k]);
                j++;
            }
            k++;
        }
        for(int i : arr2){
            arr1.push_back(i);
        }

        return arr1;
    }
};