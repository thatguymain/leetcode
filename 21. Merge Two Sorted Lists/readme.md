
# 21. Merge Two Sorted Lists
__________________
You are given the heads of two sorted linked lists `list1` and `list2`.

Merge the two lists into one **sorted** list. The list should be made by splicing together the nodes of the first two lists.

Return *the head of the merged linked list*.
 
__________________

### Example 1:

**Input:** list1 = [1,2,4], list2 = [1,3,4]

**Output:** [1,1,2,3,4,4]

### Example 2:

**Input:** list1 = [], list2 = []

**Output:** []

### Example 3:

**Input:** list1 = [], list2 = [0]

**Output:** [0]
 

### Constraints:

+ The number of nodes in both lists is in the range `[0, 50]`.
+ `-100 <= Node.val <= 100`
+ Both `list1` and `list2` are sorted in **non-decreasing** order.

__________________

## Solution

Finally we got something new, today we will be working on an "linked list". We have realisation of `node` given by leetcode, it look like this

```cpp
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
        
    }
};
```
our task is to merge two list's, lets take a tep back and create this list's first to better understand how do they works. Lets start coding by first implementing the List class that defines the structure of our linked list 

```cpp
class List
{
private:
    ListNode *head; 
public:
    List() 
    {
        head = NULL; 
    }
    void addNode(int d);
    void printList();
};
```

then we should define addNode function

```cpp
void addNode(int d)
    {
        Node *nd = new Node; 
        nd->val = d;        //init data
        nd->next = NULL;     //in this implementationwe always add a last element to the list,the next element will be NULL
        if(head == NULL)     //if we create first element
            head = nd;
        else                 //if we create non-first element
        {
            ListNode *current = head;
            while(current->next != NULL) // we go throught list untill we find the last element
                current = current->next;
            current->next = nd; // now our newly created Node weill be the last one
        }
    }
```

now we should define printList() function

```cpp
void printList()
    {
        ListNode *current = head;
        while(current != NULL)
        {
            cout << current->val << endl;
            current = current->next;
        }
    }


```

and finally, now we can create linked list

```cpp
int main()
{
    List LL, RR;
    LL.addNode(1);
    LL.addNode(2);
    LL.addNode(4);
    RR.addNode(1);
    RR.addNode(3);
    RR.addNode(4);

    LL.printList();
    cout<<"______\n";
    RR.printList();
    
    return 0;
}
```

Good, this is a normal linked list implementation. Now that we've refreshed our memory lets try to look at the conditions again. Given function `mergeTwoLists` takes ListNode* list1, ListNode* list2. This means that the leetcode has already created linked list somewhere and is only giving us the `head` of each list, so if we want to print this list we can dimply do it in the `mergeTwoLists` fuction using the following code

```cpp
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        while(list1 != NULL)
        {
            cout << list1->val << endl;
            list1 = list1->next;
        }
        return nullptr;
    }
};
```
But you should remember, if you modificate `list1` you can never get back to `head` of list, because this list is one-way linked, you can move only forward. But you can store `head` in some variable like `ListNode* t1=list1`. 
There are several ways to get the solution, 1 - we can use recursive code, 2 - we can compare values from two lists and insert one into the other, 3 - we can compare values and add the minimum value to a new linked list. Solution #1 doesnt look very good, because we have 2 lists, so we might have to call recursion twice and the time complexity would be around O (2^n). Solution #2 & #3 differ in the amount of memory they take. Lets try to implement solution #3;

```cpp
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
```

We got the solution, it works, its simple, the time complexity is O(n), where n is the total number of nodes in both lists
