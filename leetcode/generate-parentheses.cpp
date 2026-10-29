// Generate Parentheses
// https://leetcode.com/problems/generate-parentheses/
// Accepted 2026-06-23 | Runtime 3 ms | Memory 15.6 MB

class Solution {
public:
    void generate(int n, int left, int right, vector<string> &res, string curr){
        if(left==right && curr.length()==n*2){
            res.push_back(curr);
            return;
        }
        if(left>0){
            generate(n,left-1, right, res, curr+"(");
        }
        if(right>left){
            generate(n,left,right-1, res, curr+")");
        }


    }
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        generate(n, n, n, res, "");
        return res;
    }
};