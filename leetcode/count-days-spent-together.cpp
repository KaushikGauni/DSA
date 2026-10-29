// Count Days Spent Together
// https://leetcode.com/problems/count-days-spent-together/
// Accepted 2026-10-24 | Runtime 1 ms | Memory 7.8 MB

class Solution {
public:

    int day(string &date){
        int days[] = {31,28,31,30,31,30,31,31,30,31,30,31};
        int month = stoi(date.substr(0,2));
        int day = stoi(date.substr(3,2));
        for(int i=0;i<month-1;i++){
            day += days[i];
        }
        return day;
    }

    int countDaysTogether(string arriveAlice, string leaveAlice, string arriveBob, string leaveBob) {
        int start = max(day(arriveAlice), day(arriveBob));
        int end = min(day(leaveAlice), day(leaveBob));
        return max(0,end - start+1);
    }
};