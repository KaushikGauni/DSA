// Alien Dictionary (Hard)
// https://www.geeksforgeeks.org/problems/alien-dictionary/1
// Correct 2026-10-08 11:15:06 | C++

class Solution {
  public:
    string findOrder(vector<string> &words) {
        // code here
        vector<vector<int>> adj(26);
        vector<int> indegree(26,0);
        vector<bool> present(26,false);
        
        int total = 0;
    
        for(string word : words){
            for(char c : word){
                if(!present[c-'a']) total++;
                present[c-'a'] = true;
            }
        }
        
        for(int i=1;i<words.size();i++){
            string word1 = words[i-1];
            string word2 = words[i];
            int j =0, len = min(word1.size(), word2.size());
            while(j < len && word1[j]==word2[j]){
                j++;
            }    
            
            if(j==len){
                if(word1.size() > word2.size()) return "";
                continue;
            }
                
            int u = word1[j] - 'a';
            int v = word2[j] - 'a';
                
            adj[u].push_back(v);
            indegree[v]++;
        }
        
        queue<int> q;
        
        for(int i=0;i<26;i++){
            if(present[i] && indegree[i]==0){
                q.push(i);
            }
        }
        
        string ans = "";
        
        while(!q.empty()){
            int node = q.front();
            q.pop();
            
            ans += char(node + 'a');
            
            for(int neigh : adj[node]){
                indegree[neigh]--;
                if(indegree[neigh]==0){
                    q.push(neigh);
                }
            }
        }
        
        if(ans.size() != total) return "";
        
        return ans;
    }
};