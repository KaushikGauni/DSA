// Stock Buy and Sell (Medium)
// https://www.geeksforgeeks.org/problems/stock-buy-and-sell-1587115621/1
// Correct 2022-10-12 20:46:46 | Java



//User function Template for Java

class Solution{
    //Function to find the days of buying and selling stock for max profit.
    ArrayList<ArrayList<Integer> > stockBuySell(int A[], int n) {
        // code here
        ArrayList<ArrayList<Integer>> profits = new ArrayList<>();
        for(int i=1;i<n;i++){
            if(A[i]>A[i-1]){
                ArrayList<Integer> temp = new ArrayList<>();
                temp.add(i-1);
                temp.add(i);
                profits.add(temp);
            }
        }
        
        return profits;
    }
}
