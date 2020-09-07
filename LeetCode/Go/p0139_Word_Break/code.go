package p0139_Word_Break

func wordBreak(s string, wordDict []string) bool {
	//题目说non-empty
	dp := make([]bool, len(s)+1)
	dp[0] = true
	for i := 1; i < len(dp); i++ {
		for _, word := range wordDict {
			preLen := i - len(word)
			if preLen < 0 {
				continue
			} else if !dp[preLen] {
				continue
			} else if s[preLen:i] == word {
				dp[i] = true
				break
			}
		}
	}
	return dp[len(s)]
}
