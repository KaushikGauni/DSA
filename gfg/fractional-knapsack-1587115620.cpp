// Fractional Knapsack (Easy)
// https://www.geeksforgeeks.org/problems/fractional-knapsack-1587115620/1
// Correct 2026-10-07 11:27:18 | C++

class Solution {
  public:
    double fractionalKnapsack(vector<int>& val, vector<int>& wt, int capacity) {
        // code here
        vector<pair<double,int>> weights;
        for(int i=0;i<val.size();i++){
            double ratio = val[i] * 1.0 / wt[i] * 1.0;
            weights.push_back({ratio,i});
        }
        
        sort(weights.begin(), weights.end(), [](auto a, auto b){
            return a.first > b.first;
        });
        
        double profit = 0;
        
        for(auto item : weights){
            int i = item.second;
            if(wt[i] <= capacity){
                profit += val[i];
                capacity -= wt[i];
            }
            else{
                profit += ((double) capacity / wt[i]) * val[i];
                break;
            }
        }
        
        return profit;
    }
};
