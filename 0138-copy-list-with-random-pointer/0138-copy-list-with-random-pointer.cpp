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
// private:
//     void insertAtTail(Node* &head, Node* &tail, int d){
//         Node* newNode = new Node(d);
//         if(head == NULL){
//             head = newNode;
//             tail = newNode;
//             return;
//         }
//         else{
//             tail = tail -> next;
//             tail = newNode;
//         }
//     }


public:
    Node* copyRandomList(Node* head) {
        // Node* cloneHead = NULL;
        // Node* cloneTail = NULL;

        // Node* temp = head;

        // while( temp != NULL){
        //     insertAtTail(cloneHead, cloneTail, temp -> val);
        //     temp = temp -> next;
        // }

        // unordered_map<Node* , Node*> oldToNewNode;

        // Node* originalNode = head;
        // Node* cloneNode = cloneHead;

        // while(originalNode != NULL && cloneNode != NULL){
        //     oldToNewNode[originalNode] = cloneNode;
        //     originalNode = originalNode -> next;
        //     cloneNode = cloneNode -> next;
        // }

        // originalNode = head;
        // cloneNode = cloneHead;

        // while(originalNode != NULL){
        //     cloneNode -> random = oldToNewNode[originalNode -> random];
        //     originalNode = originalNode -> next;
        //     cloneNode = cloneNode -> next;
        // }
        // return cloneHead;

        if (!head) return nullptr;
        
        unordered_map<Node*, Node*> old_to_new;
        
        Node* curr = head;
        while (curr) {
            old_to_new[curr] = new Node(curr->val);
            curr = curr->next;
        }
        
        curr = head;
        while (curr) {
            old_to_new[curr]->next = old_to_new[curr->next];
            old_to_new[curr]->random = old_to_new[curr->random];
            curr = curr->next;
        }
        
        return old_to_new[head];
    }
};