#include<iostream>
// 
// Partition List
// Given a value z, all nodes less than x comes 
// before nodes greater or equal to x.
//

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) { }
};

ListNode *partition(ListNode* list, int m){
    if(list==nullptr) return list;

    ListNode leftdummy(-1);
    ListNode rightdummy(-1);
    ListNode *lptr = &leftdummy;
    ListNode *rptr = &rightdummy;

    for(ListNode *cur=list;cur!=nullptr;cur=cur->next){
        if(cur->val < m){
            lptr->next = cur;
            lptr = cur;
        } else { 
            rptr->next = cur;
            rptr = cur;
        }
    }

    lptr->next = rightdummy.next;
    rptr->next = nullptr;

    return leftdummy.next;
}

int main(){
  
    ListNode* itr;

    ListNode* list1 = new ListNode(1);
    ListNode* lnptr = new ListNode(4);
    list1->next = lnptr;
    lnptr->next = new ListNode(3);
    lnptr = lnptr->next;
    lnptr->next = new ListNode(2);
    lnptr = lnptr->next;
    lnptr->next = new ListNode(5);
    lnptr = lnptr->next;
    lnptr->next = new ListNode(2);
    lnptr = lnptr->next;

    lnptr->next = nullptr;

    itr = list1;
    printf("Before: ");
    while(itr!=nullptr){
        printf("%d ",itr->val);
        itr = itr->next; 
    }
    printf("\n");

    // Reverse list in the selected interval
    // In-place
    list1 = partition(list1,3);
    
    itr = list1;
    printf("After: ");
    while(itr!=nullptr){
        printf("%d ",itr->val);
        itr = itr->next; 
    }
    printf("\n");

    return 0;
}
