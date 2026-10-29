// Find the Smallest Divisor Given a Threshold
// https://leetcode.com/problems/find-the-smallest-divisor-given-a-threshold/
// Accepted 2026-06-20 | Runtime 10 ms | Memory 26.2 MB

class Solution {
public:

    int summation(vector<int>& nums, int threshold, int mid){
        int sum = 0;
        for(int i=0;i<nums.size();i++){
            sum += ceil((double)nums[i]/(double)mid);
            if(sum>threshold){
                return sum;
            }
        }

        return sum;
    }

    int smallestDivisor(vector<int>& nums, int threshold) {
        int low = 1, high = *max_element(nums.begin(), nums.end());
        while(low <= high){
            int mid = low + (high - low) / 2;
            int sum = summation(nums,threshold,mid);
            if(sum<=threshold){
                high = mid - 1; 
            }
            else{
                low = mid + 1;
            }
        }

        return low;
    }
};