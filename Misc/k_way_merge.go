/*
K-way merge:
Given K sorted arrays of N elements each, merge them all into a single sorted array.

This algorithm using min-heap runs in O(KNlogK) time which is faster than using the usual
merge sort algorithm extended to K arrays which runs in O((K^2)*N) time.
*/

package main

import (
	"fmt"
)

type heapElement struct {
	data  int // The element itself
	index int // The index of the array from the K arrays that this element belongs to
}

func main() {
	// Sample input with K=3 and N=3
	inp := [][]int{{10, 15, 30}, {12, 15, 20}, {17, 20, 32}}
	k := 3
	n := 3
	res := make([]int, 0)
	heap := make([]heapElement, 0)
	res = makeMinHeap(inp, k, n, heap)
	fmt.Println(res)
}

func makeMinHeap(inp [][]int, k int, n int, heap []heapElement) (res []int) {
	// Add first element from each array into heap array to construct a min-heap
	for i := 0; i < k; i++ {
		heap = append(heap, heapElement{inp[i][0], i})
	}
	for i := int(k/2) - 1; i >= 0; i-- {
		heapify(heap, k, i)
	}

	// Take first element of minheap and put it into result
	// Then take the next element from the array to which the first element belonged to and add it to min heap
	// If that array is empty, remove first element from heap
	for i := 0; i < k*n; i++ {
		res = append(res, heap[0].data)
		if len(inp[heap[0].index]) > 0 {
			inp[heap[0].index] = inp[heap[0].index][1:]
			if len(inp[heap[0].index]) > 0 {
				heap[0] = heapElement{inp[heap[0].index][0], heap[0].index}
				heapify(heap, k, 0)
			} else {
				heap = heap[1:]
				heapify(heap, len(heap), 0)
			}
		} else {
			heap = heap[1:]
			heapify(heap, len(heap), 0)
		}
	}
	return
}

func heapify(inp []heapElement, n int, i int) {
	left := 2*i + 1
	right := 2*i + 2
	newRoot := i
	if left < n && inp[left].data < inp[newRoot].data {
		newRoot = left
	}
	if right < n && inp[right].data < inp[newRoot].data {
		newRoot = right
	}
	if newRoot != i {
		temp := inp[i]
		inp[i] = inp[newRoot]
		inp[newRoot] = temp
		heapify(inp, n, newRoot)
	}
}
