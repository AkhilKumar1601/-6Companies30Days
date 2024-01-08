#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> rect;
    int i=0;
    int x,y;
    Solution(vector<vector<int>>& rect) {
        this->rect=rect;
        x=rect[i][0];
        y=rect[i][1];
    }
    
    vector<int> pick() {
        vector<int>ans={x,y};
        x++;
        if(x>rect[i][2]){
            x=rect[i][0];
            y++;
        }
        if(y>rect[i][3]){
            if(i+1 < rect.size()){
                i++;
            }else{
                i=0;
            }
            x=rect[i][0];
            y=rect[i][1];
        }
        return ans; 
    }
};