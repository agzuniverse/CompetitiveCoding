/*
Heapsort - sort that runs in O(nlogn) time
*/

package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	scanner := bufio.NewScanner(os.Stdin)
	fmt.Println("Enter array as space separated numbers") // Example: 12 11 13 5 6 7
	scanner.Scan()
	inp := make([]int, 0)
	for _, v := range strings.Split(scanner.Text(), " ") {
		val, _ := strconv.Atoi(v)
		inp = append(inp, val)
	}
	heapsort(inp)
	fmt.Println(inp)
}

func heapsort(inp []int) {
	n := len(inp)

	// Loop starts from (n/2-1)th element because for every element to its right, 2*i+1 and 2*i+2 are out of bounds.
	for i := int(n/2) - 1; i >= 0; i-- {
		heapify(inp, n, i)
	}
	for i := n - 1; i >= 0; i-- {
		temp := inp[0]
		inp[0] = inp[i]
		inp[i] = temp
		heapify(inp, i, 0)
	}
}

func heapify(inp []int, n int, i int) {
	left := 2*i + 1
	right := 2*i + 2
	newRoot := i
	if left < n && inp[left] > inp[newRoot] {
		newRoot = left
	}
	if right < n && inp[right] > inp[newRoot] {
		newRoot = right
	}
	if newRoot != i {
		temp := inp[i]
		inp[i] = inp[newRoot]
		inp[newRoot] = temp
		heapify(inp, n, newRoot)
	}
}
