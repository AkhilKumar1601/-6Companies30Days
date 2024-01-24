#include<iostream>
#include<vector>
#include<set>
#include<algorithm>
using namespace std;

class Solution {
public:
    int wordCount(vector<string>& startWords, vector<string>& targetWords) {
        for(int i=0; i<startWords.size(); i++){
            sort(startWords[i].begin(),startWords[i].end()); 
        }
        for(int i=0; i<targetWords.size(); i++){
            sort(targetWords[i].begin(),targetWords[i].end()); 
        } 
        int ans=0; 
        set<string> st(startWords.begin(),startWords.end());
        for(string s: targetWords){
            bool f=0; 
            for(int i=0; i<s.size(); i++){
                string check=s.substr(0,i)+s.substr(i+1); 
                if(st.count(check)){
                    f=1; 
                    break; 
                }
            } 
            if(f){
                ans++;
            }
        } 
        return ans;
    }
};