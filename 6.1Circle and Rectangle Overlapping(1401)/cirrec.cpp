#include<iostream>
using namespace std;

class Solution {
public:
    bool checkOverlap(int radius, int xCenter, int yCenter, int x1, int y1, int x2, int y2) {
       for(int x = x1; x <= x2; x++){     //Traverse on x-axis
           for(int y = y1; y <= y2; y++){  //Traverse on y-axis
               double distanceFromCircleCenter = ((x-xCenter)*(x-xCenter)) + ((y-yCenter)*(y-yCenter));
               double r = radius * radius;
        
               if(distanceFromCircleCenter <= r) return true; //overlapped
           }
       }
       return false;
    }
};