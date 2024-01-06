#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    static bool compare(vector<int> &a, vector<int> &b){
            if(a[0] == b[0]) return a[1] > b[1]; //sort width in A.O.
            else return a[0] < b[0];  //sort height in D.O.
        }
    
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        sort(envelopes.begin(),envelopes.end(),compare);

        vector<int> ans;
        ans.push_back(envelopes[0][1]);  //initial state;

        for(int i = 1; i < envelopes.size(); i++){
            if(ans.back() < envelopes[i][1]) {
                ans.push_back(envelopes[i][1]);   
            }
            else{
                auto possiblePosi = lower_bound(ans.begin(),ans.end(),envelopes[i][1]);  //return iterator
                auto index = possiblePosi - ans.begin(); // substract because to convert iterator into numberic value.
                ans[index] = envelopes[i][1];
            }
        }
        return ans.size();
    }
};