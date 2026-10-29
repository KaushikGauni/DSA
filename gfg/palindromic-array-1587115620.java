// Array with All Palindromes (Basic)
// https://www.geeksforgeeks.org/problems/palindromic-array-1587115620/1
// Correct 2022-09-21 19:50:47 | Java



/*Complete the Function below*/
class GfG
{
	public static int palinArray(int[] a, int n)
           {
                  //add code here.
                  int flag = 1;
                  for(int i=0;i<a.length;i++){
                      if(!isPalindrome(a[i])){
                          return 0;
                      }
                  }
                  
                  return 1;
           }
           
    public static boolean isPalindrome(int num){
        int temp = num;
        int rev = 0;
        while(temp!=0){
            rev = rev*10 + temp%10;
            temp = temp/10;
        }
        
        if(rev==num){
            return true;
        }
        
        return false;
    }       
}