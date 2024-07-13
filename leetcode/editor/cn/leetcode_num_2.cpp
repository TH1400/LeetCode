//import universal *.h
#include "../../../stdc.h"

using namespace std;


//给你两个 非空 的链表，表示两个非负的整数。它们每位数字都是按照 逆序 的方式存储的，并且每个节点只能存储 一位 数字。 
//
// 请你将两个数相加，并以相同形式返回一个表示和的链表。 
//
// 你可以假设除了数字 0 之外，这两个数都不会以 0 开头。 
//
// 
//
// 示例 1： 
// 
// 
//输入：l1 = [2,4,3], l2 = [5,6,4]
//输出：[7,0,8]
//解释：342 + 465 = 807.
// 
//
// 示例 2： 
//
// 
//输入：l1 = [0], l2 = [0]
//输出：[0]
// 
//
// 示例 3： 
//
// 
//输入：l1 = [9,9,9,9,9,9,9], l2 = [9,9,9,9]
//输出：[8,9,9,9,0,0,0,1]
// 
//
// 
//
// 提示： 
//
// 
// 每个链表中的节点数在范围 [1, 100] 内 
// 0 <= Node.val <= 9 
// 题目数据保证列表表示的数字不含前导零 
// 
//
// Related Topics 递归 链表 数学 👍 10675 👎 0


namespace solution2{
    //leetcode submit region begin(Prohibit modification and deletion)
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *head = nullptr;
        ListNode *res = nullptr;
        int tmp_num = 0;
        int cur_num = 0;
        while (l1 != nullptr or l2 != nullptr){
            int num1 = l1 ? l1->val:0;
            int num2 = l2 ? l2->val:0;
            cur_num = num1 + num2 + tmp_num;
            if (cur_num >= 10){
                tmp_num = 1;
                cur_num = cur_num - 10;
            } else {
                tmp_num = 0;
            }
            if (head == nullptr){
                head = res = new ListNode(cur_num);
            } else {
                res->next = new ListNode(cur_num);
                res = res->next;
            }
            if (l1){
                l1 = l1->next;
            }
            if (l2){
                l2 = l2->next;
            }
        }
        if (tmp_num){
            res->next = new ListNode(tmp_num);
        }
        return head;
    }
};
//leetcode submit region end(Prohibit modification and deletion)

}

using namespace solution2;
#define L1 "[9,9,9,9,9,9,9]"
#define L2 "[9,9,9,9]"
#define RESULT "[8,9,9,9,0,0,0,1]"
int main() {
    Solution solution = Solution();
    ListNode *node = solution.addTwoNumbers(stringToListNode(L1), stringToListNode(L2));
    cout << listNodeToString(node) << endl;
    assert(RESULT == listNodeToString(node));
    return 0;
}