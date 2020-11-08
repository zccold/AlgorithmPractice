package p0221_Maximal_Square

func maximalSquare(matrix [][]byte) int {
	dp := make([][]int, len(matrix))
	for i := range dp {
		dp[i] = make([]int, len(matrix[0]))
	}

	res := 0
	//dp记录了以这个点为右下角的正方形最大边长
	for i := range dp {
		for j := range dp[i] {
			if matrix[i][j] == '0' { //这个点为0，咋也不行
			} else if i-1 < 0 || j-1 < 0 { //左或上到头了，只能是1了
				dp[i][j] = 1
				if res == 0 {
					res = 1
				}
			} else {
				tmpMax := dp[i-1][j-1] + 1
				tmp := 1
				for tmp < tmpMax {
					if matrix[i][j-tmp] == '1' && matrix[i-tmp][j] == '1' {
						tmp++
					} else {
						break
					}
				}
				dp[i][j] = tmp
				if res < tmp {
					res = tmp
				}
			}
		}
	}

	return res * res
}
