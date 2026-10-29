// Count Types of Characters (Basic)
// https://www.geeksforgeeks.org/problems/count-type-of-characters3635/1
// Correct 2022-10-15 17:52:51 | Java



//User function Template for Java

class Sol
{
    int[] count (String s)
    {
        // your code here
        int[] count = new int[4];
        for(int i=0;i<s.length();i++){
            char t = s.charAt(i);
            if(t>='A' && t<='Z'){
                count[0]++;
            }
            else if(t>='a' && t<='z'){
                count[1]++;
            }
            else if(Character.getNumericValue(t)>=0 && Character.getNumericValue(t)<=9){
                count[2]++;
            }
            else{
                count[3]++;
            }
        }
        
        return count;
    }
}