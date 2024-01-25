#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

class Solution {
public:
    long mod = 1e9 + 7;
    vector<int> demo;
    unordered_map<int,int> mp;
    unordered_map<int,int> freq;
    // modular exponentition
    long long power(long long x, unsigned int y, int p) {
        long long res = 1;  
        x = x % p; 
        if (x == 0) return 0; 
        while (y > 0) {
            if (y & 1) res = (res*x) % p;
            y = y>>1;
            x = (x*x) % p;
        }
        return res;
    }

    int solve(int idx, int bitmask) {
        if(idx == demo.size()){
            if(bitmask > 0) return 1;
            return 0;
        }
        
        // dont take 
        long  not_take = solve(idx+1, bitmask);
        long  take = 0;
        // take 
        if((demo[idx]&bitmask) == 0) take = (long)solve(idx+1, bitmask|demo[idx])*(long)freq[demo[idx]];
        
        return (take + not_take)%mod;
    }

    int numberOfGoodSubsets(vector<int>& nums) {
        // as nums[i] <= 30
        vector<int> primes = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29};
        
        int n = primes.size();
        for(auto i:nums) mp[i]++;
        int ones = 0;
        for(auto i:mp) {
            int x = i.first;
            int y = i.second;
            int mask = 0;
            if(x == 1) ones = y;
            else {
                for(int j = 0; j<n; j++) {
                    if(x%primes[j] == 0) {
                        x = x/primes[j];
                        mask = mask|(1<<j);
                    }
                    if(x%primes[j] == 0 || x == 1) break;
                }
                if(x == 1) {
                    demo.push_back(mask);
                    freq[mask] = y;
                }
            }
        }
        return power(2, ones, mod)%mod*solve(0, 0)%mod;
    }
};