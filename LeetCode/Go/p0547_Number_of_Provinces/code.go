package p0547_Number_of_Provinces

func findCircleNum(isConnected [][]int) int {
	n := len(isConnected)
	mark := make([]bool, n)
	res := 0
	var fuck func(i int)
	fuck = func(i int) {
		mark[i] = true
		con := isConnected[i]
		for k, v := range con {
			if !mark[k] && v == 1 {
				fuck(k)
			}
		}
	}
	for i := 0; i < n; i++ {
		if !mark[i] {
			res++
			fuck(i)
		}
	}
	return res
}
