/* Find the smallest positive integer NOT in a given array in linear time and constant space */

package main

import (
	"fmt"
)

func main() {
	inp := []int{0, 10, 2, -10, -20} // Sample input

	// Move all negative and zero elements to the left and return the index of the first positive element
	firstPositiveElem := segregate(inp)
	inp = inp[firstPositiveElem:]
	fmt.Println(findSmallestMissingPositiveElement(inp))
}

func findSmallestMissingPositiveElement(inp []int) int {
	n := len(inp)

	// For each positive element E, set the element present at Eth index to it's negative (ignore if it's out of bounds)
	for i := 0; i < n; i++ {
		a := Abs(inp[i])
		if a-1 < n && inp[a-1] > 0 {
			inp[a-1] = -inp[a-1]
		}
	}
	// The first index which contains a positive element will be the lowest positive number not in the array.
	for i := 0; i < n; i++ {
		if inp[i] > 0 {
			return i + 1
		}
	}

	// The array consists of consecutive positive elements, so we return the next possible positive element
	return n + 1
}

func segregate(inp []int) int {
	j := 0
	for i := 0; i < len(inp); i++ {
		if inp[i] <= 0 {
			if i != j {
				temp := inp[i]
				inp[i] = inp[j]
				inp[j] = temp
			}
			j++
		}
	}
	return j
}

func Abs(e int) int {
	if e >= 0 {
		return e
	}
	return -e
}

/*
Explanation:
This is similar to counting sort except we do it in place since we can modify original array and have to
do it in constant space.
*/
