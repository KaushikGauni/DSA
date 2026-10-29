// Kth Smallest Amount With Single Denomination Combination
// https://leetcode.com/problems/kth-smallest-amount-with-single-denomination-combination/
// Accepted 2026-08-21 | Runtime 119 ms | Memory 20.6 MB

class Solution {
public:

    long long gcd(long long a, long long b){
        while(b){
            long long temp = a % b;
            a = b;
            b = temp;
        }
        return a;
    }

    long long lcm(long long a, long long b){
        return a * b / gcd(a,b);
    }


    bool check(vector<int>&coins, int k, long long mid){
        int n = coins.size();
        long long count = 0;
        for(int mask=1;mask<(1<<n);mask++){
            long long L = 1;
            int bits = 0;
            for(int i=0;i<n;i++){
                if(mask & (1<<i)){
                    bits++;
                    L = lcm(L,coins[i]);

                    if(L > mid){
                        break;
                    }
                    
                }
            }

            if(L > mid){
                continue;
            }

            if(bits%2==1){
                count += mid / L;
            }
            else{
                count -= mid / L;
            }
        }

        return count >= k;
    }

    long long findKthSmallest(vector<int>& coins, int k) {
        long long low = 1;
        long long high = 1LL * *min_element(coins.begin(), coins.end()) * k;
        while(low < high){
            long long mid = low + (high - low) / 2;
            if(check(coins,k,mid)){
                high = mid;
            }
            else{
                low = mid + 1;
            }
        }

        return low;

    }
};