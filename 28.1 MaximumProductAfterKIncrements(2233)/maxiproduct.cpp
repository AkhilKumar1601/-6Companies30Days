#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    int maximumProduct(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        long long ans = 1;
        while(k){
            int min = nums[0];
            for(int i =0;i<nums.size();++i) {
                if(nums[i]==min&&k) {
                    nums[i]++;
                    k--;
                }
                else break;
            } 
        }
        
        for(int i =0;i<nums.size();++i) {
            ans*=nums[i];
            ans%=(1000000007);
        }

        return int(ans);
    }
};