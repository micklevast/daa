// Q1) Implement algorithm to Find the maximum element in an array which is first increasing and then decreasing,
//  with Time Complexity O(Logn).
#include <iostream>
#include <vector>
using namespace std;
int maximum_using_DAC(vector<int> arr, int l, int r)
{
    while (l < r)
    {
        int mid = l + (r - l) / 2;
        if ((arr[mid] > arr[mid - 1]) && (arr[mid] > arr[mid + 1]))
        {
            return arr[mid];
        }
        else
        {
            // left movement
            if ((arr[mid - 1] > arr[mid]) && (arr[mid] > arr[mid + 1]))
            {
                r = mid - 1;
            }

            // right movement
            else
            {
                l = mid + 1;
            }
        }
    }
    return -2;
}
int main()
{
    vector<int> arr{23, 34, 39, 46, 58, 75, 80,90,100,120,150,200, 40, 20, 10, 5};
    cout << "maximum ele are"
         << ":" << maximum_using_DAC(arr, 0, arr.size() - 1);
}

// complexity Analyse:
// TC-Log(n) for binary searching
// SC-O(1)
