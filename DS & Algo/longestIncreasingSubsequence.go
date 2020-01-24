/*
Algorithm to find the longest increasing subsequence in an array.

The DP solution runs in O(n^2) time. This solution runs in O(nlogn) time and O(n) space.
*/

package main

import "fmt"

func longestIncreasingSubsequence(arr []int) int {
	n := len(arr)
	lastElems := make([]int, n)
	lastElems[0] = arr[0] // Keep track of possible endings of the subsequence.
	result := 1
	for i := 1; i < n; i++ {
		if arr[i] < lastElems[0] { // If the current element is smaller than the last element of the smallest subsequence, replace it and start a new subsequence.
			lastElems[0] = arr[i]
		} else if arr[i] > lastElems[result-1] { // If current element is larger than last element of largest subsequence, append current element to the subsequence (effectively clone the subsequence).
			lastElems[result] = arr[i]
			result++
		} else { // If neither, replace the last element of the first subsequence whose last element is larger than current element with current element.
			lastElems[lowerBound(arr, -1, result-1, arr[i])] = arr[i]
		}
	}
	return result
}

func lowerBound(arr []int, l int, r int, e int) int {
	// Use binary search and return index of first element that is >= the current element e
	m := int((r + l) / 2)
	for r-l > 1 {
		m = l + int((r-l)/2)
		if arr[m] >= e {
			r = m
		} else {
			l = m
		}
	}
	return r
}

func main() {
	inp := []int{2, 5, 3, 7, 11, 8, 10, 13, 6}
	result := longestIncreasingSubsequence(inp)
	fmt.Println(result)
}

// This is similar to Patience Sort, which runs in O(nlog(log(n))) time.
