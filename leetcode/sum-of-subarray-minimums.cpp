// Sum of Subarray Minimums
// https://leetcode.com/problems/sum-of-subarray-minimums/
// Accepted 2026-09-24 | Runtime 72 ms | Memory 193.3 MB

class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        const int MOD = 1e9+7;
        int n = arr.size();
        stack<int> st;
        vector<int> prev(n);
        vector<int> next(n);

        for(int i=0;i<n;i++){
            while(!st.empty() && arr[st.top()]>arr[i]){
                st.pop();
            }
            prev[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }

        while(!st.empty()){
            st.pop();
        }

        for(int i=n-1;i>=0;i--){
            while(!st.empty() && arr[st.top()] >= arr[i]){
                st.pop();
            }
            next[i] = st.empty() ? n : st.top();
            st.push(i);
        }
        long long res = 0;
        for(int i=0;i<n;i++){
            long long left = i - prev[i];
            long long right = next[i] - i;
            res = (res + arr[i] * left % MOD * right) % MOD;
        }

        return res;
    }
};