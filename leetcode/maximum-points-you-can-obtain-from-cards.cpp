// Maximum Points You Can Obtain from Cards
// https://leetcode.com/problems/maximum-points-you-can-obtain-from-cards/
// Accepted 2026-08-03 | Runtime 0 ms | Memory 46.2 MB

class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size();

        int total = accumulate(cardPoints.begin(), cardPoints.end(), 0);

        if(n==k){
            return total;
        }

        int window = n-k;
        int curr = 0;
        for(int i=0;i<window;i++){
            curr += cardPoints[i];
        }
        int mini = curr;
        for(int i=window;i<n;i++){
            curr += cardPoints[i];
            curr -= cardPoints[i-window];
            mini = min(mini,curr);
        }

        return total - mini;
    }
};