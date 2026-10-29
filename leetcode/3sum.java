// 3Sum
// https://leetcode.com/problems/3sum/
// Accepted 2025-08-07 | Runtime 1412 ms | Memory 54.2 MB

class Solution {
    public List<List<Integer>> threeSum(int[] nums) {
        Set<List<Integer>> r = new HashSet<>();
        int n = nums.length;
        for(int i=0;i<n;i++){
            HashSet<Integer> hs = new HashSet<>();
            for(int j=i+1;j<n;j++){
                int num = -(nums[i]+nums[j]);
                if(hs.contains(num)){
                    ArrayList<Integer> ls = new ArrayList<>();
                    ls.add(nums[i]);
                    ls.add(nums[j]);
                    ls.add(num);
                    ls.sort(null);
                    r.add(ls);
                }
                hs.add(nums[j]);
            }
        }
        
        List<List<Integer>> res = new ArrayList<>(r);
        return res;
    }
}