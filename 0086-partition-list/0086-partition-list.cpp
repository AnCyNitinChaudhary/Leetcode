/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* head1=NULL,*head2=NULL,*tail1=NULL,*tail2=NULL;
    void addNode(int data,ListNode* &head,ListNode* &tail){
        if(head==NULL&&tail==NULL){
            head=new ListNode(data);
            tail=head;
        }
        else{
            tail->next=new ListNode(data);
            tail=tail->next;
        }
    }
    ListNode* partition(ListNode* head, int x) {
        ListNode* temp=head;
        while(temp){
            if(temp->val<x)addNode(temp->val,head1,tail1);
            else if(temp->val>=x)addNode(temp->val,head2,tail2);
            temp=temp->next;
        }
        if(tail1!=NULL)tail1->next=head2;
        if(head1!=NULL)return head1;
        return head2;
    }
};