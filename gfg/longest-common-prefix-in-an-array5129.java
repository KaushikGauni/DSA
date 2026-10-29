// Longest Common Prefix of Strings (Easy)
// https://www.geeksforgeeks.org/problems/longest-common-prefix-in-an-array5129/1
// Correct 2022-09-25 18:43:00 | Java



//User function Template for Java

class Solution{
    String longestCommonPrefix(String arr[], int n){
        // code here
        Arrays.sort(arr);
        int flag = 0;
        String first = arr[0];
        String last = arr[n-1];
        String res="";
        int i=0,j=0;
        while(i<first.length() && j<last.length()){
            if(first.charAt(i)!=last.charAt(j)){
                break;
            }
            res = res + first.charAt(i);
            i++;
            j++;
        }
        
        if(res.equals("")){
            return "-1";
        }
        
        return res;
    }
}