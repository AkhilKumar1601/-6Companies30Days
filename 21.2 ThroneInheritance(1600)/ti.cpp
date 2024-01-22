#include<iostream>
#include<vector>
#include<unordered_map>
#include<map>
using namespace std;

class ThroneInheritance {
public:
    map<string,int> m;
    unordered_map<string,vector<string>> adj;
    string king = "";
    ThroneInheritance(string kingName) {
        adj.clear();
        m.clear();
        king  = kingName;
    }
    
    void birth(string parentName, string childName) {
        adj[parentName].push_back(childName);
    }
    
    void death(string name) {
        m[name]++;
    }
    void dfs(string node,vector<string>& ans,map<string,int>& vis) {
        vis[node] = 1;
        if(m.find(node)==m.end())
        ans.push_back(node);
        for(auto &i:adj[node]) {
            if(vis.find(i)==vis.end()) dfs(i,ans,vis);
        }
    }
    vector<string> getInheritanceOrder() {
        vector<string> ans;
        map<string,int> vis;
        dfs(king,ans,vis);
        return ans;
    }
};