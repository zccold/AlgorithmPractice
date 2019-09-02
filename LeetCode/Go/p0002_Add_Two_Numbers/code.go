package p0002_Add_Two_Numbers

type ListNode struct {
	Val  int
	Next *ListNode
}

func addTwoNumbers(l1 *ListNode, l2 *ListNode) *ListNode {
	res := &ListNode{}
	cur := res //当前节点
	carry := 0 //进位
	for {
		sum := 0
		if l1 != nil {
			sum += l1.Val
			l1 = l1.Next
		}
		if l2 != nil {
			sum += l2.Val
			l2 = l2.Next
		}
		sum += carry
		cur.Val = sum % 10
		carry = sum / 10
		//当l1、l2均计算完毕，且进位为0时，停止循环
		//否则，进入下一位
		if l1 != nil || l2 != nil || carry != 0 {
			cur.Next = &ListNode{}
			cur = cur.Next
		} else {
			break
		}
	}
	return res
}
