#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

class Solution {
public:
    bool asteroidsDestroyed(int mass, vector<int>& asteroids) {
        sort(asteroids.begin(),asteroids.end());
        long long mass1= mass;
        for (int i=0; i<asteroids.size(); i++){
            if (mass1>=asteroids[i])  mass1+= asteroids[i];
            else return 0;
        }
        return 1;
    }
};