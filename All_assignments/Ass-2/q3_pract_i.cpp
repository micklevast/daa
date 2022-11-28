#include<iostream>
#include<vector>
using namespace std;
void countSort(vector<int> arr)
{
    vector<int> count(10,0);
    // counting each number frequency
    for(int i=0;i<arr.size();i++)
    {
        count[arr[i]]++;
    }
    // counting postion of each number possible in arr
    for(int i=1;i<10;i++)
    {
        count[i]+=count[i];
    }

    // // placing number at it's correct position
    vector<int> ans(arr.size(),0);
    for(int i=arr.size()-1;i>=0;i--)
    {
        ans[--count[arr[i]]]=arr[i];
    }
    for(int i=0;i<10;i++)
    cout<<ans[i]<<" ";

}
int main()
{
    vector<int> arr{1,3,5,6,2,4,6,9,8};
    countSort(arr);
}