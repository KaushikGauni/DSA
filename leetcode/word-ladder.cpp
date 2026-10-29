// Word Ladder
// https://leetcode.com/problems/word-ladder/
// Accepted 2026-10-07 | Runtime 39 ms | Memory 21.2 MB

class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> hs(wordList.begin(), wordList.end());

        if(!hs.count(endWord)) return 0;

        queue<pair<string,int>> q;
        q.push({beginWord,1});
        while(!q.empty()){
            string word = q.front().first;
            int dist = q.front().second;
            q.pop();

            if(word == endWord) return dist;

            for(int i =0;i<word.size();i++){
                char original = word[i];
                for(int j=0;j<26;j++){
                    word[i] = j + 'a';
                    if(hs.count(word)){
                        hs.erase(word);
                        q.push({word,dist+1});
                    }
                }
                word[i] = original;
            }
        }

        return 0;
    }
};