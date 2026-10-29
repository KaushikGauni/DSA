// Job Sequencing Problem (Medium)
// https://www.geeksforgeeks.org/problems/job-sequencing-problem-1587115620/1
// Correct 2026-08-25 11:01:55 | C++

class Solution {
  public:
  
    int find(int x, vector<int> &parent){
        if(x==parent[x]){
            return x;
        }
        return parent[x] = find(parent[x],parent);
    }
  
    vector<int> jobSequencing(vector<int> &deadline, vector<int> &profit) {
        // code here
        vector<pair<int,int>> jobs;
        for(int i=0;i<deadline.size();i++){
            jobs.push_back({deadline[i],profit[i]});
        }
        
        sort(jobs.begin(), jobs.end(), [](auto &a, auto &b){
            return a.second > b.second;
        });
        
        
        int maxDeadLine = *max_element(deadline.begin(), deadline.end());
        
        vector<int> parent(maxDeadLine+1);
        for(int i=0;i<=maxDeadLine;i++){
            parent[i] = i;
        }
        
        int count = 0, maxProfit = 0;
        
        unordered_map<int,int> deadlines;
        for(int i=0;i<jobs.size();i++){
            int dead = jobs[i].first;
            int prof = jobs[i].second;
            
            int slot = find(dead,parent);
            
            if(slot > 0){
                count++;
                maxProfit += prof;
                
                parent[slot] = find(slot - 1, parent);
            }
        }
        
        return {count,maxProfit};
        
    }
};