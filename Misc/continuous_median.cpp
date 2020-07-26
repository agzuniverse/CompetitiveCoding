/*
Write a program to maintain a running median of a stream of numbers.

Here the numbers are given as an input array, but the idea is that the program should be
be able to handle an infinite stream of numbers and print the median of all the numbers so
far whenever asked to.
*/

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

void printMedian(vector<int> inp, int n)
{
    // Maxheap
    priority_queue<int> mx;
    // Minheap
    priority_queue<int, vector<int>, greater<int>> mn;

    // Initial median is the first element
    float median = inp[0];
    mx.push(median);
    cout << median << endl;

    for (int i = 1; i < n; i++)
    {
        int curr = inp[i];
        if (mx.size() > mn.size())
        {
            if (curr < median)
            {
                mn.push(mx.top());
                mx.pop();
                mx.push(curr);
            }
            else
                mn.push(curr);
            median = (mx.top() + mn.top()) / 2.0;
        }
        else if (mx.size() < mn.size())
        {
            if (curr > median)
            {
                mx.push(mn.top());
                mn.pop();
                mn.push(curr);
            }
            else
                mx.push(curr);
            median = (mx.top() + mn.top()) / 2.0;
        }
        else
        {
            if (curr < median)
            {
                mx.push(curr);
                median = mx.top();
            }
            else
            {
                mn.push(curr);
                median = mn.top();
            }
        }
        cout << median << endl;
    }
}

int main()
{
    vector<int> inp{5, 15, 10, 20, 3};
    int n = inp.size();
    printMedian(inp, n);
}

/*
Explanation:
Maintain a min heap and max heap.
Elements lower than the median go into the max heap.
Elements higher than the median go into the min heap.
Make sure the heaps differ at most only by 1. If the difference is going to increase,
remove the root of the larger heap and push it to other heap.

If the heaps have the same amount of nodes, the median is average of both the roots.
Otherwise it's the root of whichever heap is larger.
*/