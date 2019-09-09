package p0008_String_to_Integer_atoi

import "math"

func myAtoi(str string) int {
	var ing bool  //进入数字
	var sign bool //true则为负数
	result := 0

	for i := 0; i < len(str); i++ {
		switch str[i] {
		case '0', '1', '2', '3', '4', '5', '6', '7', '8', '9':
			result = result*10 + int(str[i]-'0')
			if ing {
				if sign {
					if 0-result < math.MinInt32 {
						return math.MinInt32
					}
				} else if !sign {
					if result > math.MaxInt32 {
						return math.MaxInt32
					}
				}
			} else {
				ing = true
			}
		case '-':
			if ing {
				return mmp(result, sign)
			}
			ing = true
			sign = !sign
		case '+':
			if ing {
				return mmp(result, sign)
			}
			ing = true
		default:
			if ing {
				return mmp(result, sign)
			} else {
				if str[i] != ' ' {
					return 0
				}
			}
		}

	}
	return mmp(result, sign)
}

func mmp(n int, sign bool) int {
	if sign {
		return -n
	} else {
		return n
	}
}
