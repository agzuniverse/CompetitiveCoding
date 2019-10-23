def find_blank(arr, l):
    for row in range(9):
        for col in range(9):
            if(arr[row][col] == 0):
                l[0] = row
                l[1] = col
                return True
    return False


def in_row(arr, row, num):
    for i in range(9):
        if(arr[row][i] == num):
            return True
    return False


def in_column(arr, col, num):
    for i in range(9):
        if(arr[i][col] == num):
            return True
    return False


def in_box(arr, row, col, num):
    for i in range(3):
        for j in range(3):
            if(arr[i+row][j+col] == num):
                return True
    return False


def check_location(arr, row, col, num):
    return not in_row(arr, row, num) and not in_column(arr, col, num) and not in_box(arr, row - row % 3, col - col % 3, num)


def solve(arr):
    l = [0, 0]
    if not find_blank(arr, l):
        return True
    row = l[0]
    col = l[1]
    for num in range(1, 10):
        if(check_location(arr, row, col, num)):
            arr[row][col] = num
            if(solve(arr)):
                return True
            arr[row][col] = 0
    return False


grid = [[0 for x in range(9)]for y in range(9)]
for a in range(9):
    grid[a] = [int(x) for x in input().split()]
if(solve(grid)):
    for a in range(0, 9):
        for b in range(0, 9):
            print(grid[a][b], end=' ')
        print()
