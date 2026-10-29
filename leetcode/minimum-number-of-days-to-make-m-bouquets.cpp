// Minimum Number of Days to Make m Bouquets
// https://leetcode.com/problems/minimum-number-of-days-to-make-m-bouquets/
// Accepted 2026-06-20 | Runtime 23 ms | Memory 70.4 MB

class Solution {
public:
    bool possible(int mid, vector<int>& bloomDay, int m, int k){
        int temp = k;
        for(int i=0;i<bloomDay.size();i++){
            if(bloomDay[i]<=mid){
                temp--;
            }
            else{
                temp = k;
            }
            if(temp==0){
                m--;
                temp = k;
                if(m==0){
                    return true;
                }
            }
        }

        return m==0;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        if((long long)m*k > bloomDay.size()){
            return - 1;
        }
        int low = *min_element(bloomDay.begin(), bloomDay.end());
        int high = *max_element(bloomDay.begin(), bloomDay.end());
        while(low<=high){
            int mid = low + (high - low) / 2;
            if(possible(mid,bloomDay,m,k)){
                high = mid - 1;
            }
            else{
                low = mid + 1;
            }
        }

        return low;
    }
};