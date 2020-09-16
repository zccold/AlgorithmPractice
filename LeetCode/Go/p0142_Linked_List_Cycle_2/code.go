package p0142_Linked_List_Cycle_2

type ListNode struct {
	Val  int
	Next *ListNode
}

//我就不写不用map的，你来打我啊
func detectCycle(head *ListNode) *ListNode {
	m := make(map[*ListNode]struct{})
	for head != nil {
		if _, ok := m[head]; ok {
			return head
		} else {
			m[head] = struct{}{}
			head = head.Next
		}
	}
	return nil
}
