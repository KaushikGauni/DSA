// Kth Largest Element in a Stream
// https://leetcode.com/problems/kth-largest-element-in-a-stream/
// Accepted 2025-12-24 | Runtime 0 ms | Memory 33.2 MB

class KthLargest {
public:
    priority_queue<int, vector<int>, greater<int>> pq;
    int K;
    KthLargest(int k, vector<int>& nums) {
        K = k;
        for(int i : nums){
            pq.push(i);
            if(pq.size()>k){
                pq.pop();
            }
        }
    }
    
    int add(int val) {
        pq.push(val);
        if(pq.size()>K){
            pq.pop();
        }
        return pq.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */