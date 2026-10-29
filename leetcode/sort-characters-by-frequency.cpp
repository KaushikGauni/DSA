// Sort Characters By Frequency
// https://leetcode.com/problems/sort-characters-by-frequency/
// Accepted 2026-06-22 | Runtime 0 ms | Memory 11.2 MB

class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char,int> hm;
        string res = "";
        for(char i : s){
            hm[i]++; 
        }
        vector<pair<int,char>> pairs;

        for(auto &a : hm){
            pairs.push_back({a.second,a.first});
        }

        sort(pairs.begin(), pairs.end(), greater<>());
        
        for(auto &a : pairs){
            res.append(a.first,a.second);
        }

        return res;
    }
};