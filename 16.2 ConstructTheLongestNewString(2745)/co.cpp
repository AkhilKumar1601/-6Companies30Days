#include<iostream>
using namespace std;

class Solution {
public:
    int longestString(int x, int y, int z) { 
        if(x>y) x=y+1;
        else if(x<y)  y = x+1;
        return 2*(x + y + z);
    }
};