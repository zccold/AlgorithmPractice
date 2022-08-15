package p0212_Word_Search_2

func findWords(board [][]byte, words []string) []string {
	t := NewTrie()
	for _, word := range words {
		t.Insert(word)
	}
	res := make([]string, 0)
	var fuck func(i, j int, prefix string, node *Trie)
	fuck = func(i, j int, prefix string, node *Trie) {
		if i < 0 || j < 0 || i >= len(board) || j >= len(board[0]) {
			return
		}
		c := board[i][j]
		if c == '#' {
			return
		}
		word := prefix + string([]byte{c})
		if next := node.next[int(c-'a')]; next != nil {
			if next.hasLeaf {
				res = append(res, word)
				next.hasLeaf = false //去重
				// 还可以进一步优化，如果叶子都没了，可以剪枝

			}
			board[i][j] = '#'
			fuck(i-1, j, word, next)
			fuck(i+1, j, word, next)
			fuck(i, j-1, word, next)
			fuck(i, j+1, word, next)
			board[i][j] = c
		}
	}
	for i := range board {
		for j := range board[i] {
			fuck(i, j, "", t)
		}
	}
	return res
}

type Trie struct {
	hasLeaf bool
	next    [26]*Trie
}

func NewTrie() *Trie {
	return &Trie{
		hasLeaf: false,
		next:    [26]*Trie{},
	}
}

func (t *Trie) Insert(word string) {
	p := t
	for i := range word {
		b := word[i]
		if next := p.next[int(b-'a')]; next != nil {
			p = next
		} else {
			nt := &Trie{
				hasLeaf: false,
				next:    [26]*Trie{},
			}
			p.next[int(b-'a')] = nt
			p = nt
		}
	}
	p.hasLeaf = true
}
