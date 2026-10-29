// Course Schedule
// https://leetcode.com/problems/course-schedule/
// Accepted 2026-07-07 | Runtime 12 ms | Memory 20 MB

class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& nums) {
        vector<vector<int>> adj(numCourses);
        
        int n = nums.size();
        for(auto i : nums){
            adj[i[1]].push_back(i[0]);
        }

        vector<int> indegree(numCourses);

        for(int i=0;i<numCourses;i++){
            for(int neigh : adj[i]){
                indegree[neigh]++;
            }
        }
        queue<int> q;
        int count = 0;
        for(int i=0;i<numCourses;i++){
            if(indegree[i]==0){
                q.push(i);
            }
        }

        while(!q.empty()){
            int node = q.front();
            q.pop();
            count++;
            for(int neigh : adj[node]){
                indegree[neigh]--;
                if(indegree[neigh]==0){
                    q.push(neigh);
                }
            }
        }

        return count==numCourses;
    }
};