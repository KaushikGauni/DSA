// Parenthesis Checker (Easy)
// https://www.geeksforgeeks.org/problems/parenthesis-checker2744/1
// Correct 2023-04-15 18:33:41 | Java




class Solution
{
    //Function to check if brackets are balanced or not.
    static boolean ispar(String x)
    {
        // add your code here
        int len = Integer.MAX_VALUE;
        while(len>x.length()){
            len = x.length();
            x = x.replace("{}","");
            x = x.replace("()","");
            x = x.replace("[]","");
        }
        if(x.length()>0){
            return false;
        }
        return true;
    }
}
