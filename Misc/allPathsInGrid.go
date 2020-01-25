/*
Given a value n, find the number of paths from the top left corner of an NxN grid to the bottom right corner,
in such a way that all squares in the grid are visited exactly once.
*/

package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

type cell struct {
	visited bool
}

func main() {
	fmt.Println("Enter the value of N")
	inp := bufio.NewScanner(os.Stdin)
	inp.Scan()
	n, _ := strconv.Atoi(inp.Text())
	// Create an NxN grid
	grid := make([][]cell, n)
	for i := range grid {
		grid[i] = make([]cell, n)
	}

	// Optimization: All solutions where the first move is down is symmetrical to all solutions where the first move is right
	// Hence we can mark the first cell as visited and move either down or right, then multiply final answer by 2.
	grid[0][0].visited = true
	result := noOfPaths(grid, 0, 1, n)
	result *= 2
	fmt.Println("The number of paths is: ", result)
}

func noOfPaths(grid [][]cell, x int, y int, n int) int {
	if x == n-1 && y == n-1 {
		grid[x][y].visited = true
		if checkIfComplete(grid, n) {
			grid[x][y].visited = false
			return 1
		}
		grid[x][y].visited = false
		return 0 // Optimization: if last block is reached and all blocks are not covered, it is impossible to cover all blocks exactly once in this path
	}
	// Optimization: if we cannot move left or right but we can move both up and down, it is impossible to cover all blocks
	// Similarly, if we cannot move up or down but can move both left and right, it is impossible to cover all blocks.
	if ((x-1 < 0 || grid[x-1][y].visited) && (x+1 > n-1 || grid[x+1][y].visited)) && ((y-1 >= 0 && !grid[x][y-1].visited) && (y+1 <= n-1 && !grid[x][y+1].visited)) {
		return 0
	} else if ((y-1 < 0 || grid[x][y-1].visited) && (y+1 > n-1 || grid[x][y+1].visited)) && ((x-1 >= 0 && !grid[x-1][y].visited) && (x+1 <= n-1 && !grid[x+1][y].visited)) {
		return 0
	}
	ways := 0
	if x < n-1 && !grid[x+1][y].visited {
		grid[x][y].visited = true
		ways += noOfPaths(grid, x+1, y, n)
		grid[x][y].visited = false
	}
	if y < n-1 && !grid[x][y+1].visited {
		grid[x][y].visited = true
		ways += noOfPaths(grid, x, y+1, n)
		grid[x][y].visited = false
	}
	if x > 0 && !grid[x-1][y].visited {
		grid[x][y].visited = true
		ways += noOfPaths(grid, x-1, y, n)
		grid[x][y].visited = false
	}
	if y > 0 && !grid[x][y-1].visited {
		grid[x][y].visited = true
		ways += noOfPaths(grid, x, y-1, n)
		grid[x][y].visited = false
	}
	return ways
}

func checkIfComplete(grid [][]cell, n int) bool {
	for i := 0; i < n; i++ {
		for j := 0; j < n; j++ {
			if !grid[i][j].visited {
				return false
			}
		}
	}
	return true
}
