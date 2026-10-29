// First and Last in Sorted (Medium)
// https://www.geeksforgeeks.org/problems/first-and-last-occurrences-of-x3116/1
// Correct 2022-09-21 20:20:45 | Java

//User function Template for Java


class GFG
{
    ArrayList<Long> find(long arr[], int n, int x)
    {
        // code here
        ArrayList<Long> list = new ArrayList<>();
        long start = -1;
        long end = -1;
        for(int i=0;i<n;i++){
            if(arr[i]==x){
                start = i;
                break;
            }
        }
        
        for(int i=n-1;i>=0;i--){
            if(arr[i]==x){
                end = i;
                break;
            }
        }
        
        list.add(start);
        list.add(end);
        return list;
    }
}


