// Find Smallest Letter Greater Than Target
// https://leetcode.com/problems/find-smallest-letter-greater-than-target/
// Accepted 2023-06-24 | Runtime 0 ms | Memory 43.6 MB

class Solution {
    public char nextGreatestLetter(char[] letters, char target) {
        int mindiff = Integer.MAX_VALUE;
        char c = ' ';
        for(char letter : letters){
            if(letter-target<=0){
                continue;
            }
            if(letter-target<mindiff){
                mindiff = letter-target;
                c = letter;
            }
        }
        if(c==' '){
            return letters[0];
        }
        return c;
    }
}