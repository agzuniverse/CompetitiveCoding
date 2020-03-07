/*
You are given an array of non-negative integers that represents a two-dimensional elevation map where each element is
unit-width wall and the integer is the height. Suppose it will rain and all spots between two walls get filled up.

Compute how many units of water remain trapped on the map in O(N) time and O(1) space.
*/

package main

import "fmt"

func main() {
	inp := []int{0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1} // Sample input
	fmt.Println(calcWaterQuantity(inp))
}

func calcWaterQuantity(arr []int) int {
	totalQuantity := 0
	temp := 0
	max := arr[0]
	// Loop from left to right
	for i := 1; i < len(arr); i++ {
		if arr[i] >= max {
			// If the current element is greater than or equal to max,
			// add the quantity collected so far to total quantity and set max to this value
			totalQuantity += temp
			temp = 0
			max = arr[i]
		} else {
			// Add quantity that can be stored in that spot to temp
			temp += max - arr[i]
		}
	}
	// If there is no wall to the right that is greater than or equal to max, the last temp value
	// is wrong and will not get added to the totalQuantity.
	// Loop from right to left with the same logic so the correct value in this case will get added
	temp = 0
	max = arr[len(arr)-1]
	for i := len(arr) - 2; i >= 0; i-- {
		if arr[i] >= max {
			totalQuantity += temp
			temp = 0
			max = arr[i]
		} else {
			temp += max - arr[i]
		}
	}
	return totalQuantity
}
