#include<iostream>
#include<vector>
#include<cmath>
using namespace std;

class Solution {
private:
    int mod = pow(10,9) + 7;
    //Recursion + memoisation.
    int topDownApproach(int s, int e, int curr, int k, vector<vector<int>>& dp){
        //Base Case
        if(k == 0){
            if(curr == e) return 1;
            else return 0;
        }

        //Return ans from dp array is stored.
        if(dp[curr + 1001][k] != -1) return dp[curr + 1001][k];

        //Recursive call
        int movementToRight = topDownApproach(s,e,curr+1,k-1,dp) % mod;
        int movementToLeft = topDownApproach(s,e,curr-1,k-1,dp) % mod;

        //Store Ans in dp array.
        dp[curr + 1001][k] = (movementToRight + movementToLeft) % mod;

        return dp[curr + 1001][k];
    }
public:
    int numberOfWays(int startPos, int endPos, int k) {
        vector<vector<int>> dp(3001,vector<int>(1001,-1));  //Create Dp array.

        return topDownApproach(startPos,endPos,startPos,k,dp);
    }
};