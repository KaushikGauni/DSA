# Find Minimum Operations to Make All Elements Divisible by Three
# https://leetcode.com/problems/find-minimum-operations-to-make-all-elements-divisible-by-three/
# Accepted 2026-08-20 | Runtime 0 ms | Memory 19.1 MB

class Solution:
    def minimumOperations(self, nums: List[int]) -> int:
        res = 0
        for i in nums:
            if i%3!=0:
                res += 1
        return res
        