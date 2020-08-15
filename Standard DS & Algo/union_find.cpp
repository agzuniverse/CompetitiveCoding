/*
Union Find algorithm, used for Kruskal's algorithm, etc

Both union and find operations are in O(log(n))
*/

#include <iostream>

using namespace std;

// Returns the representative of the set to which vertex xth belongs to
int find(int link[], int size[], int x)
{
    while (link[x] != x)
        x = link[x];
    return x;
}

// Combines the set containing the xth and yth vertices, if they are not already in the same set
void _union_(int link[], int size[], int x, int y)
{
    int r1 = find(link, size, x);
    int r2 = find(link, size, y);
    if (r1 != r2)
    {
        // Always link the smaller set to larger set
        if (size[r1] < size[r2])
        {
            link[r1] = r2;
            size[r2] += size[r1];
        }
        else
        {
            link[r2] = r1;
            size[r1] += size[r2];
        }
    }
}

int main()
{
    int v = 10; // Number of vertices
    /*
    Vertices are partitioned into a number of sets, each set having an element chosen as it's
    representative element.
    When performing union, the representative of the smaller set is linked to the representative of
    the larger set.
    */

    // The first element is not used for clarity
    int link[v + 1]; // link[i] gives the vertex to which the ith vertex is linked to.
                     // representative elements are linked it themselves.

    int size[v + 1]; // size[i] gives the size of the set to which ith vertex belongs to.
    for (int i = 1; i < v + 1; i++)
    {
        link[i] = i; // Initially every element is in it's own set.
        size[i] = 1;
    }
}