package p0024_Swap_Nodes_in_Pairs

type ListNode struct {
	Val  int
	Next *ListNode
}

//抄了大佬一手递归……太强大了
func swapPairs(head *ListNode) *ListNode {
	if head == nil || head.Next == nil {
		return head
	}

	newHead := head.Next
	head.Next = swapPairs(newHead.Next)
	newHead.Next = head

	return newHead
}
