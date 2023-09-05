/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        //There are two approaches to solve this question-
        //1-Using unordered map and without it.
        //Using unordered map
        // unordered_map<Node*,Node*>um;
        // Node* temp=head;
        // while(temp){
        //     Node *copy=new Node(temp->val);
        //     um[temp]=copy;
        //     temp=temp->next;
        // }
        // temp=head;
        // Node *ans=um[temp];
        // while(temp){
        //     ans->next=um[temp->next];
        //     if(temp->random==NULL)ans->random=NULL;
        //     else{
        //         ans->random=um[temp->random];
        //     }
        //     temp=temp->next;
        //     ans=ans->next;
        // }
        // ans->next=NULL;
        // ans=um[temp];
        // return ans;
        //This approach is giving error
        
        //Solving in constant space
        if(head==NULL)return NULL;
        Node* temp=head;
        while(temp){
            Node* copy=new Node(temp->val);
            copy->next=temp->next;
            temp->next=copy;
            temp=temp->next->next;
        }
        temp=head;
        Node *copyhead=temp->next;
        while(temp&&temp->next){
            if(temp->random==NULL)copyhead->random=NULL;
            else{
                copyhead->random=temp->random->next;
            }
            if(temp->next!=NULL)temp=temp->next->next;
            if(copyhead->next!=NULL)copyhead=copyhead->next->next;
        }
        if(temp)temp->next=NULL;
        copyhead->next=NULL;
        temp=head;
        copyhead=temp->next;
        Node* ans=temp->next;
        while(temp){
            temp->next=copyhead->next;
            if(copyhead->next)copyhead->next=copyhead->next->next;
            temp=temp->next;
            copyhead=copyhead->next;
        }
        return ans;
    }
};