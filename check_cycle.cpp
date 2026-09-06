#include<bits/stdc++.h>
using namespace std;

struct ListNode{
    int val;
    ListNode*next;
    ListNode(int x){
        val=x;
        next=NULL;
    }
};

void printList(ListNode*head){
    ListNode*temp=head;
    while(temp!=NULL){
        cout<<temp->val;
        if(temp->next!=NULL)
            cout<<" -> ";
        temp=temp->next;
    }
    cout<<endl;
}
void printCircularList(ListNode*head){
    ListNode*temp=head;
    do{
        cout<<temp->val;
        cout<<" -> ";
        temp=temp->next;
    }while(temp->next!=head);
    cout<<"HEAD"<<endl;
}

bool hasCycle(ListNode*head){
    ListNode*slow=head;
    ListNode*fast=head;
    while(fast!=NULL&&fast->next!=NULL){
        slow=slow->next;
        fast=fast->next->next;
        if(slow==fast)
            return true;
    }
    return false;
}

int main(){
    int n;
    cout<<"Enter number of nodes: ";
    cin>>n;

    if(n<=0){
        cout<<"Has cycle: false";
        return 0;
    }

    vector<int>values(n);
    cout<<"Enter "<<n<<" node values: ";
    for(int i=0;i<n;i++)
        cin>>values[i];

    vector<ListNode*>nodes(n);
    for(int i=0;i<n;i++)
        nodes[i]=new ListNode(values[i]);

    for(int i=0;i<n-1;i++)
        nodes[i]->next=nodes[i+1];

    ListNode*head=nodes[0];

    int pos;
    cout<<"Enter position to connect tail for a cycle (-1 for no cycle, 0 to "<<n-1<<"): ";
    cin>>pos;

    if(pos>=0&&pos<n)
        nodes[n-1]->next=nodes[pos];

    if(hasCycle(head)){
        cout<<"Has cycle: true"<<endl;
        cout<<"Linked List :"<<endl;
        printCircularList(head);
        
    }else{
        cout<<"Has cycle: false"<<endl;
        cout<<"Linked List: ";
        printList(head);
    }

    return 0;
}
