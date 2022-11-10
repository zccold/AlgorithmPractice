package p1047_Remove_All_Adjacent_Duplicates_In_String

import "log"

// 英语不好，提交才发现只能两个两个消，三个要剩一个
func removeDuplicates(s string) string {
	h := new(heap)
	for i := range s {
		char := s[i]
		if char == h.top() { //匹配成功
			log.Println("fucking:", char)
			h.pop()
			i++
		} else { //匹配失败
			// 把当前字符放进去
			h.push(char)
			i++
		}
	}
	return string(h.shit)
}

type heap struct {
	shit []byte
}

func (h *heap) push(i byte) {
	h.shit = append(h.shit, i)
}
func (h *heap) top() byte {
	if len(h.shit) == 0 {
		return ' '
	}
	return h.shit[len(h.shit)-1]
}
func (h *heap) pop() byte {
	if len(h.shit) == 0 {
		return ' '
	}
	i := h.shit[len(h.shit)-1]
	h.shit = h.shit[:len(h.shit)-1]
	return i
}
