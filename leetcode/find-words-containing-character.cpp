// Find Words Containing Character
// https://leetcode.com/problems/find-words-containing-character/
// Accepted 2025-11-03 | Runtime 0 ms | Memory 33 MB

class Solution {
public:
    vector<int> findWordsContaining(vector<string>& words, char x) {
        vector<int> res;
        for(int i=0;i<words.size();i++){
            if(find(words[i].begin(), words[i].end(), x)!=words[i].end()){
                res.push_back(i);
            }
        }
        return res;
    }
};