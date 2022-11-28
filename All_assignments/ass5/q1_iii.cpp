// C++ program to implement Quick Hull algorithm
// to find convex hull. #include<bits/stdc++.h> using namespace std;
#include <iostream>
#include <vector>
#include <map>
#include <queue>
#include <set>
#include <string>
using namespace std;
// iPair is integer pairs
#define iPair pair<int, int>

// Stores the result (points of convex hull)
set<iPair> hull;

// Returns the side of point p with respect to line
// joining points p1 and p2.
int findSide(iPair p1, iPair p2, iPair p)
{
    int val = (p.second - p1.second) * (p2.first - p1.first) - (p2.second - p1.second) * (p.first - p1.first);

    if (val > 0)
        return 1;
    if (val < 0)
        return -1;
    return 0;
}

// returns a value proportional to the distance
// between the point p and the line joining the
// points p1 and p2
int lineDist(iPair p1, iPair p2, iPair p)
{
    return abs((p.second - p1.second) * (p2.first - p1.first) - (p2.second - p1.second) * (p.first - p1.first));
}

// End points of line L are p1 and p2. side can have value
// 1 or -1 specifying each of the parts made by the line L
void quickHull(iPair a[], int n, iPair p1, iPair p2, int side)
{
    int ind = -1;
    int max_dist = 0;

    // finding the point with maximum distance
    // from L and also on the specified side of L.
    for (int i = 0; i < n; i++)
    {
        int temp = lineDist(p1, p2, a[i]);
        if (findSide(p1, p2, a[i]) == side && temp > max_dist)
        {
            ind = i;
            max_dist = temp;
        }
    }

    // If no point is found, add the end points
    // of L to the convex hull.
    if (ind == -1)
    {
        hull.insert(p1);
        hull.insert(p2);
        return;
    }

    // Recur for the two parts divided by a[ind]
    quickHull(a, n, a[ind], p1, -findSide(a[ind], p1, p2));
    quickHull(a, n, a[ind], p2, -findSide(a[ind], p2, p1));
}

void printHull(iPair a[], int n)
{
    // a[i].second -> y-coordinate of the ith point
    if (n < 3)
    {
        cout << "Convex hull not possible\n";
        return;
    }

    int min_x = 0, max_x = 0;
    for (int i = 1; i < n; i++)
    {
        if (a[i].first < a[min_x].first)
            min_x = i;
        if (a[i].first > a[max_x].first)
            max_x = i;
    }

    // Recursively find convex hull points on
    // one side of line joining a[min_x] and
    // a[max_x]
    quickHull(a, n, a[min_x], a[max_x], 1);

    // Recursively find convex hull points on
    // other side of line joining a[min_x] and
    // a[max_x]
    quickHull(a, n, a[min_x], a[max_x], -1);

    cout << "The points in Convex Hull are:\n";
    while (!hull.empty())
    {
        cout << "(" << (*hull.begin()).first << ", "
             << (*hull.begin()).second << ") ";
        hull.erase(hull.begin());
    }
}

double dist(Point a, Point b)
{
	return sqrt((a.x - b.x) * (a.x - b.x)
				+ (a.y - b.y) * (a.y - b.y));
}

// Function to return the perimeter of the convex hull
double perimeter(vector<Point> ans)
{
	double perimeter = 0.0;

	// Find the distance between adjacent points
	for (int i = 0; i < ans.size() - 1; i++) {
		perimeter += dist(ans[i], ans[i + 1]);
	}

	// Add the distance between first and last point
	perimeter += dist(ans[0], ans[ans.size() - 1]);

	return perimeter;
}



// Driver code
int main()
{
    iPair a[] = {{1,4},{1,3},{1,2},{2,1},{4,4},{3,3},{3,2},{4,1},{6,3},{5,2},{6,1},{7,4},{7,2},{8,1},{8,3},{9,2}};
    

    int n = sizeof(a) / sizeof(a[0]);
    printHull(a, n);
    return 0;
}
// tc and SC
The time complexity of the above algorithm in the average case is of O(NlogN) while in worst case it gives the time complexity of O(N^2). The space complexity is O(K) as extra space is used to store the convex hull points where K is the number of points in the convex hull.
