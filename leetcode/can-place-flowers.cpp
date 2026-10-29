// Can Place Flowers
// https://leetcode.com/problems/can-place-flowers/
// Accepted 2025-10-06 | Runtime 4 ms | Memory 24.1 MB

class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int count = 0;
        for(int i=0;i<flowerbed.size();i++){
            if(i==0){
                if(flowerbed[i]==0 && flowerbed.size()==1){
                    count++;
                    flowerbed[i] = 1;
                }    
                else if(flowerbed[i]==0 && flowerbed[i+1]==0){
                    flowerbed[i] = 1;
                    count++;
                }    
            }
            else if(i==flowerbed.size()-1){
                if(flowerbed[i]==0 && flowerbed[i-1]==0){
                    flowerbed[i] = 1;
                    count++;
                }    
            }
            else if(flowerbed[i]==0 && flowerbed[i-1]==0 && flowerbed[i+1]==0){
                flowerbed[i] = 1;
                count++;
            }
        }
        return count>=n;
    }
};