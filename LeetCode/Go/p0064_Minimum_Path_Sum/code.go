package p0064_Minimum_Path_Sum

func minPathSum(grid [][]int) int {
	dp := make([][]int, len(grid))
	for i := range dp {
		dp[i] = make([]int, len(grid[0]))
	}
	for i := 0; i < len(grid); i++ {
		for j := 0; j < len(grid[0]); j++ {
			if i == 0 && j == 0 {
				dp[0][0] = grid[0][0]
				continue
			}
			if i == 0 {
				dp[0][j] = dp[0][j-1] + grid[0][j]
				continue
			}
			if j == 0 {
				dp[i][0] = dp[i-1][0] + grid[i][0]
				continue
			}
			dp[i][j] = min(dp[i-1][j], dp[i][j-1]) + grid[i][j]
		}
	}
	return dp[len(grid)-1][len(grid[0])-1]
}

func min(i, j int) int {
	if i < j {
		return i
	}
	return j
}
