// Range Sum Query - Immutable
// https://leetcode.com/problems/range-sum-query-immutable/
// Accepted 2026-10-05 | Runtime 0 ms | Memory 24.1 MB

class NumArray {
public:
    vector<int> arr;
    NumArray(vector<int>& nums) {
        arr.push_back(0);
        for(int i : nums){
            arr.push_back(i + arr.back());
        }
    }
    
    int sumRange(int left, int right) {
        return arr[right+1] - arr[left];
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */