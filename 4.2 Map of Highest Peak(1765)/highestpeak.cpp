#include<iostream>
#include<vector>
#include<queue>
using namespace std;

class Solution {
public:
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        int n = isWater.size(), m = isWater[0].size();

        vector<vector<int>> ans(n,vector<int>(m,-1));
        queue<pair<int,int>>q;

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(isWater[i][j]){
                    ans[i][j] = 0;
                    q.push({i,j});
                }
            }
        }

        while(!q.empty()){
            auto a = q.front(); q.pop();
            int x = a.first, y = a.second;
            int v = ans[x][y];
            vector<int> temp = {-1,0,1,0,-1};
            for(int i = 0; i < temp.size() - 1; i++){
                if((x + temp[i] >= 0) && (x + temp[i] < n) && (y + temp[i + 1] < m) && y + temp[i + 1] >= 0){
                    if(ans[x + temp[i]][y + temp[i + 1]] == -1){
                        ans[x + temp[i]][y + temp[i + 1]] = v + 1;
                        q.push({x + temp[i], y + temp[i + 1]});
                    }
                }
            }
        }

        return ans;
    }
};