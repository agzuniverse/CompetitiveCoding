/*
Fisher-Yates algorithm is used to generate a random permutation of an array
in O(n) time and O(1) space.

It starts at the end of the array, takes a random element (including the last element) and
swaps it with the last element. Then array of length n-2 is considered and the process is repeated.
*/

#include<iostream>
#include<time.h>
#include<random>

using namespace std;

void create_random_permutation(int arr[], int size)
{
    for(int i=size-1; i>=0; i--)
    {
        int x = rand()%(i+1);
        swap(arr[x],arr[i]);
    }
}

int main()
{
    srand((unsigned)time(NULL));
    int arr[] = {1,2,3,4,5};
    int size = sizeof(arr)/sizeof(arr[0]);
    create_random_permutation(arr,size);
    for(int i=0; i<size; i++)
    {
        cout<<arr[i]<<" ";
    }
}