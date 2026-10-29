// Lemonade Change
// https://leetcode.com/problems/lemonade-change/
// Accepted 2026-06-26 | Runtime 0 ms | Memory 87.2 MB

class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int fives = 0;
        int tens = 0;
        for(int bill : bills){
            if(bill==5){
                fives++;
            }
            else if(bill==10){
                if(fives>=1){
                    fives--;
                    tens++;
                }
                else{
                    return false;
                }
            }
            else if(bill=20){
                if((tens>=1 && fives>=1)){
                    tens--;
                    fives--;
                }
                else if(fives>=3){
                    fives -= 3;
                }
                else{
                    return false;
                }
            }
        }

        return true;
    }
};