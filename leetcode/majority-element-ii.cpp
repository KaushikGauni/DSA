// Majority Element II
// https://leetcode.com/problems/majority-element-ii/
// Accepted 2026-06-12 | Runtime 0 ms | Memory 23.6 MB

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int res1=-1, res2=-1;
        int count1 = 0, count2 = 0;

        for(int i: nums){
            if(res1==i){
                count1++;
            }
            else if(res2==i){
                count2++;
            }
            else if(count1==0){
                res1 = i;
                count1++;
            }
            else if(count2==0){
                res2 = i;
                count2++;
            }
            else{
                count1--;
                count2--;
            }
        }
        int cnt1 = 0, cnt2=0;
        for(int i: nums){
            if(i==res1)cnt1++;
            else if(i==res2)cnt2++;
        }


        vector<int> res;
        if(cnt1>nums.size()/3){
            res.push_back(res1);
        }
        if(cnt2>nums.size()/3){
            res.push_back(res2);
        }

        return res;
    }
};