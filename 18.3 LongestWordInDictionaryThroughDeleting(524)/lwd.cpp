#include<iostream>
#include<vector>
using namespace std;

class Solution {
private:
    bool check(string text1, string text2){
        int i=0, j=0;
        while(i<text1.length() && j<text2.length()){
            if(text1[i]==text2[j]){
                i++;
                j++;
            }
            else i++;
        }
        if(j==text2.length()) return true;

        return false;
    }
    
public:
    string findLongestWord(string s, vector<string>& dictionary) {
        
        string ans="";
        for(int i=0 ; i<dictionary.size(); i++){
            if(check(s, dictionary[i])){
                if(dictionary[i].length()>ans.length()) ans = dictionary[i];
                else if(dictionary[i].length()==ans.length() && ans>dictionary[i]) ans = dictionary[i];
            }
        }
        return ans;
    }
};