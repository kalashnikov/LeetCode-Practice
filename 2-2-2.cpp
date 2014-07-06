#include<iostream>
// 
// Reverse Linked List in selected Interval 
// 1<=m<=n<=length 
//

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) { }
};

ListNode *reverse(ListNode* list, int m, int n){
    if(m>n)           return list;
    if(list==nullptr) return list;
    
    int i,j;
    ListNode *nptr, *mptr, *tptr, *lptr;

    // Dummy Node at Head
    ListNode dummy(-1);
    dummy.next = list;

    // Index: n
    j=1, nptr = list;
    while(j++!=n) nptr=nptr->next;
    
    // Index: m-1
    if(m==1) {
        tptr = &dummy; 
    } else { 
        j=1, tptr = list;
        while(j++!=m-1) tptr=tptr->next;
    }

    // Index: m 
    mptr = tptr->next;

    // Head of reversed list
    tptr->next = nptr;

    // Change the list address
    if(m==1) list = tptr->next;
    
    // printf("%d %d %d\n", tptr->val, mptr->val, nptr->val);

    // Save the tail's next address
    lptr = nptr->next;

    while(nptr!=mptr){
        tptr = mptr;
        while(tptr->next!=nptr) tptr=tptr->next;
        nptr->next = tptr;
        nptr = tptr;
    }

    // Tail of reversed list
    mptr->next = lptr;

    return list;
}

int main(){
  
    ListNode* itr;

    ListNode* list1 = new ListNode(1);
    ListNode* lnptr = new ListNode(2);
    list1->next = lnptr;
    lnptr->next = new ListNode(3);
    lnptr = lnptr->next;
    lnptr->next = new ListNode(4);
    lnptr = lnptr->next;
    lnptr->next = new ListNode(5);
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
    list1 = reverse(list1,1,5);
    
    itr = list1;
    printf("After: ");
    while(itr!=nullptr){
        printf("%d ",itr->val);
        itr = itr->next; 
    }
    printf("\n");

    return 0;
}
