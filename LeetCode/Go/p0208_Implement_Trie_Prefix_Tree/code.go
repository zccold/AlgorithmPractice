package p0208_Implement_Trie_Prefix_Tree

//因为输出都是a-z的字母，所以可以用数组优化，但是我懒得改了
type Trie struct {
	hasLeaf bool
	next    map[byte]*Trie
}

/** Initialize your data structure here. */
func Constructor() Trie {
	return Trie{
		hasLeaf: false,
		next:    make(map[byte]*Trie),
	}
}

/** Inserts a word into the trie. */
func (this *Trie) Insert(word string) {
	p := this
	for i := range word {
		b := word[i]
		if next, ok := p.next[b]; ok {
			p = next
		} else {
			nt := &Trie{
				hasLeaf: false,
				next:    make(map[byte]*Trie),
			}
			p.next[b] = nt
			p = nt
		}
	}
	p.hasLeaf = true
}

/** Returns if the word is in the trie. */
func (this *Trie) Search(word string) bool {
	p := this
	for i := range word {
		b := word[i]
		if next, ok := p.next[b]; ok {
			p = next
		} else {
			return false
		}
		if i == len(word) {
			return p.hasLeaf
		}
	}
	return p.hasLeaf
}

/** Returns if there is any word in the trie that starts with the given prefix. */
func (this *Trie) StartsWith(prefix string) bool {
	p := this
	for i := range prefix {
		b := prefix[i]
		if next, ok := p.next[b]; ok {
			p = next
		} else {
			return false
		}
		if i == len(prefix) {
			return true
		}
	}
	return true
}

/**
 * Your Trie object will be instantiated and called as such:
 * obj := Constructor();
 * obj.Insert(word);
 * param_2 := obj.Search(word);
 * param_3 := obj.StartsWith(prefix);
 */
