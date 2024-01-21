#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int getLastMoment(int n, vector<int>& left, vector<int>& right) {
        int ans = 0;

        // Iterate through the 'left' vector and find the maximum position.
        for (int i = 0; i < left.size(); i++) {
            ans = max(ans, left[i]);
        }

        // Iterate through the 'right' vector and find the maximum position.
        for (int i = 0; i < right.size(); i++) {
            ans = max(ans, n - right[i]);
        }
        return ans;
    }
};