package p0148_Sort_List

type ListNode struct {
	Val  int
	Next *ListNode
}

func sortList(head *ListNode) *ListNode {
	if head == nil || head.Next == nil {
		return head
	}
	fast := head.Next
	slow := head
	for fast != nil && fast.Next != nil {
		fast = fast.Next.Next
		slow = slow.Next
	}
	tmp := slow.Next
	slow.Next = nil
	left := sortList(head)
	right := sortList(tmp)
	res := &ListNode{} //这个节点是为了写代码方便，最后要扔掉
	tmp = res
	for left != nil && right != nil {
		if left.Val < right.Val {
			tmp.Next = left
			left = left.Next
		} else {
			tmp.Next = right
			right = right.Next
		}
		tmp = tmp.Next
	}
	if left != nil {
		tmp.Next = left
	} else {
		tmp.Next = right
	}
	return res.Next
}
