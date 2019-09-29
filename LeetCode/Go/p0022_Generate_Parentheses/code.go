package p0022_Generate_Parentheses

func generateParenthesis(n int) []string {
	res := make([]string, 0, 16)
	findCase(n, n, "", &res)
	return res
}

//自己想的方法很蠢，还是参考了查到的递归方法
//left是（剩余个数，right是）剩余个数
//temp是当前拼的括号串
//结果存到res里，因为res很可能需要扩容，所以需要指针
func findCase(left int, right int, temp string, res *[]string) {
	//括号用完了，存结果
	if left == 0 && right == 0 {
		*res = append(*res, temp)
		return
	}
	//（只要有就随便加
	if left > 0 {
		findCase(left-1, right, temp+"(", res)
	}
	//）只要比left少就随便加，最后必然能匹配
	if right > left {
		findCase(left, right-1, temp+")", res)
	}
}
