// Digit Frequency Score
// https://leetcode.com/problems/digit-frequency-score/
// Accepted 2026-08-20 | Runtime 0 ms | Memory 8.7 MB

class Solution {
public:
    int digitFrequencyScore(int n) {
        vector<int> freq(10,0);
        while(n!=0){
            freq[n%10]++;
            n /= 10;
        }
        int res = 0;
        for(int i=0;i<10;i++){
            res += i * freq[i];
        }
        return res;
    }
};