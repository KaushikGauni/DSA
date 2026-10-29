// Removing Stars From a String
// https://leetcode.com/problems/removing-stars-from-a-string/
// Accepted 2023-06-27 | Runtime 193 ms | Memory 45.2 MB

class Solution {
    public String removeStars(String s) {
        Stack<Character> stack = new Stack<>();
        for(int i=0;i<s.length();i++){
            if(s.charAt(i)!='*'){
                stack.push(s.charAt(i));
            }
            else{
                stack.pop();
            }
        }
        StringBuilder st = new StringBuilder();
        while(!stack.isEmpty()){
            st.append(stack.pop());
        }
        return st.reverse().toString();
    }
}