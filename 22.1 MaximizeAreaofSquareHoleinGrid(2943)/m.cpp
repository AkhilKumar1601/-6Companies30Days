#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
using namespace std;

class Solution {
public:
    int findMaxConsecutiveBars(vector<int>& nums){
        unordered_map<int, int> mpp;
        int maxLen = 1;
        for(auto it: nums){
            if(mpp.find(it-1) != mpp.end()){
                mpp[it] = mpp[it-1] + 1;
                maxLen = max(mpp[it], maxLen);
            }
            else mpp[it] = 1;
        }
        return maxLen;
    }
    int maximizeSquareHoleArea(int n, int m, vector<int>& hBars, vector<int>& vBars) {
        //Sort the arrays to keep bars in increasing order.
        sort(hBars.begin(), hBars.end());
        sort(vBars.begin(), vBars.end());
        
        // Find maxLen, maxWidth
        int maxLen = findMaxConsecutiveBars(hBars);
        int maxWidth = findMaxConsecutiveBars(vBars);
        
        // Find minLength that can form square
        int dimensions = min(maxLen, maxWidth) + 1;
        return dimensions*dimensions;
    }
};