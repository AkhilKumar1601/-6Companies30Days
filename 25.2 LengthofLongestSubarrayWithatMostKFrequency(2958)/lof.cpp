#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        int ans = 0;

        int i = 0, j = 0;
        while(j < nums.size()) {
            mp[nums[j]]++;
            while(mp[nums[j]] > k) {
                mp[nums[i]]--;
                i++;
            }
            ans = max(ans,j-i+1);
            j++;
        }
        
        return ans;
    }
};
