// Array Subset (Basic)
// https://www.geeksforgeeks.org/problems/array-subset-of-another-array2317/1
// Correct 2022-09-24 19:53:08 | Java



//User function Template for Java


class Compute {
    public String isSubset( long a1[], long a2[], long n, long m) {
        ArrayList<Long> al = new ArrayList<>();
        for(int i=0;i<n;i++){
            al.add(a1[i]);
        }
        
        for(int i=0;i<m;i++){
            if(!al.contains(a2[i])){
                return "No";
            }
            al.remove(a2[i]);
        }
        
        return "Yes";
    }
}