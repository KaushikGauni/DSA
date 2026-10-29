// Kth Largest Element in an Array
// https://leetcode.com/problems/kth-largest-element-in-an-array/
// Accepted 2026-09-19 | Runtime 31 ms | Memory 72.6 MB

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int>> pq;
        for(int i : nums){
            pq.push(i);
            if(pq.size() > k){
                pq.pop();
            }
        }

        return pq.top();
    }
};