// C++ implementation of the approach
#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <map>
#include <queue>
#include <set>
#include <string>
#define llu long long int
using namespace std;


struct Point {

	llu x, y;

	bool operator<(Point p)
	{
		return x < p.x || (x == p.x && y < p.y);
	}
};

// Cross product of two vectors OA and OB
// returns positive for counter clockwise
// turn and negative for clockwise turn

llu cross_product(Point O, Point A, Point B)
{
	return (A.x - O.x) * (B.y - O.y)
		- (A.y - O.y) * (B.x - O.x);
}

// Returns a list of points on the convex hull
// in counter-clockwise order
vector<Point> convex_hull(vector<Point> A)
{
	int n = A.size(), k = 0;

	if (n <= 3)
		return A;

	vector<Point> ans(2 * n);

	// Sort points lexicographically
	sort(A.begin(), A.end());

	// Build lower hull
	for (int i = 0; i < n; ++i) {

		// If the point at K-1 position is not a part
		// of hull as vector from ans[k-2] to ans[k-1]
		// and ans[k-2] to A[i] has a clockwise turn
		while (k >= 2
			&& cross_product(ans[k - 2],
							ans[k - 1], A[i]) <= 0)
			k--;
		ans[k++] = A[i];
	}

	// Build upper hull
	for (size_t i = n - 1, t = k + 1; i > 0; --i) {

		// If the point at K-1 position is not a part
		// of hull as vector from ans[k-2] to ans[k-1]
		// and ans[k-2] to A[i] has a clockwise turn
		while (k >= t
			&& cross_product(ans[k - 2],
						ans[k - 1], A[i - 1]) <= 0)
			k--;
		ans[k++] = A[i - 1];
	}

	// Resize the array to desired size
	ans.resize(k - 1);

	return ans;
}

// Function to return the distance between two points
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
void print_all_boundary_point(vector<Point> ans)
{
    for(int i=0;i<ans.size();i++)
    {
        cout<<"[ "<<ans[i].x<<" , "<<ans[i].y<<" ]"<<"  ";
    }
}
int main()
{
	vector<Point> points={{1,4},{1,3},{1,2},{2,1},{4,4},{3,3},{3,2},{4,1},{6,3},{5,2},{6,1},{7,4},{7,2},{8,1},{8,3},{9,2}};

	// Find the convex hull
	vector<Point> ans = convex_hull(points);
    cout<<"Followinng are the bounded region :\n";
    print_all_boundary_point(ans);

	// Find the perimeter of convex polygon
	cout<<"\nthe perimeter of bounded region:" << perimeter(ans)<<endl;;

	return 0;
}
// TIME AND SPACE COMPLEXITY:

// The time complexity of the above algorithm in the average case is of O(NlogN) while in worst case it gives the time complexity of O(N^2). The space complexity is O(K) as extra space is used to store the convex hull points where K is the number of points in the convex hull.

