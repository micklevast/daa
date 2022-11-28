// search in sorted matrix which is row and column wise sorted
#include <iostream>
#include <vector>
using namespace std;

// Algorithm
// 1.	In the below program we will take the input 2d array .
// 2.	Take input  the element which we need to find out and store it in key variable.
// 3.	Start from the first row and last element check if the element is greater than or equal to the key.
// 4.If the last element is greater than the key then search the element the row and print its index
// 5. Else check the last element of the next row 


vector<int> searching(vector<vector<int>> mat, int i, int j,int search)
{
    // cout<<"searching.\n";
    vector<int> ans(2,-1);
    while (i < mat.size() && j >= 0)
    {
        // cout<<"searching..\n";

        if(mat[i][j]==search)
        {
            
            ans[0]=i;
            ans[1]=j;
            return ans;
        }
        else if(mat[i][j]<search)
        i++;
        else if(mat[i][j]>search)
        j--;
    }
    return ans;
}
int main()
{
    vector<vector<int>> mat{
        {1, 2, 3,12,19},
        {4, 5, 6,15,29},
        {7, 8, 9,18,56}};
    // int i = mat.size() - 1;
    int i=0;
    int j = mat[0].size() - 1;
    vector<int> ans = searching(mat, i, j,100);

    cout<<"at pos index:[ "<<ans[0]<<","<<ans[1]<<" ]"<<endl;
}

// TIME AND SPACE COMPLEXITY:-
// The time complexity of the above algorithm is O(N+M) where N is the number of rows and M is the number of coulmns in the array. 
// The space complexity of the above algorithm is O(1)as there is no extra space is used.
