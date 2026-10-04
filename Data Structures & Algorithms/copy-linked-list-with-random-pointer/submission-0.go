/**
 * Definition for a Node.
 * type Node struct {
 *     Val int
 *     Next *Node
 *     Random *Node
 * }
 */

func copyRandomList(head *Node) *Node {
    oldToCopy := make(map[*Node]*Node)
	oldToCopy[nil] = nil

	cur := head
	for cur != nil {
		if _, exists := oldToCopy[cur]; !exists {
			oldToCopy[cur] = &Node{Val: cur.Val}
		}
		if cur.Next != nil {
			if _, exists := oldToCopy[cur.Next]; !exists {
				oldToCopy[cur.Next] = &Node{Val: cur.Next.Val}
			}
			oldToCopy[cur].Next = oldToCopy[cur.Next]
		}
		if cur.Random != nil {
			if _, exists := oldToCopy[cur.Random]; !exists {
				oldToCopy[cur.Random] = &Node{Val: cur.Random.Val}
			}
			oldToCopy[cur].Random = oldToCopy[cur.Random]
		}
		cur = cur.Next
	}
	return oldToCopy[head]
}
