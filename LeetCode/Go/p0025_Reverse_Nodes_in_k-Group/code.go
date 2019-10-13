package p0025_Reverse_Nodes_in_k_Group

type ListNode struct {
	Val  int
	Next *ListNode
}

//很明显和24题一样，可以搞一手递归，今天实在太困了，直接copy了代码
func reverseKGroup(head *ListNode, k int) *ListNode {
	if k < 2 || head == nil || head.Next == nil {
		return head
	}

	tail, needReverse := getTail(head, k)

	if needReverse {
		tailNext := tail.Next
		/* 斩断 tail 后的链接 */
		tail.Next = nil
		head, tail = reverse(head, tail)
		/* tail 后面接上尾部的递归处理 */
		tail.Next = reverseKGroup(tailNext, k)
	}

	return head
}

func getTail(head *ListNode, k int) (*ListNode, bool) {
	for k > 1 && head != nil {
		head = head.Next
		k--
	}
	return head, k == 1 && head != nil
}

func reverse(head, tail *ListNode) (*ListNode, *ListNode) {
	curPre, cur := head, head.Next
	for cur != nil {
		curPre, cur, cur.Next = cur, cur.Next, curPre
	}
	return tail, head
}
