package p0061_Rotate_List

type ListNode struct {
	Val  int
	Next *ListNode
}

func rotateRight(head *ListNode, k int) *ListNode {
	if head == nil || head.Next == nil {
		return head
	}
	//算完长度，shit正好是最后一个节点
	tail := head
	length := 1
	for tail.Next != nil {
		length++
		tail = tail.Next
	}
	k = k % length
	if k == 0 {
		return head
	}
	newTail := head
	for i := 1; i < length-k; i++ {
		newTail = newTail.Next
	}
	newHead := newTail.Next
	newTail.Next = nil
	tail.Next = head
	return newHead
}
