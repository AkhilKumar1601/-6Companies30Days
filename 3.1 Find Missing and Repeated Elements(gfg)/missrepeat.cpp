#include<iostream>
#include<vector>
using namespace std;

class Solution{
public:
    vector<int> findTwoElement(vector<int> arr, int n) {
        int i = 0; 
        while(i < n){ //Sorting using swap
            int index = arr[i] - 1; //all values are considered as index but index 0 indexed that's why -1
            if(arr[i] != arr[index])swap(arr[i],arr[index]);
            else i++;
        }
        
        int missingVal, repeatedVal;
        
        for(int i = 0; i < n; i++){ 
            if(i + 1 != arr[i]){
                missingVal = i + 1;
                repeatedVal = arr[i];
                break;
            }
        }
        
        return {repeatedVal,missingVal};
    }
};