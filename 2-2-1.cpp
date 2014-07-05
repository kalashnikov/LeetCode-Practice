#include<iostream>
// 
// Add Two Numbers 
// Linked List ver.
//

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) { }
};

ListNode *addTwoNum(ListNode* list1, ListNode* list2){
    if(list1==nullptr&&list2==nullptr) return nullptr;
    if(list1==nullptr) return list2;
    if(list2==nullptr) return list1;

    ListNode *nlist, *tptr, *ltptr;
    nlist = tptr = ltptr = nullptr;
    
    int tmp, carry = 0;
    while(list1!=nullptr){
        tmp     = list1->val + list2->val + carry;
        carry   = tmp/10;
        ltptr   = tptr; 
        tptr    = new ListNode(tmp%10);
        if(ltptr!=nullptr) ltptr->next = tptr;
        if(nlist==nullptr) nlist = tptr;
        
        // Next node
        list1=list1->next;
        list2=list2->next;
    }

    if(carry!=0){
        ltptr   = tptr; 
        tptr    = new ListNode(carry);
        if(ltptr!=nullptr) ltptr->next = tptr;
    }

    return nlist;
}


int main(){
   
    ListNode* list1;
    ListNode* list2;

    ListNode* lnptr1 = new ListNode(2);
    ListNode* lnptr2 = new ListNode(4);
    ListNode* lnptr3 = new ListNode(3);
    lnptr1->next = lnptr2;
    lnptr2->next = lnptr3;
    list1 = lnptr1;

    lnptr1 = new ListNode(5);
    lnptr2 = new ListNode(6);
    lnptr3 = new ListNode(4);
    lnptr1->next = lnptr2;
    lnptr2->next = lnptr3;
    list2 = lnptr1;

    ListNode* result = addTwoNum(list1,list2);
    while(result!=nullptr){
        printf("%d ",result->val);
        result=result->next;
    }
    printf("\n");

    return 0;
}
