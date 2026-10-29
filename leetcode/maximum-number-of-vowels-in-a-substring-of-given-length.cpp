// Maximum Number of Vowels in a Substring of Given Length
// https://leetcode.com/problems/maximum-number-of-vowels-in-a-substring-of-given-length/
// Accepted 2026-08-01 | Runtime 15 ms | Memory 13.2 MB

class Solution {
public:
    unordered_set<char> vowels = {'a','e','i','o','u'};
    int maxVowels(string s, int k) {
        int left =0, right = 0;
        int vowelCount = 0,maxVowelCount = 0;
        for(right = 0;right<s.size();right++){
            if(vowels.count(s[right])){
                vowelCount++;
            }

            while(right-left+1>k){
                if(vowels.count(s[left])){
                    vowelCount--;
                }
                left++;
            }

            if(right-left+1==k){
                maxVowelCount = max(maxVowelCount, vowelCount);
            }
        }

        return maxVowelCount;
    }
};