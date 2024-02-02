#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    bool check( vector<string>& wordDict, string& s) {
        for(auto i : wordDict){
            if(s == i) return true;
        }
        return false;
    }

    bool solveUsingRecursion(string &s, vector<string>& wordDict, int start) {
        if(start == s.size()) return true;

        bool flag = false;
        string word = "";
        for(int i = start; i < s.size(); i++) {
            word += s[i];
            if(check(wordDict,word)) {
               flag = flag || solveUsingRecursion(s,wordDict,i+1);
            }
        }

        return flag;
    }

    bool solveUsingMem(string &s, vector<string>& wordDict, int start, vector<int> &dp) {
        if(start == s.size()) return true;

        if(dp[start] != -1) return dp[start];

        bool flag = false;
        string word = "";
        for(int i = start; i < s.size(); i++) {
            word += s[i];
            if(check(wordDict,word)) {
               flag = flag || solveUsingMem(s,wordDict,i+1,dp);
            }
        }

        return dp[start] = flag;
    }

    bool solveUsingTabulation(string s, vector<string>& wordDict) {
        vector<bool> dp(s.size()+1,true);

        for(int start = s.size()-1; start >= 0; start--) {
            bool flag = false;
            string word = "";
            for(int i = start; i < s.size(); i++) {
                word.push_back(s[i]);      //word += s[i];
                if(check(wordDict,word)) {
                   flag = flag || dp[i+1];
                }
            }
            dp[start] = flag;
        }

        return dp[0];
    }

    bool wordBreak(string s, vector<string>& wordDict) {
        //vector<int> dp(s.size(),-1);
        return solveUsingTabulation(s,wordDict);
    }
};