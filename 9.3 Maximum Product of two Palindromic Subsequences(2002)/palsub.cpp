#include<iostream>
using namespace std;

class Solution 
{
public:
    bool palin(string &s) {
        for(int i=0;i<s.size()/2;i++){
            if(s[i]!=s[s.size()-1-i]) return false;
        }

        return true;
    }

    void dfs(string &s,string &s1,string &s2,int index,int &ans) {
        if(index>=s.size()){    //Base case
            if(palin(s1) && palin(s2)) ans=max(ans,(int)s1.size()*(int)s2.size());
            return;
        }

        s1.push_back(s[index]);
        dfs(s,s1,s2,index+1,ans);
        s1.pop_back();

        s2.push_back(s[index]);
        dfs(s,s1,s2,index+1,ans);
        s2.pop_back();

        dfs(s,s1,s2,index+1,ans);
    }

    int maxProduct(string s) {
        int ans = 1;
        string s1,s2 = "";
        dfs(s,s1,s2,0,ans);

        return ans;    
    }
};