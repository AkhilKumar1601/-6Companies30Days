#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        int n = nums.size();
        vector<pair<int,int>>vp;
        for(int i=0; i<n; i++){
            vp.push_back({nums[i],i});
        }
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        for(auto p:vp){
            pq.push(p);
            if(pq.size() > k) pq.pop();
        }
        vector<pair<int,int>>temp;
        while(!pq.empty()){
            temp.push_back({pq.top().second,pq.top().first});pq.pop();
        }
        sort(temp.begin(),temp.end());
        vector<int>ans;
        for(auto p:temp){
            ans.push_back(p.second);
        }
        return ans;
    }
};