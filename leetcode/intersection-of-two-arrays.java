// Intersection of Two Arrays
// https://leetcode.com/problems/intersection-of-two-arrays/
// Accepted 2023-07-03 | Runtime 2 ms | Memory 43.8 MB

class Solution {
    public int[] intersection(int[] nums1, int[] nums2) {
        HashSet<Integer> list1 = new HashSet<>();
        HashSet<Integer> list2 = new HashSet<>();
        for(int i : nums1){
            list1.add(i);
        }
        for(int i : nums2){
            list2.add(i);
        }
        HashSet<Integer> re = new HashSet<>(); 
        for(int i : nums1){
            if(list2.contains(i)){
                re.add(i);
            }
        }
        int j = 0;
        int[] res = new int[re.size()];
        for(int i : re){
            res[j++] = i; 
        }
        return res;
    }
}