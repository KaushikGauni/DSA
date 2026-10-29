// Find Missing and Repeated Values
// https://leetcode.com/problems/find-missing-and-repeated-values/
// Accepted 2026-07-28 | Runtime 0 ms | Memory 26.6 MB

class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        int n = grid.size();
        long long N = n*n;
        long long expectedSum = N*(N+1)/2, expectedSoS = N*(N+1)*(2*N+1)/6;
        long long actualSum = 0, actualSoS = 0;
        for(auto arr : grid){
            for(int i : arr){
                actualSum += i;
                actualSoS += i*i;
            }
        }
        long long diff = actualSum - expectedSum; // x - y
        long long sum = (actualSoS - expectedSoS)/diff; // x + y

        long long repeated = (diff + sum) / 2;
        long long missing = sum - repeated;

        return {(int)repeated, (int)missing};
    }
};