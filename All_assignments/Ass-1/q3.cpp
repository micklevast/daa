// Q3) Given a sorted array of n integers that has been rotated an unknown number of times, write code to find an element in the array.
//  You may assume that the array was originally sorted in increasing order.

// Algorithm
// 1.initilise i=0 ,j=size-1 and find mid=(i+j)/2;
// 2.traversing until i<j
//     i.if search element founded then return it's index
//     ii.else if  try to search in sorted array part by checking arr[i]<arr[mid] and update i/j index
//         I. if arr[i]<=Search_ele && Search_ele<=arr[mid-1] then search left side
//         II.else search right side
// 3.if not found the return -1

#include<iostream>
#include<vector>
using namespace std;
// Driver code
int searching(int *arr,int size,int Search_ele)
{
    int i=0;
    int j=size-1;
    while(i<j)
    {
        int  mid=i+(j-i)/2;
        if(arr[mid]==Search_ele)
        return mid;
        else if(arr[mid]>arr[i])
        {
            if(arr[i]<=Search_ele && Search_ele<=arr[mid-1] )
            j=mid-1;
            else
            i=mid+1;
        }
        else
        {
            if(Search_ele>= arr[mid+1] && Search_ele<=arr[j])
            i=mid+1;
            else
            j=mid-1;
        }
    }
    return -1;
}
int main()
{
	int arr[] = {15, 16, 19, 20, 25, 1, 3, 4, 5, 7, 10, 14};
	int n = sizeof(arr) / sizeof(arr[0]);
	int serachedIndex=searching(arr,n,20);
    cout<<"search index founded:"<<serachedIndex<<endl;
	return 0;
}

// Complexity Analyse:
// 1>time complexity is log(n) for binary search
// 2>space complexity is O(1) as only used constant space
