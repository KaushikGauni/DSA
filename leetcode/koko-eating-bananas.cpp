// Koko Eating Bananas
// https://leetcode.com/problems/koko-eating-bananas/
// Accepted 2026-06-20 | Runtime 9 ms | Memory 22.8 MB

class Solution {
public:

    bool canEat(vector<int>& piles, int h, int mid){
        int hours = 0;
        for(int i=0;i<piles.size();i++){
            hours += (piles[i] + mid - 1) / mid; //to future me :  ceil operation integer style w/o using ceil and double conversions...
            if(hours>h){
                return false;
            }
        }

        return true;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int low = 1, high = *max_element(piles.begin(),piles.end());
        while(low<=high){
            int mid = low + (high - low) / 2;
            if(canEat(piles,h,mid)){
                high = mid - 1;
            }
            else{
                low = mid + 1;
            }
        }

        return low;
    }
};