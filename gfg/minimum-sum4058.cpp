// Min Sum Pair using Digits (Medium)
// https://www.geeksforgeeks.org/problems/minimum-sum4058/1
// Correct 2026-10-07 10:59:23 | C++

class Solution {
  public:
  
    string addStrings(string num1, string num2){
        int i = num1.size() - 1;
        int j = num2.size() - 1;
        
        int carry = 0;
        
        string res = "";
        
        while(i>=0 || j>=0 || carry){
            int sum = carry;
            
            if(i>=0) sum += num1[i--] - '0';
            if(j>=0) sum += num2[j--] - '0';
            
            res += char((sum%10) + '0');
            carry = sum / 10;
        }
        
        reverse(res.begin(), res.end());
        
        int k = 0;
        
        while(k < res.size()-1 && res[k]=='0'){
            k++;
        }
        
        return res.substr(k);
    }
  
    string minSum(vector<int> &arr) {
        // code here
        sort(arr.begin(), arr.end());
        string num1 = "", num2 = "";
        
        for(int i=0;i<arr.size();i++){
            if(i%2==0){
                num1 += char(arr[i] + '0');
            }
            else{
                num2 += char(arr[i] + '0');
            }
        }
        
        return addStrings(num1,num2);
    }
};