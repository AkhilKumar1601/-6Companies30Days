#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int>> dist(n,vector<int>(n,1e9));

        for(auto it:edges) {
            dist[it[0]][it[1]] = it[2];
            dist[it[1]][it[0]] = it[2];
        }

        for(int i=0;i<n;i++) {
            dist[i][i] = 0;
        }


        for(int node = 0;node<n;node++) {
            for(int i=0;i<n;i++) {
                for(int j=0;j<n;j++) {
                    if(dist[i][node] == 1e9 || dist[node][j] == 1e9)
                        continue;

                    dist[i][j] = min(dist[i][j], dist[i][node]+dist[node][j]);
                }
            }
        }

        int cityMax = n;
        int cityNo = -1;

        for(int i=0;i<n;i++) {
            int count=0;
            for(int j=0;j<n;j++) {
                if(dist[i][j] <= distanceThreshold) {
                    count++;
                }
            }
            if(count <= cityMax) {
                cityMax = count;
                cityNo = i;
            }

        }

        return cityNo;
    }
};