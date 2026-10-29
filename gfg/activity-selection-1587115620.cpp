// Activity Selection (Medium)
// https://www.geeksforgeeks.org/problems/activity-selection-1587115620/1
// Correct 2026-10-07 10:43:08 | C++

class Solution {
  public:
    int activitySelection(vector<int> &start, vector<int> &finish) {
        // code here
        vector<pair<int,int>> acts;
        for(int i =0;i<start.size();i++){
            acts.push_back({finish[i],start[i]});
        }
        
        sort(acts.begin(), acts.end());
        
        int last = acts[0].first;
        int res = 1;
        for(int i=1;i<start.size();i++){
            if(acts[i].second > last){
                res++;
                last = acts[i].first;
            }
        }
        
        
        return res;
    }
};