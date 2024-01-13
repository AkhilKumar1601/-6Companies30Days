#include<iostream>
#include<vector>
#include<math.h>
#include<unordered_map>
using namespace std;

class Solution {
public:

    long long mod = 1e9+7; 

    long long solve(int i,long long mask,vector<int>& nums,unordered_map<int,int>& mem,vector<vector<long long>>& dp){

        if(i>nums.size()-1) return 0 ;

        if(dp[i][mask]!=-1) return dp[i][mask];

        int notPick = solve(i+1,mask,nums,mem,dp);

        // it is not possible to pick if it contain square element as factor 
        for(int j=2;j<=sqrt(nums[i]);j++){          
            if(nums[i]%(j*j)==0) return dp[i][mask] = notPick ;
        }

        // it is not possible to pick if its factor is already picked
        for(int j=0;j<10;j++){
            int k = mem[j] ,isSet= (mask&(1<<j)); 
            if(nums[i]%k==0 && isSet) return dp[i][mask] = notPick ; 
        }

        long long prev = mask; 

        // set new mask 
        for(auto j:mem){
            if(nums[i]%j.second==0) mask^=(1<<j.first);
        }

        int pick = 1+solve(i+1,mask,nums,mem,dp);

        return dp[i][prev]= (pick+notPick)%mod; 

    }

    int squareFreeSubsets(vector<int>& nums) {
        
        unordered_map<int,int> mem ;

        vector<int> visited(31);

        vector<vector<long long>> dp(nums.size()+1,vector<long long>((1<<10)+1,-1));

        int count =0 ;

        for(int i=2;i<30;i++){

            if(visited[i]) continue ;

            for(int j=2*i;j<30;j+=i) visited[j] = true ;
            
            mem[count++] = i ;
    
        }

        return solve(0,0,nums,mem,dp);

    }
};