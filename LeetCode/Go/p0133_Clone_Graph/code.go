package p0133_Clone_Graph

type Node struct {
	Val       int
	Neighbors []*Node
}

//key是旧的，v是新的
var nodeMap = make(map[*Node]*Node)

func cloneGraph(node *Node) *Node {
	if node == nil {
		return nil
	}
	newNode := &Node{
		Val:       node.Val,
		Neighbors: make([]*Node, 0, len(node.Neighbors)),
	}
	nodeMap[node] = newNode
	for _, neiOld := range node.Neighbors {
		if neiNew, ok := nodeMap[neiOld]; ok {
			newNode.Neighbors = append(newNode.Neighbors, neiNew)
		} else {
			newNode.Neighbors = append(newNode.Neighbors, cloneGraph(neiOld))
		}
	}
	return newNode
}
