package p0072_Edit_Distance

func minDistance(word1 string, word2 string) int {
	if len(word1) == 0 {
		return len(word2)
	} else if len(word2) == 0 {
		return len(word1)
	}
	dp := make([][]int, len(word1)+1)
	for i := range dp {
		dp[i] = make([]int, len(word2)+1)
	}

	min := func(a, b, c int) int {
		if a < b {
			if a < c {
				return a
			} else {
				return c
			}
		} else {
			if b < c {
				return b
			} else {
				return c
			}
		}
	}

	for i := 0; i < len(word1)+1; i++ {
		for j := 0; j < len(word2)+1; j++ {
			if i == 0 {
				dp[i][j] = j
			} else if j == 0 {
				dp[i][j] = i
			} else if word1[i-1] == word2[j-1] {
				dp[i][j] = dp[i-1][j-1]
			} else {
				dp[i][j] = min(dp[i-1][j-1], dp[i][j-1], dp[i-1][j]) + 1
			}
		}
	}
	return dp[len(word1)][len(word2)]
}
