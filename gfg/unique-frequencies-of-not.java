// Distinct Frequencies Check (Easy)
// https://www.geeksforgeeks.org/problems/unique-frequencies-of-not/1
// Correct 2023-07-13 21:22:03 | Java




class Solution {
    public static boolean isFrequencyUnique(int n, int[] arr) {
        // code here
        HashMap<Integer, Integer> hm = new HashMap<>();
        HashSet<Integer> hs = new HashSet<>();
        for(int i=0;i<n;i++){
            if(hm.containsKey(arr[i])){
                hm.put(arr[i],hm.get(arr[i])+1);
            }
            else{
                hm.put(arr[i],1);
            }
        }
        for(Map.Entry<Integer,Integer> entry : hm.entrySet()){
                hs.add(entry.getValue());
        }
        if(hs.size()!=hm.size()){
            return false;
        }
        return true;
    }
}
        
