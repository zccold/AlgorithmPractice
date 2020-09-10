package p0040_Combination_Sum_2

import (
	"sort"
	"strconv"
	"strings"
)

//dp[i]里存了组成i的方案，因为没有set用，所以搞了个map，然后为了能在key里用，拼成了字符串
func combinationSum2(candidates []int, target int) [][]int {
	if target <= 0 {
		return [][]int{}
	}
	countMap := make(map[int]int)
	for _, v := range candidates {
		countMap[v] = countMap[v] + 1
	}
	dp := make([]map[string]struct{}, target+1)
	for i := 0; i < len(dp); i++ {
		dp[i] = make(map[string]struct{})
	}
	dp[0][""] = struct{}{}
	for i := 1; i < len(dp); i++ {
		for _, v := range candidates {
			if i-v >= 0 {
			xxx:
				for k := range dp[i-v] {
					sliceOld := str2slice(k)
					if countInSlice(sliceOld, v) >= countMap[v] {
						continue xxx
					}
					slice := append(sliceOld, v)
					sort.Ints(slice)
					dp[i][slice2str(slice)] = struct{}{}
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

func countInSlice(slice []int, num int) int {
	count := 0
	for _, v := range slice {
		if v == num {
			count++
		}
	}
	return count
}
