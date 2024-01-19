#include<iostream>
#include<vector>
#include<queue>
#include<map>
#include<climits>
using namespace std;

class Solution {
public:
    int dist(int ax,int ay,int bx,int by) {
        return abs(ax-bx)+abs(ay-by);
    }

    int minimumCost(vector<int>& start, vector<int>& target, vector<vector<int>>& special) {
        int sx=start[0],sy=start[1],tx=target[0],ty=target[1];
        //Trick: In case the special roads does not lead to the target so explicitly add the target in the special roads
        special.push_back({tx,ty,tx,ty,0});
        
        //we need a queue of [x][y][cost]
        queue<pair<pair<int,int>,int>>q;
        q.push({{sx,sy},0});

        //unordered map tp store the distances
        map<pair<int, int>, int> mp;
        //store all the ending positions in the map and set them as Infinity
        for(auto it:special)
            mp[{it[2],it[3]}]=INT_MAX;
        mp[{tx,ty}]=dist(sx,sy,tx,ty);

        //implementg the Djikstra algorithm
        while(!q.empty()) {
            int curr_x=q.front().first.first;
            int curr_y=q.front().first.second;
            int curr_dist=q.front().second;
            q.pop();
            //Iterating over all the special roads and checking ehich special road leads to an index in the minimum cost
            
            for(auto it:special) {
                int st_x=it[0];
                int st_y=it[1];
                int end_x=it[2];
                int end_y=it[3];
                int special_dist=it[4];
                //calculating the manhatten distance from the current pos to the start of the special road
                int dist_to_start=dist(curr_x,curr_y,st_x,st_y);
                int total_dist=curr_dist+dist_to_start+special_dist;
                if(mp[{end_x,end_y}]>total_dist) {
                    mp[{end_x,end_y}]=total_dist;
                    q.push({{end_x,end_y},total_dist});
                }
            }
        }
        return mp[{tx,ty}];
    }
};