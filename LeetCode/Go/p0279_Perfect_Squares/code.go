package p0279perfectsquares

func numSquares(n int) int {
	squares := getSquares(n)
	shit := make([]int, n+1)
	min := func(n int) int {
		tmp := n
		for i := range squares {
			s := squares[len(squares)-i-1]
			lastIndex := n - s
			if lastIndex >= 0 {
				last := shit[lastIndex]
				if last+1 < tmp {
					//log.Println("index", n, "lastIndex", lastIndex, "s", s)
					tmp = last + 1
				}
			}
		}
		return tmp
	}
	for i := 1; i < len(shit); i++ {
		shit[i] = min(i)
	}
	//log.Println(shit)
	return shit[n]
}

func getSquares(n int) []int {
	res := make([]int, 0)
	i := 1
	for {
		shit := i * i
		if shit > n {
			return res
		}
		res = append(res, shit)
		i++
	}
}
