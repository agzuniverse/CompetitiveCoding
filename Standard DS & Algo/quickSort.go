package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	//Example a := []int{5, 10, 8, 9, 0, 2, 7, 28, 1, 3, 4}
	scanner := bufio.NewScanner(os.Stdin)
	fmt.Println("Enter array to be sorted as space-separated integers")
	scanner.Scan()
	a := make([]int, 0)
	for _, v := range strings.Split(scanner.Text(), " ") {
		i, _ := strconv.Atoi(v)
		a = append(a, i)
	}
	fmt.Println(a)
	quickSort(a, 0, len(a)-1)
	fmt.Println(a)
}

func quickSort(a []int, l int, r int) {
	if l >= r {
		return
	}
	index := partition(a, l, r)
	quickSort(a, l, index-1)
	quickSort(a, index+1, r)
}

func partition(a []int, l int, r int) int {
	pivot := a[l]
	left, right := l, r
	for left < right {
		for a[left] <= pivot && left < r {
			left++
		}
		for a[right] > pivot {
			right--
		}
		if left < right {
			temp := a[left]
			a[left] = a[right]
			a[right] = temp
		}

	}
	a[l] = a[right]
	a[right] = pivot
	return right
}
