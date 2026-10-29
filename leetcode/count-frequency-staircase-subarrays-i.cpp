// Count Frequency Staircase Subarrays I
// https://leetcode.com/problems/count-frequency-staircase-subarrays-i/
// Accepted 2026-10-29 | Runtime 1032 ms | Memory 397.4 MB

class Solution {
public:
    int countStaircase(vector<int>& nums) {
        int n = nums.size(), answer = 0;
        for (int left = 0; left < n; ++left) {
            unordered_map<int, pair<int, int>> state;
            int distinct = 0, incomplete = 0;
            for (int right = left; right < n; ++right) {
                auto it = state.find(nums[right]);
                if (it == state.end()) {
                    it = state.emplace(nums[right],
                        make_pair(++distinct, 0)).first;
                    ++incomplete;
                }
                int rank = it->second.first;
                int& frequency = it->second.second;
                ++frequency;
                // An excessive frequency cannot be fixed.
                if (frequency > rank) break;
                if (frequency == rank) --incomplete;
                if (incomplete == 0) ++answer;
            }
        }
        return answer;
    }
};