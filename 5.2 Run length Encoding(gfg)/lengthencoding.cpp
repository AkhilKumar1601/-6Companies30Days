#include<iostream>
using namespace std;

string encode(string src)
{     
  string ans = "";
  int cnt = 1;
  
  for(int i = 0; i < src.size() - 1; i++){
      if(src[i] == src[i+1]) cnt++;
      else{
          ans += src[i];
          ans += to_string(cnt);
          cnt = 1;
      }
  }
  
  ans += src[src.size()-1];
  return ans += to_string(cnt);
} 