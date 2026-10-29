// Asteroid Collision
// https://leetcode.com/problems/asteroid-collision/
// Accepted 2026-09-24 | Runtime 3 ms | Memory 22.1 MB

class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> st;
        for(int i : asteroids){
            if(st.empty()){
                st.push(i);
            }
            else if(st.top()>0 && i<0){
                while(!st.empty() && st.top()<abs(i) && st.top()>0){
                    st.pop();
                }
                if(st.empty() || st.top()<0){
                    st.push(i);
                }
                else if(st.top() == abs(i)){
                    st.pop();
                }
            }
            else{
                st.push(i);
            }
        }

        vector<int> res;
        while(!st.empty()){
            res.push_back(st.top());
            st.pop();
        }

        reverse(res.begin(), res.end());

        return res;
    }
};