/*

对链表进行插入排序。

	从第一个元素开始，该链表可以被认为已经部分排序（用黑色表示）。
	
	每次迭代时，从输入数据中移除一个元素（用红色表示），并原地将其插入到已排好序的链表中。

插入排序算法：

    插入排序是迭代的，每次只移动一个元素，直到所有元素可以形成一个有序的输出列表。
	
    每次迭代中，插入排序只从输入数据中移除一个待排序的元素，找到它在序列中适当的位置，并将其插入。
	
    重复直到所有输入数据插入完为止。

示例 1：

	输入: 4->2->1->3

	输出: 1->2->3->4

示例 2：

	输入: -1->5->3->4->0
	
	输出: -1->0->3->4->5

*/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* insertionSortList(ListNode* head) {
        if (head == NULL || head->next == NULL) return head;
        ListNode* sorthead = new ListNode();
        sorthead->next =NULL;
        ListNode* sort;
        ListNode* node = head;
        while (node)
        {
            ListNode* next = node->next;
            sort = sorthead;
            while (sort->next)
            {
                if (node->val < sort->next->val)
                    break;
                sort = sort->next;
            }
            node->next = sort->next;
            sort->next = node;
            node = next;
        }
        return sorthead->next;
    }
};