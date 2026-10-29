// Most Frequent in a Limited Range Array (Easy)
// https://www.geeksforgeeks.org/problems/maximum-repeating-number4858/1
// Correct 2026-09-16 15:05:57 | C++

class Solution {
  public:
  
    int maxRepeating(int k, vector<int>& arr) {
        // code here
        vector<int> freq(k);
        
        for(int i : arr){
            freq[i]++;
        }
        
        int maxFreq = 0, result = k;
        
        for(int i =0;i<k;i++){
            if(freq[i] > maxFreq || (freq[i] == maxFreq && i < result)){
                maxFreq = freq[i];
                result = i;
            }
        }
        
        return result;
    }
};