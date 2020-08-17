/*
Given an array of points in a 2D plane, find the distance between the closest pair of points

Time complexity: O(nlog(n)^2)
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <limits>

#define P pair<int, int>

using namespace std;

double dist(P a, P b)
{
    return sqrt(pow(b.first - a.first, 2) + pow(b.second - a.second, 2));
}

double bruteForce(vector<P> &v, int l, int r)
{
    double minval = numeric_limits<double>::max();
    for (int i = l; i < r; i++)
        for (int j = i + 1; j < r; j++)
            minval = min(minval, dist(v[i], v[j]));
    return minval;
}

bool sortByY(const P &a, const P &b)
{
    return a.second < b.second;
}

double minFromCloser(vector<P> &v, double m)
{
    double currMin = m;
    // Sort the vector w.r.t to the y coordinate. This is required to make the bottom loop run a max of 6 times only.
    sort(v.begin(), v.end(), sortByY);
    for (int i = 0; i < v.size(); i++)
    {
        // The 2nd condition here ensures this loop runs only a max of 6 times (mathematically proven)
        for (int j = i + 1; j < v.size() && abs(v[j].second - v[i].second) < m; j++)
            currMin = min(currMin, dist(v[i], v[j]));
    }
    return currMin;
}

double closestPoints(vector<P> &v, int start, int end)
{
    // Base case - when there are 2 or 3 points, bruteforce the minimum distance and return
    if (end - start < 3)
        return bruteForce(v, start, end);
    int mid = (end + start) / 2;
    // Find the minimum distance between points on either side of the mid point
    double minLeft = closestPoints(v, start, mid);
    double minRight = closestPoints(v, mid, end);
    double totalMin = min(minLeft, minRight);

    // See if there are any points that are closer to mid point that d (using x coordinate distance only)
    vector<P> closer;
    for (int i = start; i < end; i++)
        if (abs(v[i].first - v[mid].first) < totalMin)
            closer.push_back(v[i]);

    // Check if any pair of elements in closer are closer than totalMin
    double closerMin = minFromCloser(closer, totalMin);
    return min(closerMin, totalMin);
}

int main()
{
    // Input of points
    vector<P> v{{2, 3}, {12, 30}, {40, 50}, {5, 1}, {12, 10}, {3, 4}};

    // Sort the elements by x coordinate
    sort(v.begin(), v.end());
    cout << closestPoints(v, 0, v.size());
}