// Find the Difference of Two Arrays
// https://leetcode.com/problems/find-the-difference-of-two-arrays/
// Accepted 2023-07-03 | Runtime 15 ms | Memory 44.9 MB

class Solution {
    public List<List<Integer>> findDifference(int[] nums1, int[] nums2) {
        HashSet<Integer> list1 = new HashSet<>();
        HashSet<Integer> list2 = new HashSet<>();
        HashSet<Integer> hs1 = new HashSet<>();
        HashSet<Integer> hs2 = new HashSet<>();
        for(int num:nums1){
            hs1.add(num);
        }
        for(int num:nums2){
            hs2.add(num);
        }
        for(int num:nums1){
            if(!hs2.contains(num)){
                list1.add(num);
            }
        }
        for(int num:nums2){
            if(!hs1.contains(num)){
                list2.add(num);
            }
        }
        List<List<Integer>> list = new ArrayList<>();
        list.add(new ArrayList<Integer>(list1));
        list.add(new ArrayList<Integer>(list2));
        return list;
    }
}