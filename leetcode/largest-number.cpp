// Largest Number
// https://leetcode.com/problems/largest-number/
// Accepted 2026-09-22 | Runtime 4 ms | Memory 17.2 MB

class Solution {
public:
    struct Compare{
        bool operator()(string a, string b){
            return a+b > b+a;
        }
    };


    string largestNumber(vector<int>& nums) {
        vector<string> arr;
        for(int i : nums){
            arr.push_back(to_string(i));
        }
        sort(arr.begin(), arr.end(), Compare());

        if(arr[0]=="0"){
            return "0";
        }

        string res = "";

        for(string i : arr){
            res += i;
        }

        return res;
    }
};