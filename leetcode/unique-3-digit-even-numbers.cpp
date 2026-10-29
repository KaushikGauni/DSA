// Unique 3-Digit Even Numbers
// https://leetcode.com/problems/unique-3-digit-even-numbers/
// Accepted 2026-09-11 | Runtime 15 ms | Memory 30.8 MB

class Solution {
public:
    int totalNumbers(vector<int>& digits) {
        set<int> nums;
        int n = digits.size();
        for(int i=0;i<n;i++){
            if(digits[i]==0) continue;

            for(int j=0;j<n;j++){
                if(i==j) continue;

                for(int k=0;k<n;k++){
                    if(i==k || k==j) continue;

                    if(digits[k]%2!=0) continue;

                    int num = digits[i]*100 + digits[j]*10 + digits[k];
                    nums.insert(num);
                }
            }
        }

        return nums.size();

    }
};