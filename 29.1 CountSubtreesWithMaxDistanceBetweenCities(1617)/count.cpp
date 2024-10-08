#include<iostream>
#include<vector>
#include<unordered_map>
#include<climits>
using namespace std;

class Solution {
public:

    int dfs(int u,int par,vector<vector<int>> &adj,int &mask,int &ans){

              if(!(mask & (1<<u)))return 0; // if the current node is not present in the subset.

              mask = mask ^ (1<<u);

              int fmax = 0 , smax = 0;

              for(auto &v : adj[u]){
                  if(v == par)continue;

                  int val = dfs(v,u,adj,mask,ans);

                  if(val >= fmax){
                      smax = fmax;
                      fmax = val;
                  }
                  else if(val > smax){
                      smax = val;
                  }
              }

         ans = max(ans,fmax+smax); // calculating the maximum distance at each node.

         return fmax + 1;
    }

    vector<int> countSubgraphsForEachDiameter(int n, vector<vector<int>>& edges) {

             vector<vector<int>> adj(n+1);

             for(auto &it : edges){
                 int u = it[0] , v = it[1];
                 adj[u].push_back(v);
                 adj[v].push_back(u);
             }

             unordered_map<int,int> mp;
        
            for(int bit=1;bit<(1<<n);bit++){

                int mask = 0 , node = -1;
                
                for(int k=0;k<n;k++){
                     if(bit & (1<<k)){
                         mask |= (1<<(k+1));
                         node = k+1;
                     }
                }

                int ans = INT_MIN;

                dfs(node,-1,adj,mask,ans); // to determine whether or not our subset is connected, and to calculate the maximum distance
                
                if(mask == 0)mp[ans]++;
            }

            vector<int> ans;

            for(int i=1;i<n;i++){
                int val = mp[i];
                ans.push_back(val);
            }

        return ans;
    }
};