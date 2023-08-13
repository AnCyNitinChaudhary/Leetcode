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
// #include<bits/stdc++.h>
class Solution {
public:
    ListNode *temp2=NULL;
    ListNode *tail=NULL;
    void add(int data){
        if(temp2==NULL){
            temp2=new ListNode(data);
            tail=temp2;
        }
        else{
            tail->next=new ListNode(data);
            tail=tail->next;
        }
    }
    
    
    
    ListNode* addTwoLists(ListNode* first, ListNode* second)
{
    ListNode* res = NULL;
    ListNode *temp, *prev = NULL;
    int carry = 0, sum;
    while (first != NULL || second != NULL) {
        sum = carry + (first ? first->val : 0) + (second ? second->val : 0);
        carry = (sum >= 10) ? 1 : 0;
        sum = sum % 10;
        temp = new ListNode(sum);
        if (res == NULL)
            res = temp;
        else
            prev->next = temp;
        prev = temp;
        if (first)
            first = first->next;
        if (second)
            second = second->next;
    }
    if (carry > 0)
        temp->next = new ListNode(carry);
    return res;
}
 
ListNode* reverse(ListNode* head)
{
    if (head == NULL || head->next == NULL)
        return head;
    ListNode* rest = reverse(head->next);
    head->next->next = head;
    head->next = NULL;
    return rest;
}
    ListNode* doubleIt(ListNode* head) {
//         ListNode* temp=head;
//         string num="";
//         while(temp){
//             num+=to_string(temp->val);
//             temp=temp->next;
//         }
//         // cout<<num<<endl;
//         int tempnum=0;
//         if(num!="")tempnum=stoi(num);
//         tempnum*=2;
//                 // cout<<tempnum<<endl;
//         num=to_string(tempnum);
//         // cout<<num<<endl;
//         // temp=head;
//         int index=0;
//         // ListNode* temp2=NULL;
//         // while(temp&&index<num.size()){
//         //     if(temp->next==NULL)temp2=temp;
//         //     temp->val=(int)num[index];
//         //     temp=temp->next;
//         //     index++;
//         // }
//         while(index<num.size()){
//             // cout<<(int)num[index]<<endl;
//             // cout<<(int)num[index]<<endl;
//             // int toadd=
//             add((int)(num[index]-'0'));
//             index++;
//         }
//         return temp2;
        
        // ListNode* temp=head;
        // int carry=0;
        // while(temp){
        //     int doubledValue=(temp->val*2)+carry;
        //     temp->val=doubledValue%10;
        //     carry = doubledValue / 10;
        //     if (!temp->next && carry > 0) {
        //         temp->next = new ListNode(carry);
        //     }
        //     temp = temp->next;
        // }
        // return head;
        ListNode *temp=head;
        while(temp){
            add(temp->val);
            temp=temp->next;
        }
        ListNode* second = temp2;
        temp2=NULL;
        tail=NULL;
        head = reverse(head);
        second = reverse(second);
        temp2=addTwoLists(head,second);
        temp2=reverse(temp2);
        return temp2;
    }
};