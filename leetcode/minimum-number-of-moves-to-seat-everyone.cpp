// Minimum Number of Moves to Seat Everyone
// https://leetcode.com/problems/minimum-number-of-moves-to-seat-everyone/
// Accepted 2025-10-09 | Runtime 0 ms | Memory 21.8 MB

class Solution {
public:
    int minMovesToSeat(vector<int>& seats, vector<int>& students) {
        int moves = 0;
        sort(seats.begin(), seats.end());
        sort(students.begin(), students.end());
        for(int i=0;i<seats.size();i++){
            moves += abs(seats[i]-students[i]);
        }

        return moves;
    }
};