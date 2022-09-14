package p0393_UTF_8_Validation

func validUtf8(data []int) bool {
	// 当前字符还有几个字节
	followLen := 0
	for _, x := range data {
		// x开头有多少个1
		var xLen int
		for i := 0; i < 8; i++ {
			if getbit(x, 7-i) == 1 {
				xLen++
			} else {
				break
			}
		}

		//fmt.Println("len", x, followLen, xLen)

		if xLen > 4 {
			return false
		}

		// 当前字符还没结束
		if followLen > 0 {
			// 当前byte不是10开头
			if xLen != 1 {
				return false
			}
			followLen--
		} else {
			// 现在是新字符的开始

			// 10不能是字符开头
			if xLen == 1 {
				return false
			}
			// 赋值当前字符长度
			if xLen > 1 {
				followLen = xLen - 1
			}
			// xLen==0是单字节
		}

	}

	return followLen == 0
}

func getbit(x int, n int) int {
	res := (x & (1 << n)) >> n
	//fmt.Println("bit", x, n, res)
	return res
}
