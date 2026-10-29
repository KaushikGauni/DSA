// Permutation in String
// https://leetcode.com/problems/permutation-in-string/
// Accepted 2026-08-10 | Runtime 0 ms | Memory 9.9 MB

class Solution {
public:

    bool equalVectors(vector<int> &arr1, vector<int> &arr2){
        for(int i=0;i<26;i++){
            if(arr1[i]!=arr2[i]){
                return false;
            }
        }
        return true;
    }

    bool checkInclusion(string s1, string s2) {
        vector<int> arr1(26,0);
        vector<int> arr2(26,0);
        int left = 0, right = 0;
        for(char c : s1){
            arr1[c-'a']++;
        }
        for(right=0;right<s2.size();right++){
            arr2[s2[right]-'a']++;

            while(right-left+1 > s1.size()){
                arr2[s2[left]-'a']--;
                left++;
            }

            if(right-left+1 == s1.size()){
                if(equalVectors(arr1,arr2)){
                    return true;
                }
            }
        }

        return false;
    }
};