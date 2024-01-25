#include<iostream>
using namespace std;

class Solution {
public:
    int countCollisions(string s) {
      int n=s.size(),cnt=0,i=0;
      bool c=0;
      // stack<char>st;
      int cr=0;
      while(i<n) {
        if(s[i]!='R') {
          if(s[i]=='L') {
            if(cr > 0) {
              cnt += 2;
              cr--;
              c = 1;
              cnt += cr;
              cr = 0;
            }
            else if(c) cnt++;
          }
          else {
           cnt += cr;
           cr = 0;
           c = 1;
          }
        }
        else cr++;
        i++;
      }

      return cnt;
    }
};