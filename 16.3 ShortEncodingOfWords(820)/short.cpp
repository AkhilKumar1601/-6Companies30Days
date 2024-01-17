#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    static bool cmp(string s1, string s2){
        return s1.size()>s2.size();
    }
    int minimumLengthEncoding(vector<string>& words) {
        sort(words.begin(), words.end(),cmp);
        string ans = "";
        for(auto a:words)
            if(ans.find(a+"#") == string::npos)  ans += (a + "#");
        return ans.size();
    }
};