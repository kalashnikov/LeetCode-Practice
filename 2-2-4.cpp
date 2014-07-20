#include<iostream>
// 
// Remove Duplicate from Sorted List 
//

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) { }
};

ListNode *removeDup(ListNode* list){
    if(list==nullptr) return list;

    ListNode *nptr=list;
    int prev = list->val;
    for(ListNode *cur=list->next;cur!=nullptr;cur=cur->next){
        if(cur->val!=prev){
            nptr->next = cur;
            prev = cur->val;
            nptr = cur;
        }
    }

    // Remove the tail duplicated part 
    nptr->next = nullptr;

    return list;
}

int main(){
  
    ListNode* itr;

    ListNode* list1 = new ListNode(1);
    ListNode* lnptr = new ListNode(1);
    list1->next = lnptr;
    lnptr->next = new ListNode(3);
    lnptr = lnptr->next;
    lnptr->next = new ListNode(3);
    lnptr = lnptr->next;
    lnptr->next = new ListNode(2);
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

    list1 = removeDup(list1);
    
    itr = list1;
    printf("After: ");
    while(itr!=nullptr){
        printf("%d ",itr->val);
        itr = itr->next; 
    }
    printf("\n");

    return 0;
}
