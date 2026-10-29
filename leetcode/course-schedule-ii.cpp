// Course Schedule II
// https://leetcode.com/problems/course-schedule-ii/
// Accepted 2026-07-07 | Runtime 4 ms | Memory 19.1 MB

class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        for(auto i : prerequisites){
            adj[i[1]].push_back(i[0]);
        }
        vector<int> indegree(numCourses);
        vector<int> result;
        for(int i=0;i<numCourses;i++){
            for(int neigh : adj[i]){
                indegree[neigh]++;
            }
        }

        queue<int> q;

        for(int i=0;i<numCourses;i++){
            if(indegree[i]==0){
                q.push(i);
            }
        }

        while(!q.empty()){
            int node = q.front();
            q.pop();
            result.push_back(node);
            for(int neigh : adj[node]){
                indegree[neigh]--;
                if(indegree[neigh]==0){
                    q.push(neigh);
                }
            }
        }

        if(result.size()!=numCourses){
            return {};
        }

        return result;
    }
};