#include<iostream>
using namespace std;

class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        int ans = 0, c = maxCost, i = 0, j = 0;

        for(int j=0; j<s.size(); j++) {
            c -= abs(s[j] - t[j]);
            if(c >= 0) ans = max(ans, j - i + 1);
            else c += abs(s[i] - t[i]), i++;
        }
        return ans;
    }
};