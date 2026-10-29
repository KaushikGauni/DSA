// Counting Bits
// https://leetcode.com/problems/counting-bits/
// Accepted 2025-11-26 | Runtime 0 ms | Memory 10.7 MB

class Solution {
public:

    int count(int n){
        int count = 0;
        while(n!=0){
            count += n&1;
            n = n >> 1;
        }
        return count;
    }
    vector<int> countBits(int n) {
        vector<int> res(n+1);
        for(int i=0;i<=n;i++){
            res[i] = count(i);
        }
        return res;
    }
};