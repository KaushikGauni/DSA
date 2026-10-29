// Fruit Into Baskets
// https://leetcode.com/problems/fruit-into-baskets/
// Accepted 2026-08-01 | Runtime 31 ms | Memory 85 MB

class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int left = 0, right = 0, count = 0;
        unordered_map<int,int> fs;
        while(right<fruits.size()){
            fs[fruits[right]]++;
            while(fs.size()>2){
                fs[fruits[left]]--;
                if(fs[fruits[left]]==0){
                    fs.erase(fruits[left]);
                }
                left++;
            }
            count = max(count, right-left+1);
            right++;
        }

        return count;
    }
};