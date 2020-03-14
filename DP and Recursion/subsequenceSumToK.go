/* Perfect sum problem:
Given an array and a value k, print all the subsequences of the array that will sum up to k.
Assume all elements in the array will be positive.
*/

package main

import "fmt"

var result []int
var resultPresent bool

func main() {
	// Sample input
	arr := []int{12, 1, 61, 5, 9, 2}
	k := 24

	result = make([]int, 0)
	findSubarray(arr, 0, k)
	if !resultPresent {
		fmt.Println("Not possible")
	}
}

func findSubarray(arr []int, i int, k int) {
	if i > len(arr)-1 {
		return
	}

	for j := i; j < len(arr); j++ {
		remaining := k - arr[j]
		if remaining == 0 {
			result = append(result, arr[j])
			fmt.Println(result)
			resultPresent = true
			result = result[:len(result)-1]
		} else if remaining < 0 {
			continue
		} else if remaining > 0 {
			result = append(result, arr[j])
			findSubarray(arr, j+1, remaining)
			result = result[:len(result)-1]
		}
	}
}
