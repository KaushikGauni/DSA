// Check if Numbers Are Ascending in a Sentence
// https://leetcode.com/problems/check-if-numbers-are-ascending-in-a-sentence/
// Accepted 2023-06-21 | Runtime 17 ms | Memory 44.9 MB

class Solution {
    public boolean areNumbersAscending(String s) {
        ArrayList<Integer> list = new ArrayList<>();
        String[] arr = s.split(" ");
        for(String temp:arr){
            if(temp.matches("-?(0|[1-9]\\d*)")){
                list.add(Integer.parseInt(temp));
            }
        }
        for(int i=0;i<list.size()-1;i++){
            if(!(list.get(i)<list.get(i+1))){
                return false;
            }
        }
        return true;
    }
}