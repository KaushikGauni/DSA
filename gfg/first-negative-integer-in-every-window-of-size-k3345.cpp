// First Negative in Windows of Size K (Medium)
// https://www.geeksforgeeks.org/problems/first-negative-integer-in-every-window-of-size-k3345/1
// Correct 2022-09-27 20:18:25 | C++



vector<long long> printFirstNegativeInteger(long long int A[],
                                             long long int N, long long int K) {
                                    vector<long long> ans;
    int i=0, j=0;
    queue<int> q;
    while(j<N) {
        if(A[j]<0) q.push(A[j]);
        if(j-i+1<K) j++;
        else if(j-i+1==K) {
            if(q.empty()) ans.push_back(0);
            else ans.push_back(q.front());
            if(A[i]==q.front()) q.pop();
            i++; j++;
        }
    }
    return ans;             
 }