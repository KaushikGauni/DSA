// Reverse Words (Easy)
// https://www.geeksforgeeks.org/problems/reverse-words-in-a-given-string5459/1
// Correct 2023-06-03 16:51:59 | Java




class Solution 
{
    //Function to reverse words in a given string.
    String reverseWords(String S)
    {
        // code here 
        String[] words = S.split("[.]");
        StringBuilder result = new StringBuilder();
        for(int i=words.length-1;i>=0;i--){
            result.append(words[i]);
            result.append(".");
        }
        result.deleteCharAt(S.length());
        return result.toString();
    }
}