package p0200_Number_of_Islands

func numIslands(grid [][]byte) int {
	res := 0
	for i := range grid {
		shit := grid[i]
		for j := range shit {
			if shit[j] == '1' {
				fuck(grid, i, j)
				res++
			}
		}
	}
	return res
}

//fuck会从一个点开始，标记整个岛
func fuck(grid [][]byte, i int, j int) {
	if i < 0 || i >= len(grid) || j < 0 || j >= len(grid[0]) {
		return
	}
	if grid[i][j] == '1' {
		grid[i][j] = '2'
		fuck(grid, i, j-1)
		fuck(grid, i, j+1)
		fuck(grid, i-1, j)
		fuck(grid, i+1, j)
	}
}
