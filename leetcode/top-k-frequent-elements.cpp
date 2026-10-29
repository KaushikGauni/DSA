// Top K Frequent Elements
// https://leetcode.com/problems/top-k-frequent-elements/
// Accepted 2026-09-16 | Runtime 4 ms | Memory 18 MB

class Solution {
public:

    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> hm;
        for(int i : nums){
            hm[i]++;
        }
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        for(auto a : hm){
            pq.push({a.second,a.first});
            if(pq.size() > k){
                pq.pop();
            }
        }

        vector<int> res;

        while(!pq.empty()){
            res.push_back(pq.top().second);
            pq.pop();
        }

        return res;
    }
};