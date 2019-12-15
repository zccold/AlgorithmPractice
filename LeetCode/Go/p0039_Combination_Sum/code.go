package p0039_Combination_Sum

import (
	"sort"
	"strconv"
	"strings"
)

func combinationSum(candidates []int, target int) [][]int {
	if target <= 0 {
		return [][]int{}
	}
	dp := make([]map[string]interface{}, target+1)
	for i := 0; i < len(dp); i++ {
		dp[i] = make(map[string]interface{})
	}
	dp[0][""] = true
	for i := 1; i < len(dp); i++ {
		for _, v := range candidates {
			if i-v >= 0 {
				for k := range dp[i-v] {
					slice := append(str2slice(k), v)
					sort.Ints(slice)
					dp[i][slice2str(slice)] = true
				}
			}
		}
	}
	var res [][]int
	for k := range dp[target] {
		res = append(res, str2slice(k))
	}
	return res
}

func slice2str(slice []int) string {
	if len(slice) == 0 {
		return ""
	}
	var sb strings.Builder
	for _, v := range slice {
		if sb.Len() > 0 {
			sb.WriteByte(',')
		}
		sb.WriteString(strconv.Itoa(v))
	}
	return sb.String()
}

func str2slice(str string) []int {
	if str == "" {
		return []int{}
	}
	strSlice := strings.Split(str, ",")
	slice := make([]int, len(strSlice))
	for k, v := range strSlice {
		slice[k], _ = strconv.Atoi(v)
	}
	return slice
}
