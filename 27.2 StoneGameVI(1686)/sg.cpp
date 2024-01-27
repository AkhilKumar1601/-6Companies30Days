#include<iostream>
#include<vector>
#include<queue>
using namespace std;

class mine{
    public:
    int sum;
    int index;
    mine(int s,int i){
        sum=s;
        index=i;
    }
};
class compare{
    public:
    bool operator()(mine*a,mine*b){
        return a->sum < b->sum;
    }
};


class Solution {
public:
    int stoneGameVI(vector<int>& aliceValues, vector<int>& bobValues) {
        int n=bobValues.size();
        priority_queue<mine*,vector<mine*>,compare>pq;
        for(int i=0;i<n;i++){
            mine*t=new mine(aliceValues[i]+bobValues[i],i);
            pq.push(t);
        }
        int alice=0,bob=0;
        bool turn_alice=true;
        while(!pq.empty()){
            auto fr=pq.top();
            pq.pop();
            if(turn_alice){
                alice+=aliceValues[fr->index];
            }
            else{
                bob+=bobValues[fr->index];
            }
            turn_alice=!turn_alice;
        }
        if(alice>bob){
            return 1;
        }
        else if(alice<bob){
            return -1;
        }
        return 0;
    }
};