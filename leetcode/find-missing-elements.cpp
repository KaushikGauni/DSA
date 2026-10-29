// Find Missing Elements
// https://leetcode.com/problems/find-missing-elements/
// Accepted 2026-08-10 | Runtime 0 ms | Memory 32.3 MB

class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        vector<bool> visit(101,false);
        vector<int> res;
        int smallest = INT_MAX, largest = INT_MIN;
        for(int i=0;i<nums.size();i++){
            visit[nums[i]] = true;
            smallest = min(smallest, nums[i]);
            largest = max(largest, nums[i]);
        }
        for(int i=smallest;i<=largest;i++){
            if(!visit[i]){
                res.push_back(i);
            }
        }
        return res;
    }
};