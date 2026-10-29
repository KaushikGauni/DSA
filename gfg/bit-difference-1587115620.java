// Bit Difference (Easy)
// https://www.geeksforgeeks.org/problems/bit-difference-1587115620/1
// Correct 2026-09-03 16:34:41 | Java

class Solution {
    public static int countBitsFlip(int a, int b) {
        // code here
        int diff = a ^ b;
        int count = 0;
        while(diff>0){
            count += diff&1;
            diff = diff >> 1;
        }
        
        return count;
    }
}
