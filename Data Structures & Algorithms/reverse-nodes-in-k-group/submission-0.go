/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */

func reverseKGroup(head *ListNode, k int) *ListNode {
    count := 0
    node := head
    for node != nil && count < k {
        node = node.Next
        count++
    }
    if count < k {
        return head
    }

    var prev *ListNode
    cur := head
    for range k {
        tmp := cur.Next
        cur.Next = prev
        prev = cur
        cur = tmp
    }

    head.Next = reverseKGroup(cur, k)
    return prev
}