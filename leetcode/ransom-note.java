// Ransom Note
// https://leetcode.com/problems/ransom-note/
// Accepted 2025-08-11 | Runtime 6 ms | Memory 44.8 MB

class Solution {
    public boolean canConstruct(String ransomNote, String magazine) {
        HashMap<Character, Integer> hm = new HashMap<>();
        for(char c : ransomNote.toCharArray()){
            if(hm.containsKey(c)){
                hm.put(c,hm.get(c)+1);
            }
            else{
                hm.put(c,1);
            }
        }

        for(char c : magazine.toCharArray()){
            if(hm.containsKey(c)){
                if(hm.get(c)==1){
                    hm.remove(c);
                }
                else{
                    hm.put(c,hm.get(c)-1);
                }
            }
        }

        return hm.isEmpty();
    }
}