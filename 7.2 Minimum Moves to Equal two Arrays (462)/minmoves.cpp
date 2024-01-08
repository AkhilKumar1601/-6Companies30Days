#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    int minMoves2(vector<int>& nums) {
        int n = nums.size(), ans = 0;
        sort(nums.begin(),nums.end());
        for(int i = 0; i < n; i++){
            ans += abs(nums[i] - nums[n/2]);
        }
        return ans;
    }
};