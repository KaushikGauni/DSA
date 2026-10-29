// K Closest in Sorted Array (Medium)
// https://www.geeksforgeeks.org/problems/k-closest-elements3619/1
// Correct 2026-09-16 15:52:15 | C++

class Solution {
  public:
  
    struct Compare{
        bool operator()(pair<int,int> &a, pair<int,int> &b){
            if(a.first == b.first){
                return a.second > b.second;
            }
            return a.first < b.first;
        }  
    };
  
    vector<int> findKClosest(vector<int> arr, int k, int x) {
        // Code here
        priority_queue<pair<int,int>, vector<pair<int,int>>, Compare> pq;
        for(int i : arr){
            if(i==x){
                continue;
            }
            pq.push({abs(x-i),i});
            if(pq.size() > k){
                pq.pop();
            }
        }
        
        vector<int> res(pq.size());
        int i = pq.size() - 1;
        while(!pq.empty()){
            res[i--] = pq.top().second;
            pq.pop();
        }
        
        return res;
    }
};