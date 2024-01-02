#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    void solve(vector<vector<int>>& ans, vector<int>& output, int k, int n, int no ){
        if(k == 0 && n == 0){
            ans.push_back(output);
            return;
        }
        if(n < 0 || k < 0)return;
        if(no == 10)return;

        solve(ans,output,k,n,no+1); //excluding
        output.push_back(no);
        solve(ans,output,k-1,n-no,no+1); //including
        output.pop_back();
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ans;
        vector<int> output; //Store different solutions.
        solve(ans,output,k,n,1);
        return ans;
    }
};