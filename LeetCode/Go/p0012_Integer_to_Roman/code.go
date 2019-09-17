package p0012_Integer_to_Roman

import "strings"

/*
之前一直看不懂罗马数字的规则……
其实类似十进制，每一位最多十
这个题可以当做最高位是"M"位，算算有几个，
然后下一位是"CM"位，算算有几个，以此类推
因为规则挺少的，直接强撸进代码就行了，也不需要生成这些东西
*/
func intToRoman(num int) string {
	var sb strings.Builder
	for num >= 1000 {
		sb.WriteString("M")
		num -= 1000
	}
	if num >= 900 {
		sb.WriteString("CM")
		num -= 900
	}
	if num >= 500 {
		sb.WriteString("D")
		num -= 500
	}
	if num >= 400 {
		sb.WriteString("CD")
		num -= 400
	}
	for num >= 100 {
		sb.WriteString("C")
		num -= 100
	}
	if num >= 90 {
		sb.WriteString("XC")
		num -= 90
	}
	if num >= 50 {
		sb.WriteString("L")
		num -= 50
	}
	if num >= 40 {
		sb.WriteString("XL")
		num -= 40
	}
	for num >= 10 {
		sb.WriteString("X")
		num -= 10
	}
	if num >= 9 {
		sb.WriteString("IX")
		num -= 9
	}
	if num >= 5 {
		sb.WriteString("V")
		num -= 5
	}
	if num >= 4 {
		sb.WriteString("IV")
		num -= 4
	}
	for num >= 1 {
		sb.WriteString("I")
		num -= 1
	}
	return sb.String()
}

/*
Symbol       Value
I             1
V             5
X             10
L             50
C             100
D             500
M             1000
*/
