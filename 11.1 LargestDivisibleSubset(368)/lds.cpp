#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& arr) {
        int n = arr.size();
        sort(arr.begin(),arr.end());
        vector<int>dp(n,1) , hash(n);
        int maxi = 1;
        int lastindex = 0;
        for(int i=0;i<n;i++){
            hash[i] = i;
            for(int j=0;j<i;j++){
                if(( arr[i] % arr[j] == 0 ) && ( 1+dp[j] > dp[i] ) ){
                    dp[i] = dp[j] + 1;
                    hash[i] = j;
                }
            }
            if(dp[i] > maxi){
                maxi = dp[i];
                lastindex = i;
            }
            
        }
        
        vector<int>temp;
        temp.push_back(arr[lastindex]);
        while(  lastindex !=  hash[lastindex] ){
            lastindex = hash[lastindex];
            temp.push_back(arr[lastindex]);
        }
        
        reverse(temp.begin(),temp.end());
        return temp;
        
        
    }
};