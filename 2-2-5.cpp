#include<iostream>
// 
// Remove Duplicate from Sorted List 
// Leave only distinct value
//

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) { }
};

ListNode *removeDup(ListNode* list){
    if(list==nullptr) return list;

    ListNode newList(-1);
    ListNode *nptr = &newList;

    ListNode *tptr,*cur=list;
    while(cur!=nullptr){
        tptr = cur->next; 
        while(tptr!=nullptr && tptr->val==cur->val){ 
            tptr=tptr->next;
        }
        if(tptr==cur->next){
            nptr->next = cur;
            nptr = cur;
        }
        cur = tptr;
    }

    // Remove the tail duplicated part 
    nptr->next = nullptr;

    return newList.next;
}

int main(){
  
    ListNode* itr;

    ListNode* list1 = new ListNode(1);
    ListNode* lnptr = new ListNode(1);
    list1->next = lnptr;
    lnptr->next = new ListNode(1);
    lnptr = lnptr->next;
    lnptr->next = new ListNode(2);
    lnptr = lnptr->next;
    lnptr->next = new ListNode(3);
    lnptr = lnptr->next;
    lnptr->next = new ListNode(3);
    lnptr = lnptr->next;
    lnptr->next = new ListNode(4);
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
