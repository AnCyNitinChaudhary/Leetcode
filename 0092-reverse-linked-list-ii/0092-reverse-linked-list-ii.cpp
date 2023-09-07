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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(left==right)return head;
        int templeft=left;
        // else{
    //         ListNode* current,*previous,*next;
    //         current=head;
    //         int count=0;
    //         while(++count<left){
    //             current=current->next;
    //         }
    // previous=current;
    // current=current->next;
    // previous=NULL;
    // while(++left<=right){
    //   next=current->next;
    //   current->next=previous;
    //   previous=current;
    //   current=next;
    // }
    // return head;
    // }    
            
        ListNode* temp=head;
        ListNode* prev=NULL;
        right-=left;
        left--;
            while(left){
            prev=temp;
            temp=temp->next;
            left--;
            }
        ListNode* current = temp;
        ListNode *pre = NULL, *nex = NULL;
        ListNode* last=NULL;
        // cout<<right<<endl;
        while (right) {
            nex = current->next;
            last=nex->next;
            current->next = pre;
            pre = current;
            current = nex;
            right--;
        }
        current->next = pre;
        if(prev)prev->next=current;
        temp->next=last;
        if(templeft==1)return current;
        return head;
        
    }
};