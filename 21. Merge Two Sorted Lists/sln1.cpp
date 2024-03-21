#include <iostream>

using namespace std;


struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* t1 = list1;           // storing `head`
        ListNode* t2 = list2;
        ListNode* res = new ListNode(-101); // creating list with `answer`, -101 because of constraints in task
        ListNode* resHead = res; // storing `res` head
        while (t1 != nullptr && t2 != nullptr) {
            if (t1->val < t2->val)      //compare values
            {    
                res->next = t1;         //adding minimum-value to res
                t1 = t1->next;          //moving forward in list1
            } 
            else 
            {
                res->next = t2;
                t2 = t2->next;
            }
            res = res->next;            //moving forward in res
        }

        res->next = (t1 != nullptr) ? t1 : t2;   // for the case when one list is shorter than the other

        return resHead->next;
    }
};

int main ()
{
    Solution s;
    ListNode *LL;
    ListNode *RR;
    ListNode *headLL;
    ListNode *headRR;
    
    LL=new ListNode(1);
    headLL=LL;
    LL->next = new ListNode(2);
    LL=LL->next;
    LL->next = new ListNode(4);
    LL=LL->next;

    RR=new ListNode(1);
    headRR=RR;
    RR->next = new ListNode(3);
    RR=RR->next;
    RR->next = new ListNode(4);
    RR=RR->next;
    

    ListNode* res = s.mergeTwoLists(headLL,headRR);
    
    while(res!=NULL)
    {
        cout<<res->val<<" ";
        res=res->next;
    }
    
    return 0;
}