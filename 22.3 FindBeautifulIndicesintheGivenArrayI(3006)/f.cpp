#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    vector<int> beautifulIndices(string s, string a, string b, int k) {
        vector<int> ans, indices_a, indices_b;
        int x = s.size(), y = a.size(), z = b.size();
        
        for (int i = 0; i <= x - y; i++) {
            if (s.substr(i, y) == a) indices_a.push_back(i);
        }
    
        for (int j = 0; j <= x - z; j++) {
            if (s.substr(j, z) == b) indices_b.push_back(j);
        }
        
        for (int i = 0; i < indices_a.size(); i++) {
            for (int j = 0; j < indices_b.size(); j++) {
                if (abs(indices_a[i] - indices_b[j]) <= k) {
                    ans.push_back(indices_a[i]);
                    break;
                }
            }
        }
        
        sort(ans.begin(), ans.end());

        return ans;
    }
};