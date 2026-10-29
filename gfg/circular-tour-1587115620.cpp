// Gas Station (Medium)
// https://www.geeksforgeeks.org/problems/circular-tour-1587115620/1
// Correct 2026-09-10 10:18:44 | C++

class Solution {
  public:
    int startStation(vector<int> &gas, vector<int> &cost) {
        //  code here
        int n = gas.size();
        int start = 0;
        int total = 0,tank = 0;
        
        for(int i=0;i<n;i++){
            int diff = gas[i] - cost[i];
            tank += diff;
            total += diff;
            
            if(tank < 0){
                start = i + 1;
                tank = 0;
            }
        }
        
        if(total < 0){
            return -1;
        }
        
        return start;
    }
};