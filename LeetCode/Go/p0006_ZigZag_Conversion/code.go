package p0006_ZigZag_Conversion

import "strings"

func convert(s string, numRows int) string {
	if numRows == 1 {
		return s
	}
	//存储每一行的字符串
	foo := make([]string, numRows)
	//排列方向，向下false，向上trueD
	d := false
	//处于第几行
	fuck := 0
	for i := 0; i < len(s); i++ {
		foo[fuck] += string(s[i])
		if !d {
			fuck++
		} else {
			fuck--
		}
		if fuck == 0 || fuck == len(foo)-1 {
			d = !d
		}
	}
	var sb strings.Builder
	for i := 0; i < len(foo); i++ {
		sb.WriteString(foo[i])
	}
	return sb.String()
}
