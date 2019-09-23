package p0017_Letter_Combinations_of_a_Phone_Number

func letterCombinations(digits string) []string {
	if len(digits) == 0 {
		return nil
	}
	m := make(map[byte][]string)
	m['2'] = []string{"a", "b", "c"}
	m['3'] = []string{"d", "e", "f"}
	m['4'] = []string{"g", "h", "i"}
	m['5'] = []string{"j", "k", "l"}
	m['6'] = []string{"m", "n", "o"}
	m['7'] = []string{"p", "q", "r", "s"}
	m['8'] = []string{"t", "u", "v"}
	m['9'] = []string{"w", "x", "y", "z"}
	res := []string{""}
	//按位看
	for i := 0; i < len(digits); i++ {
		letters := m[digits[i]]
		temp := make([]string, 0, len(res)*len(letters))
		//取之前部分的结果
		for j := 0; j < len(letters); j++ {
			//拼接上当前这位的各种可能
			for k := 0; k < len(res); k++ {
				temp = append(temp, res[k]+letters[j])
			}
		}
		//然后就OK了
		res = temp
	}
	return res
}
