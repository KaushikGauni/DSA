// Cinema Seat Allocation
// https://leetcode.com/problems/cinema-seat-allocation/
// Accepted 2026-08-19 | Runtime 63 ms | Memory 76.8 MB

class Solution {
public:

    int help(vector<int> &row){
        bool left = true, mid = true, right = true;
        for(int i=2;i<=5;i++){
            if(row[i]==1){
                left = false;
                break;
            }
        }
        for(int i=4;i<=7;i++){
            if(row[i]==1){
                mid = false;
                break;
            }
        }
        for(int i=6;i<=9;i++){
            if(row[i]==1){
                right = false;
                break;
            }
        }
        if(left && right){
            return 2;
        }
        if(left || right || mid){
            return 1;
        }
        return 0;
    }

    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        unordered_map<int,vector<int>> hm;
        for(auto seats : reservedSeats){
            if(!hm.count(seats[0])){
                hm[seats[0]] = vector<int>(11,0);
            }
            hm[seats[0]][seats[1]] = 1;
        }
        int res = 2 * (n - hm.size());
        
        for(auto& [numRow, row] : hm){
            res += help(row);
        }

        return res;
    }
};