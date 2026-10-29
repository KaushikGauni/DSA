// Kids With the Greatest Number of Candies
// https://leetcode.com/problems/kids-with-the-greatest-number-of-candies/
// Accepted 2023-06-27 | Runtime 0 ms | Memory 41.7 MB

class Solution {
    public List<Boolean> kidsWithCandies(int[] candies, int extraCandies) {
        List<Boolean> arr = new ArrayList<>();
        int max = Integer.MIN_VALUE;
        for(int i=0;i<candies.length;i++){
            if(candies[i]>max){
                max = candies[i];
            }
        }
        for(int i=0;i<candies.length;i++){
            if(candies[i]+extraCandies>=max){
                arr.add(true);
            }
            else{
                arr.add(false);
            }
        }
        return arr;
    }
}