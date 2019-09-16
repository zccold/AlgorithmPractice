package p0010_Regular_Expression_Matching

//isMatch 动态规划的太难写了，放弃，递归凑合一下好了
func isMatch(s string, p string) bool {
	//初始p不可能是*开头，并且递归的时候也没有让*开头的
	//0长度的p只能匹配0长度的s
	if len(p) == 0 {
		return len(s) == 0
	}
	//第一个字符是否匹配
	firstMatch := len(s) > 0 && (p[0] == '.' || p[0] == s[0])
	if len(p) >= 2 && p[1] == '*' {
		//出现了 x*的情况，可能会消掉x*或者一个x
		return isMatch(s, p[2:]) || firstMatch && isMatch(s[1:], p)
	} else {
		return firstMatch && isMatch(s[1:], p[1:])
	}
}
