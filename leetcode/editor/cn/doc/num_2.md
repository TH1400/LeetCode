# 链表操作

1.创建新的链表

创建一个新的列表，并对列表进行元素的增删，需要创建两个指针，一个头指针，一个尾指针。

	1. 先对头尾指针同时赋值，指向同一个地址
	1. 然后给尾指针赋值，并将尾指针指向下一个地址

```cpp
        	// 先初始化头指针，再初始化尾指针
		    ListNode *head = nullptr;
        	ListNode *res = nullptr;
			// 判断头指针是否存在
            if (head == nullptr){
                head = res = new ListNode(cur_num);
            } else {
                res->next = new ListNode(cur_num);
                res = res->next;
            }

```

2. 取指针的值，并指向下一个

   ```
   初始化
   ListNode *num = l1;
   取最前面的值
   num1 = num->val;
   指向下一个指针
   num = num->next;
   ```

3. 判断指针是否为空（若为空，指定值）

   使用条件表达式

   ```
   int num1 = l1 ? l1->val:0;
   l1 是一个指针，表示链表 l1 的当前节点。
   l1 ? l1->val : 0; 表达式的意思是：
   如果 l1 非空（即指向有效节点），则取 l1->val，即当前节点的值。
   如果 l1 为空（即指向 nullptr），则取 0
   ```