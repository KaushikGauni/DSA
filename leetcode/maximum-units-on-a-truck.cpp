// Maximum Units on a Truck
// https://leetcode.com/problems/maximum-units-on-a-truck/
// Accepted 2025-10-09 | Runtime 153 ms | Memory 55.7 MB

class Solution {
public:
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        sort(boxTypes.begin(), boxTypes.end(), [](vector<int> a, vector<int> b){
            return a[1] > b[1];
        });
        int maxUnits = 0;
        for(auto i : boxTypes){
            
            maxUnits += i[1] * (min(i[0],truckSize));
            truckSize -= min(i[0],truckSize);
        }

        return maxUnits;
    }
};