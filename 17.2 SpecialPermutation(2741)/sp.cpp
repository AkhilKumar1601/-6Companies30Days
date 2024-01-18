#include<iostream>
#include<vector>
#include<math.h>
using namespace std;

class Solution {
    private:
    int mod = 1e9+7;
    // mask will work as visited array, in which we mark the bit if we have visited that bit.
    // pre will be previously choosen element if any.
    int fun( int pre , vector<int>&v , int mask, vector<vector<int>> &dp)
    {
        int n = v.size();
        if( mask == pow(2, n) -1) { return 1;}
        if(pre >= n ) return 0;
        if( dp[pre][mask] != -1) return dp[pre][mask];
        long ans = 0;
        for( int j = 0 ; j< n; j++)
        {
            if(( (1<<j)&mask) != 0 ) continue;
             if((1<<pre)&mask &&  v[pre]%v[j] != 0 && v[j]%v[pre] != 0 ) continue;
            
            int newmask = mask |(1<<j);
            ans += fun(j, v, newmask, dp);
            ans%= mod;
        }
        return dp[pre][mask] = ans;
    }
    
    public:
    int specialPerm(vector<int>& nums) {
        
        // At first i started with LCM approach but later on i found it isn't intutive 
        // long long lcm = 1;
        // for(auto&i:nums) lcm*=i;
        // nums.insert( nums.begin(), lcm);

        int n = nums.size();
        vector<vector<int>> dp(n +1, vector<int>( 1<<n , -1));
        return fun( 0 , nums, 0, dp);
    }
};