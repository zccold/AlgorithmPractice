package p0155_Min_Stack

import "container/list"

//Methods pop, top and getMin operations will always be called on non-empty stacks.
//所以又很多破事是不用考虑的
type MinStack struct {
	list    *list.List
	minList *list.List
}

/** initialize your data structure here. */
func Constructor() MinStack {
	return MinStack{
		list:    list.New(),
		minList: list.New(),
	}
}

func (this *MinStack) Push(x int) {
	this.list.PushBack(x)
	if this.minList.Len() == 0 {
		this.minList.PushBack(x)
	} else {
		min := this.minList.Back().Value.(int)
		if x <= min {
			this.minList.PushBack(x)
		}
	}
}

func (this *MinStack) Pop() {
	e := this.list.Back()
	top := this.list.Remove(e).(int)
	if top == this.GetMin() {
		this.minList.Remove(this.minList.Back())
	}
}

func (this *MinStack) Top() int {
	return this.list.Back().Value.(int)
}

func (this *MinStack) GetMin() int {
	return this.minList.Back().Value.(int)
}

/**
 * Your MinStack object will be instantiated and called as such:
 * obj := Constructor();
 * obj.Push(x);
 * obj.Pop();
 * param_3 := obj.Top();
 * param_4 := obj.GetMin();
 */
