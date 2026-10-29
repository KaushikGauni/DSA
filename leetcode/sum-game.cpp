// Sum Game
// https://leetcode.com/problems/sum-game/
// Accepted 2026-08-23 | Runtime 7 ms | Memory 14 MB

class Solution {
public:

    bool sumGame(string num) {
        int n = num.size();
        int sum1 = 0, sum2 = 0, q1 = 0, q2= 0;
        for(int i=0;i<n/2;i++){
            if(num[i]!='?'){
                sum1 += num[i] - '0';
            }
            else{
                q1++;
            }
        }
        for(int i=n/2;i<n;i++){
            if(num[i]!='?'){
                sum2 += num[i] - '0';
            }
            else{
                q2++;
            }
        }
        
        if(q1==q2){
            return sum1!=sum2;
        }

        return (sum1-sum2)*2 != (q2-q1)*9;

    }
};