#include<iostream>
#include<stack>
using namespace std;

class Solution{   
public:
    string printMinNumberForPattern(string S){
        string ans = "";
        stack<string> st;
        int valToBeInserted = 1; 
        
        for(int i = 0; i < S.length(); i++){
            if(S[i] == 'D') st.push(to_string(valToBeInserted++));
            else{
                st.push(to_string(valToBeInserted++));
                while(!st.empty()){
                    ans += st.top(); 
                    st.pop();
                }
            }
        }
        
        st.push(to_string(valToBeInserted));
        while(!st.empty()){  //Creation of Answer if last value in input string is 'D'.
                ans += st.top(); 
                st.pop();
            }
            
            
        return ans;
    }
};