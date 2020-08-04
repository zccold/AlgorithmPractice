package p0207_Course_Schedule

import "container/list"

type Course struct {
	prev int   //需要的前置课程数
	post []int //后置课程列表
}

func canFinish(numCourses int, prerequisites [][]int) bool {
	cl := make([]Course, numCourses)
	for i := range cl {
		cl[i].post = make([]int, 0)
	}
	for _, rule := range prerequisites {
		prev := rule[1]
		post := rule[0]
		cl[prev].post = append(cl[prev].post, post)
		cl[post].prev++
	}
	l := list.New()
	count := 0
	for i, c := range cl {
		if c.prev == 0 {
			count++
			l.PushBack(i)
		}
	}
	for l.Len() > 0 {
		ie := l.Front()
		l.Remove(ie)
		i := ie.Value.(int)
		c := &cl[i]
		for _, cpi := range c.post {
			cp := &cl[cpi]
			cp.prev--
			if cp.prev == 0 {
				count++
				l.PushBack(cpi)
			}
		}
	}
	return count == numCourses
}
