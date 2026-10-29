// Next Greater Element I
// https://leetcode.com/problems/next-greater-element-i/
// Accepted 2026-10-14 | Runtime 1 ms | Memory 12.6 MB

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int> hm;
        stack<int> st;
        for(int i=nums2.size()-1;i>=0;i--){
            while(!st.empty() && st.top() <= nums2[i]) st.pop();
            if(st.empty()) hm[nums2[i]] = -1;
            else hm[nums2[i]] = st.top();
            st.push(nums2[i]);
        }

        for(int &i : nums1) i = hm[i];

        return nums1;
    }
};