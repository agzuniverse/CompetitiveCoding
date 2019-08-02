package main

import "fmt"

func main() {
	a := []int{5, 10, 8, 9, 0, 2, 7, 28, 1, 3}
	fmt.Println(a)
	mergeSort(a, 0, len(a)-1)
	fmt.Println(a)
}

func mergeSort(arr []int, l int, u int) {
	if l >= u {
		return
	}
	mid := (l + u) / 2
	mergeSort(arr, l, mid)
	mergeSort(arr, mid+1, u)
	merge(arr, l, mid, u)
}

func merge(arr []int, l int, mid int, u int) {
	var temp []int
	lower, upper := l, mid+1
	for lower <= mid && upper <= u {
		if arr[lower] <= arr[upper] {
			temp = append(temp, arr[lower])
			lower++
		} else {
			temp = append(temp, arr[upper])
			upper++
		}
	}
	for lower <= mid {
		temp = append(temp, arr[lower])
		lower++
	}
	for upper <= u {
		temp = append(temp, arr[upper])
		upper++
	}
	for _, i := range temp {
		arr[l] = i
		l++
	}
}
