/*
Cycle Sort:
Cycle Sort runs in O(n^2) time but performs the minimum number of memory writes.
Used in situations when memory writes are much more expensive than memory reads.

It finds the elements to the right of each element that are smaller than that element.
If there are k such elements, the current element must be atleast in the kth position.

Once this swap is done, the element originally in the kth position is stored in temp,
and the process is repeated for this element.
*/

package main

import "fmt"

func main() {
	inp := []int{1, 8, 3, 9, 10, 10, 2, 4} // Sample input
	cycleSort(inp)
	fmt.Println(inp)
}

func cycleSort(arr []int) {
	var temp int
	var index int
	for i := 0; i < len(arr)-1; i++ {
		temp = arr[i]
		index = i

		// Find the minimum index the element must be stored at by counting elements larger than it to it's right.
		for j := i + 1; j < len(arr); j++ {
			if arr[j] < temp {
				index++
			}
		}
		// Don't swap if the position is already correct.
		if index == i {
			continue
		}

		// Increment index until we clear all duplicate elements.
		for temp == arr[index] {
			index++
		}

		// Swap. The element in the kth position is now the element we are considering.
		t := temp
		temp = arr[index]
		arr[index] = t

		// Loop (i.e, go through all cycles) until the we get the element to put in the position of the original element.
		for index != i {
			index = i
			for j := i + 1; j < len(arr); j++ {
				if arr[j] < temp {
					index++
				}
			}
			for temp == arr[index] {
				index++
			}
			t := temp
			temp = arr[index]
			arr[index] = t
		}
	}
}

/* Cycle sort is an unstable sorting algorithm. */
