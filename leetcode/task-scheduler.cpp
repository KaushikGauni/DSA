// Task Scheduler
// https://leetcode.com/problems/task-scheduler/
// Accepted 2026-08-23 | Runtime 1 ms | Memory 38.3 MB

class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> freq(26,0);
        int count = 0;
        for(char c : tasks){
            freq[c-'A']++;
            count = max(count, freq[c-'A']);
        }
        int ans = (count-1) * (n+1);
        for(int i : freq){
            if(i==count){
                ans++;
            }
        }

        return max((int)tasks.size(),ans);
    }
};