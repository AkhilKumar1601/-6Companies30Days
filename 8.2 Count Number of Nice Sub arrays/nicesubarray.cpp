#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        vector<int> v;
        int count = 0;
        for(auto i : nums){
            if(i % 2 == 0) count++;
            else{
                v.push_back(count);
                count = 0;
            }
        }
        v.push_back(count);

        int i = 0, ans = 0;
        while(i + k < v.size()){
            ans += (v[i] + 1) * (v[i+k] + 1);  //sliding window
            i++;
        }

        return ans;
    }
};