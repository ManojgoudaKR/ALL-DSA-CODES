/*You�re given a doubly-linked list with N nodes, where each node deviates at max K position from its position in the sorted list. Your task is to sort this given doubly linked list. For Example : Let us consider K is 3, an element at position 4 in the sorted doubly linked list, can be at positions 1, 2, 3, 4, 5, 6, 7 in the given linked list because the absolute difference of all these indices with 4 is at most 3. Note : All elements are distinct.

A doubly linked list is a type of linked list that is bidirectional, that is, it can be traversed in both directions, forward and backward.

Input Format

The first line of input contains T, the number of test cases.

The first line of each test case contains an integer K, as specified in the problem statement.

The second line contains the elements of the doubly linked list separated by a single space and terminated by -1. Hence, -1 would never be a list element.

Constraints

1 <= T <= 10 1 <= N <= 10000 1 <= K < N

Time Limit: 1 sec

Output Format

For each test case print in a new line the sorted linked list, the elements of the sorted list should be single-space separated, terminated by -1.*/

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *prev;
    struct node *next;
}*NODE;

NODE getNode(int d)
{
    NODE n = (NODE)malloc(sizeof(struct node));
    if(n==NULL)
        exit(0);
    n->data = d;
    n->next = NULL;
    n->prev = NULL;
    return n;
}

NODE sort(NODE head, int k)
{
    if(head==NULL || head->next==NULL)
        return head;
    NODE temp1, temp2, temp3;
    for(NODE i = head->next; i!=NULL; i=i->next)
    {
        NODE j = i;
        while(j->prev!=NULL && j->prev->data>j->data)
        {
            temp1 = j->prev->prev;
            temp2 = j->prev;
            temp3 = j->next;
            j->prev->next = temp3;
            j->prev->prev = j;
            j->prev = temp1;
            j->next = temp2;
            if(temp1 != NULL)
                temp1->next = j;
            if(temp3 != NULL)
                temp3->prev = temp2;
        }
        if(j->prev == NULL)
            head = j;
    }
    return head;
}

NODE insert_end(NODE head, int d)
{
    NODE temp = getNode(d);
    if(head==NULL)
        return temp;
    NODE cur = head;
    while(cur->next!=NULL)
        cur = cur->next;
    cur->next = temp;
    temp->prev = cur;
    return head;
}

void display(NODE head)
{
    if(head==NULL)
        printf("Linked list is empty.\n");
    else
    {
        NODE cur = head;
        while(cur!=NULL)
        {
            printf("%d ", cur->data);
            cur = cur->next;
        }
        printf("%d", -1);
    }
}

int main()
{
    NODE head = NULL;
    int t, k;
    signed int d;
    scanf("%d", &t);
    scanf("%d", &k);
    while(1)
    {
        scanf("%d", &d);
        if(d==-1)
            break;
        head = insert_end(head,d);
    }
    head = sort(head,k);
    display(head);
    return 0;
}
