/* Given a number of points in the form (x,y), find the convex hull (set of points which when connected forms a convex polygon
that contains all given points)

This is quickhull, an algorithm based on quicksort that runs in O(nlogn) on average, but O(n^2) in worst case.
*/

#include <iostream>
#include <limits>
#include <set>

using namespace std;

// Each point of the convex hull comes up twice (since it is part of 2 edges)
// Set is used to remove repeats.
set<pair<int, int>> ans;

// Calculates a value proportional to the distance of p from the line joining p1 and p2
int finddistance(pair<int, int> p1, pair<int, int> p2, pair<int, int> p)
{
    // (y-y1)*(x2-x1) - (x-x1)*(y2-y1)
    return abs((p.second - p1.second) * (p2.first - p1.first) - (p.first - p1.first) * (p2.second - p1.second));
}

int findside(pair<int, int> p1, pair<int, int> p2, pair<int, int> p)
{
    // Uses the same equation as finddistance()
    int t = (p.second - p1.second) * (p2.first - p1.first) - (p.first - p1.first) * (p2.second - p1.second);
    if (t > 0)
        return 1;
    if (t < 0)
        return -1;
    // return 0 if point p is on the line connecting p1 and p2
    return 0;
}

void quickhullutil(pair<int, int> a[], int n, pair<int, int> left, pair<int, int> right, int side)
{
    // Stores the index in a[] of the point furthest from the line from left to right
    int index = -1;
    int maxdist = 0;
    int temp = 0;
    for (int i = 0; i < n; i++)
    {
        temp = finddistance(left, right, a[i]);
        if (findside(left, right, a[i]) == side && temp > maxdist)
        {
            maxdist = temp;
            index = i;
        }
    }

    // If there are no further elements on this side, left and right are part of the convex hull
    if (index == -1)
    {
        ans.insert(left);
        ans.insert(right);
        return;
    }
    // Go to the side opposite where right is w.r.t a[index] and left
    quickhullutil(a, n, a[index], left, -findside(a[index], left, right));
    // Go to the side opposite where left is w.r.t a[index] and right
    quickhullutil(a, n, a[index], right, -findside(a[index], right, left));
}

void quickhull(pair<int, int> a[], int n)
{
    if (n < 3)
    {
        cout << "Convex hull cannot be formed\n";
        return;
    }
    // Find index of points with lowest and highest x coordinate
    int minx = 0, maxx = 0;
    for (int i = 1; i < n; i++)
    {
        if (a[i].first < a[minx].first)
            minx = i;
        if (a[i].first > a[maxx].first)
            maxx = i;
    }
    // 1 and -1 represent sides, with all points returning 1  from findside() lying on one side of the line,
    // and all points returning -1 from findside() lying on the other side of the line joining a[minx] and a[maxx].
    quickhullutil(a, n, a[minx], a[maxx], 1);
    quickhullutil(a, n, a[minx], a[maxx], -1);

    for (auto i : ans)
        cout << "(" << i.first << ", " << i.second << ")\n";
}

int main()
{
    pair<int, int> a[] = {{0, 3}, {1, 1}, {2, 2}, {4, 4}, {0, 0}, {1, 2}, {3, 1}, {3, 3}};
    int n = sizeof(a) / sizeof(a[0]);
    quickhull(a, n);
}