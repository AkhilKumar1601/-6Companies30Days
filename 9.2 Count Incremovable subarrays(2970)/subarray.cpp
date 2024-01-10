#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    bool check(int start, int end, vector<int>& nums) {
        int prev = -1, curr = -1;
        for(int i = 0; i < nums.size(); i++) {
            if(i >= start && i <= end)continue;
            else{
                prev = curr;
                curr= nums[i];
            }

            if(prev >= curr) return false;
        }

        return true;
    }

    int incremovableSubarrayCount(vector<int>& nums) {
        int count = 0;
        int n = nums.size();
        if (n == 2) return 3;

        for (int i = 0; i < n; i++) {     // starting index i
            for (int j = i; j < n; j++) { // ending index j
                if (check(i, j, nums)) count++;
            }
        }

        return count++;
    }
};