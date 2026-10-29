// Next Greater Element II
// https://leetcode.com/problems/next-greater-element-ii/
// Accepted 2026-06-25 | Runtime 3 ms | Memory 28.5 MB

class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        vector<int> res(n,-1);
        stack<int> st;
        for(int i=2*n-1;i>=0;i--){
            int j = i%n;
            while(!st.empty() && st.top() <= nums[j]){
                st.pop();
            }

            if(st.empty()){
                res[j] = -1;
            }

            else{
                res[j] = st.top();
            }

            st.push(nums[j]);
        }

        return res;
    }
};