// Capacity To Ship Packages Within D Days
// https://leetcode.com/problems/capacity-to-ship-packages-within-d-days/
// Accepted 2026-06-20 | Runtime 15 ms | Memory 34.9 MB

class Solution {
public:

    bool canShip(vector<int>& weights, int days, int mid){
        int daysneeded = 1;
        int currweight = 0;
        for(int i =0;i<weights.size();i++){
            if(currweight + weights[i] <= mid){
                currweight += weights[i];
            }
            else{
                daysneeded++;
                currweight = weights[i];
            }
        }

        return daysneeded <= days;
    }

    int shipWithinDays(vector<int>& weights, int days) {
        int low = *max_element(weights.begin(), weights.end()), high = accumulate(weights.begin(), weights.end(), 0);
        while(low<=high){
            int mid = low + (high - low) / 2;
            if(canShip(weights,days,mid)){
                high = mid - 1;
            }
            else{
                low = mid + 1;
            }
        }

        return low;
    }
};