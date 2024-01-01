#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    vector<int> smallestTrimmedNumbers(vector<string>& nums, vector<vector<int>>& queries) {
        vector<int> ans;
        for(auto it : queries){
            vector<pair<string,int>> v;
            for(int i = 0; i < nums.size(); i++){
                string trimmedVal = nums[i].substr(nums[i].size() - it[1]);  
                v.push_back({trimmedVal,i});
            }
            sort(v.begin(),v.end());
            int k = it[0] - 1;
            int originalIndexOfTrimmedVal = v[k].second;
            ans.push_back(originalIndexOfTrimmedVal);
        }

        return ans;
    }
};