struct ListNode {
    int val;
    struct ListNode *next;
};
 //��ʹ��ͷ�����ɵ�����ĺϲ�
struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2) {
	if (l1 == NULL)
		return l2;
	if (l2 == NULL)
		return l1;
	struct ListNode* NewH, *NewT;//ָ�� �µ�ͷ���µ�β
	if (l1->val <= l2->val) {
		NewH = NewT = l1;
		l1 = l1->next;
	}
	else {
		NewH = NewT = l2;
		l2 = l2->next;
	}
	while (l1&&l2) {
		if (l1->val <= l2->val) {
			NewT->next = l1;
			l1 = l1->next;
		}
		else {
			NewT->next = l2;
			l2 = l2->next;
		}
		NewT = NewT->next;
	}
	if (l1) {
		NewT->next = l1;
	}
	if (l2) {
		NewT->next = l2;
	}
	return NewH;
}

//����ͷ���������������ϲ�
struct ListNode {
	int val;
	struct ListNode *next;
};
struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2) {
	struct ListNode* NewH, *NewT, *tmp;
	if (l1 == NULL)
		return l2;
	if (l2 == NULL)
		return l1;
	NewH = NewT = (struct ListNode*)malloc(sizeof(struct ListNode));//ͷ���  ���洢����
	while (l1 &&l2) {
		if (l1->val <= l2->val) {
			NewT->next = l1;
			l1 = l1->next;
		}
		else {
			NewT->next = l2;
			l2 = l2->next;
		}
		NewT = NewT->next;
	}
	if (l1) {
		NewT->next = l1;
	}
	if (l2) {
		NewT->next = l2;
	}
	tmp = NewH;
	NewH = NewH->next;
	free(tmp);
	return NewH;
}


struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};
class Partition {
public:
	ListNode* partition(ListNode* pHead, int x) {
		struct ListNode* LH, *LT, *GH, *GT, *cur;
		if (pHead == NULL)
			return NULL;
		LH = LT = (struct ListNode*)malloc(sizeof(struct ListNode));
		GH = GT = (struct ListNode*)malloc(sizeof(struct ListNode));
		cur = pHead;
		while (cur) {
			if (cur->val < x) {
				LT->next = cur;
				LT = LT->next;
			}
			else {
				GT->next = cur;
				GT = GT->next;
			}
			cur = cur->next;
		}
		GT->next = NULL;
		//����������ƴ������
		LT->next = GH->next;
		LT = LH;
		GT = GH;
		LH = LH->next;
		free(LT);
		free(GT);
		return LH;
	}
};

struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
}; 
class PalindromeList {
public:
	bool chkPalindrome(ListNode* A) {
		struct ListNode* slow, *fast, *prev, *cur, *next;
		if (A == NULL || A->next == NULL)
			return true;
		//���ÿ���ָ��,Ѱ���м�λ��
		slow = fast = A;
		while (fast && fast->next) {
			slow = slow->next;
			fast = fast->next->next;
		}
		//����ͷ����ɺ�벿�ַ�ת
		prev = NULL;
		cur = slow;
		while (cur) {
			next = cur->next;
			//ͷ��
			cur->next = prev;
			prev = cur;
			cur = next;
		}
		cur = prev;
		//�Ƚ�
		while (A && cur) {
			if (A->val != cur->val) {
				return false;
			}
			A = A->next;
			cur = cur->next;
		}
		return true;
	}
};


 Definition for singly-linked list.
 struct ListNode {
     int val;
     struct ListNode *next;
 };
struct ListNode *getIntersectionNode(struct ListNode *headA, struct ListNode *headB) {
	struct ListNode* curA, *curB;
	if (headA == NULL || headB == NULL)
		return NULL;
	curA = headA;
	curB = headB;
	int lenA, lenB;
	lenA = lenB = 0;
	while (curA) {
		lenA++;
		curA = curA->next;
	}
	while (curB) {
		lenB++;
		curB = curB->next;
	}
	//�����ֵ
	int gap = abs(lenA - lenB);
	//����lenA��
	curA = headA;
	curB = headB;
	if (lenA < lenB) {
		curA = headB;
		curB = headA;
	}
	while (gap--) {
		curA = curA->next;
	}
	while (curA&&curB) {
		if (curA == curB) {
			return curA;
		}
		curA = curA->next;
		curB = curB->next;
	}
	return NULL;
}


struct ListNode {
	int val;
	struct ListNode *next;
};
bool hasCycle(struct ListNode *head) {
	struct ListNode* slow, *fast;
	if (head == NULL)
		return false;
	slow = fast = head;
	while (fast && fast->next) {
		slow = slow->next;
		fast = fast->next->next;
		if (fast == slow)
			return true;
	}
	return false;
}


struct ListNode {
	int val;
	struct ListNode *next;
	
};
struct ListNode* hasCycle(struct ListNode *head) {
	struct ListNode* slow, *fast;
	if (head == NULL)
		return NULL;
	slow = fast = head;
	while (fast && fast->next) {
		slow = slow->next;
		fast = fast->next->next;
		if (fast == slow)
			return fast;
	}
	return NULL;
}
struct ListNode *detectCycle(struct ListNode *head) {
	struct ListNode* cur;
	cur = hasCycle(head);
	if (cur) {
		while (cur->val != head->val) {
			cur = cur->next;
			head = head->next;
		}
		return cur;
	}
	return NULL;
}

struct Node {
	int val;
	struct TreeNode *next;
	struct TreeNode *random;
};
  
struct Node* copyRandomList(struct Node* head) {
	struct Node* cur, *copy, *next, *newH;
	if (head == NULL)
		return NULL;
	//����
	cur = head;
	while (cur) {
		next = cur->next;
		copy = (struct Node*) malloc(sizeof(struct Node));
		copy->val = cur->val;

		cur->next = copy;
		copy->next = next;

		cur = next;
	}

	//����random
	cur = head;
	while (cur) {
		copy = cur->next;
		next = copy->next;
		if (cur->random)
			copy->random = cur->random->next;
		else
			copy->random = NULL;
		cur = next;

	}

	//����
	cur = head;
	newH = cur->next;
	while (cur) {
		copy = cur->next;
		next = copy->next;

		if (next)
			copy->next = next->next;
		else
			copy->next = NULL;
		cur = next;
	}
	return newH;
}