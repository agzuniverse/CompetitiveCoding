// Generates a uniform random permutation by randomizing in-place to avoid wost cases and to almost always ensure average case cost

#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, input;
    vector<int> a;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> input;
        a.push_back(input);
    }
    srand(time(0));
    for (int i = 0; i < n; i++)
    {
        int r = rand() % n; //Rand generates integers in the range 0 to RAND_MAX
        iter_swap(a.begin() + i, a.begin() + r);
    }
    for (auto i = a.begin(); i < a.end(); i++)
    {
        cout << *i << endl;
    }
}