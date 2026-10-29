// Daily Temperatures
// https://leetcode.com/problems/daily-temperatures/
// Accepted 2026-06-25 | Runtime 33 ms | Memory 107.3 MB

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> result(temperatures.size(),0);
        stack<int> indices;
        for(int i=0;i<temperatures.size();i++){
            while(!indices.empty() && temperatures[i] > temperatures[indices.top()]){
                result[indices.top()] = i - indices.top();
                indices.pop();
            }
            indices.push(i);
        }
        return result;
    }
};