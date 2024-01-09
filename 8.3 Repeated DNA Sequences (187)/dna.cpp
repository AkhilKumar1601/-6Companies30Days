#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        vector<string> ans;
        if(s.size() <= 10) return ans;

        unordered_map<string, int>mp;
        for(int i = 0; i <= s.size()-10; i++){
            if(mp[s.substr(i,10)]++ == 1) ans.push_back(s.substr(i,10));
        }
    
        return ans;
    }
};