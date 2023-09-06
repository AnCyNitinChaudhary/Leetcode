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
    void addNode(ListNode* &head,ListNode* & tail,int data){
        if(head==NULL){
            head=new ListNode(data);
            tail=head;
        }
        else{
            tail->next=new ListNode(data);
            tail=tail->next;
        }
    }
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        vector<ListNode*> ans;
        ListNode* temp=head;
        int len=0;
        while(temp){
            temp=temp->next;
            len++;
        }
        if(len<k){
            temp=head;
            while(temp){
                ListNode* temphead=NULL;
                ListNode* temptail=NULL;
                addNode(temphead,temptail,temp->val);
                ans.push_back(temphead);
                temp=temp->next;
            }
            int extra=k-len;
            while(extra--){
                ListNode* temphead1=NULL;
                ans.push_back(temphead1);
            }
        }
        else{
            int tempsize=len/k;
            int countadd=len%k;
            temp=head;
            while(temp){
                ListNode* temphead=NULL;
                ListNode* temptail=NULL;
                int sizei=tempsize;
                while(sizei--){
                    addNode(temphead,temptail,temp->val);
                    temp=temp->next;
                }
                if(countadd>0){
                    addNode(temphead,temptail,temp->val);
                    temp=temp->next;
                    countadd--;
                }
                ans.push_back(temphead);
            }
        }
        return ans;
    }
};