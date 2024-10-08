#include<iostream>
#include<queue>
using namespace std;

class Solution {
public:
    int findTheWinner(int n, int k) {
        queue<int>q;
        for(int i = 1; i <= n; i++) q.push(i);

        while(q.size() > 1){
            int count = k;
             while(count > 1){
                 int element = q.front();
                 q.pop();
                 q.push(element);
                 count--;
             } 
            q.pop();
        }
        return q.front();
    }
};