class Solution {
public:
	int countList(ListNode* node) {
		int count = 0;
		while(node != NULL) {
			count++;
			node = node->next;
		}
		return count;
	}

	ListNode* mergeSort(ListNode* node, int count) {
		if (count == 1) {
			return node;
		}

		int firstListCount = count / 2;
		int secondListCount = count - firstListCount;

		ListNode* firstList = node;
		for(int i = 0; i < firstListCount - 1; ++i) {
			node = node->next;
		}
		ListNode* secondList = node->next;
		node->next = NULL;

		firstList = mergeSort(firstList, firstListCount);
		secondList = mergeSort(secondList, secondListCount);

		ListNode head(0);
		ListNode *curr = &head;

		while(firstList != NULL && secondList != NULL) {
			if (firstList->val < secondList->val) {
				curr->next = firstList;
				firstList = firstList->next;
			} else {
				curr->next = secondList;
				secondList = secondList->next;
			}
			curr = curr->next;
		}
		curr->next = (firstList == NULL) ? secondList : firstList;

		return head.next;
	}

	ListNode* sortList(ListNode* head) {
		int count = countList(head);

		if (count == 0 || count == 1) {
			return head;
		}

		return mergeSort(head, count);
	}
};