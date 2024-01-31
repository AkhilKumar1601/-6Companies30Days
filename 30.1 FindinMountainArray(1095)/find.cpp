#include<iostream>
using namespace std;

class MountainArray {
   public:
     int get(int index);
     int length();
};

class Solution {
public:
    //binary search in incresing array
    int bs_self1(int low,int high,MountainArray  &arr,int target)
    {
        if(low>high)
        return -1;
        if(low==high)
        return arr.get(low)==target?low:-1;
        while(low<=high)
        {
            int mid=low+(high-low)/2;
            int x=arr.get(mid);
            if(x==target)
            return mid;
            if(x<target)
            low=mid+1;
            else
            high=mid-1;
        }
        return -1;
    }
    //binary search in decresing array 
    int bs_self2(int low,int high,MountainArray  &arr,int target)
    {
        if(low>high)
        return -1;
        if(low==high)
        return arr.get(low)==target?low:-1;
        while(low<=high)
        {
            int mid=low+(high-low)/2;
            int x=arr.get(mid);
            if(x==target)
            return mid;
            if(x>target)
            low=mid+1;
            else
            high=mid-1;
            
        }
        
        return -1;
    }
    int findInMountainArray(int target, MountainArray &arr) {
        int peak;
        int n=arr.length();
        if(arr.length()==1)
            return arr.get(0)==target?0:-1;
        if(arr.get(0)>arr.get(1))
        //binary search for find peak
        peak=0;
        else if(arr.get(n-1)>arr.get(n-2))
        peak=n-1;
        else
        {
            int low=1,high=n-2;
            while(low<=high)
            {
                int mid=low+(high-low)/2;
                int x=arr.get(mid);
                int y=arr.get(mid+1);
                int z=arr.get(mid-1);
                if(x>y && x>z)
                {
                    peak=mid;
                    break;
                }
                else if(x>z && y>x)
                low=mid+1;
                else
                high=mid-1;
            }
        }
        int left_part=bs_self1(0,peak,arr,target);
        if(left_part!=-1)
        return left_part;
        int right_part=bs_self2(peak+1,n-1,arr,target);
        return right_part;
    }
};