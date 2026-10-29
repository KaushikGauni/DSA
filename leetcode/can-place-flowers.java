// Can Place Flowers
// https://leetcode.com/problems/can-place-flowers/
// Accepted 2023-06-27 | Runtime 1 ms | Memory 44.2 MB

class Solution {
    public boolean canPlaceFlowers(int[] flowerbed, int n) {
        if(n==0){
            return true;
        }
        for(int i=0;i<flowerbed.length;i++){
            if(flowerbed[i] == 0 && (i==0 || flowerbed[i-1]==0) && (i==flowerbed.length-1 || flowerbed[i+1] == 0)){
                flowerbed[i] = 1;
                n--;
                if(n==0){
                    return true;
                }
            }
        }
        return false;
    }
}