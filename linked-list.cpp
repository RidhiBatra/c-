//multiple blocks of memory linked with each other
'''properties of linked list
size can be modified
non contiguous memory
insertion and deletion at any point is easier. '''
#include<iostream>
using namespace std;
class node{
    public:
    int data;
    node* next;
    node(int val){
        data = val;
        next = NULL;
    }
};
void insertAtTail(node* &head, int val){
    node* n= new node(val);
    if (head == NULL){
        head = n;
        return;
    }
    node* temp = head;
    while (temp->next != NULL){
        temp = temp-> next;
    }
    temp->next = n;
}
//printing a linkedlist
void display(node* head){
    node* temp = head;
    while(temp!= NULL){
        cout<<temp->next;
    }
    cout << "NULL" <<endl;
}
//inserting at the head
void insertAthead(node* &head, int val){
    node* n = new node(val);
    n->next = head;
    head = n;
}
//linear search in the linked list
bool search(node* head, int key){
    node* temp = head;
    while (temp != NULL ){
        if(temp->data == key){
            return true;
        }temp = temp->next;
    }return false;
}
//deletion of a node
void deleteAthead(node* &head){
    node* todelete = head;
    head = head->next;
    delete todelete;
}
void deletion(node* &head, int vala){
    if (head == NULL)
    return;
    if(head->next == NULL){
        deleteAthead(head);
        return;
    }
    node* temp= head;
    while (temp->next->data != val){
    temp = temp->next;
}
//we have to delete the tenp->next node
node* todelete = temp->next;
temp->next = temp->temp->next;
delete todelete;}

//reverse a linkedlist
//1) iterative
node* reverse(node* &head){
    node* prevptr = NULL;
    node* currptr = head;
    node* nextptr;
    while (currptr != NULL){
        nextptr = currptr->next;
        currptr->next = prevptr;
        prevptr = currptr;
        currptr = nextptr;
        
    }return prevptr;
}
//2) recursive
node* reverseRecursive(node* &head){
    if(head == NULL || head->next == NULL){
        return head;
    }
    node*newhead = reverseRecursive(head->next);
    head->next->next = head;
    head->next= NULL;
    return newhead;
}
//K reverse[IMP]
node* reversek(node* &head, int k){
    node* prevptr = NULL;
    node* currptr = head;
    node* nextptr;
    int count = 0;
    while (currptr != NULL && count <k ){
        nextptr = currptr->next;
        currptr->next = prevptr;
        prevptr = currptr;
        currptr = nextptr;
        count++;
        }
        if (nextptr != NULL){
            head->next = reversek(nextptr, k);
        }return prevptr;
}
//cycle deletion [IMP] (Floyd's cycle deletion)
bool deleteCycle(node* &head){
    node* slow = head;
    node* fast= head;
    while (fast != NULL && fast->next != NULL){
        slow = slow->next;
        fast=fast->next->next;
        if (fast==slow){
            return true;
        }
    }
    return false;
}
//doubly linked list
class node{
    public:
    int data;
    node* next;
    node* prev;
    node(int val){
        data = val;
        next = NULL;
        prev = NULL;
    }
};

//Append last k nodes to start of the linked list
int length(node *head){
    int l=0;
    node* temp=head;
    while(temp!=NULL){
        l++;
        temp=temp->next;
    }return l;
}
node* kappend(node* &head, int k){
    node* newhead;
    node* newtail;
    node* tail=head;

    int l=length(head);
    int count = 1;
    while(tail->next!=NULL){
        if(count==l-k){
            newtail= tail;
        }
        if(count==l-k+1){
            newhead=tail;
        }
        tail=tail->next;
        count++;
    }
    newtail->next=NULL;
    tail->next=head;
    return newhead;
}
int main(){
    node* head=NULL;
    int arr[]={1,2,3,4,5,6};
    for(int i=0;i<6; i++){
        insertAtTail(head,arr[i]);
    }
    display(head);
    node* newhead=kappend(head ,3);
    diplay(newhead);
    return 0;
}

//find  intersertion point of 2 linked lists
void display(node* head){
    node* temp=head;
    while(temp!=NULL){
        cout<<temp->data<<" -> ";
        temp=temp->next;
    }cout<<"NULL"<<endl;
}
int length(node* head){
    int l=0;
    node* temp=head;
    while(temp!=NULL){
        temp=temp->next;
        l++;
    }return l;

}
int intersertion(node* &head1, node* &head2){
    int l1=length(head1);
    int l2=length(head2);
    int d=0;
    node* ptr1;
    node* ptr2;
    if(l1>l2){
        d=l1-l2;
        ptr1=head1;
        ptr2=head2;
    }
    else{
        d=l2-l1;
        ptr1=head2;
        ptr2=head1;
    }
    while(d){
        ptr=ptr1->next;
        if(ptr1==NULL){
            return -1;        }d--;
    }ehile(ptr!=NULL && ptr2!=NULL){
        if(ptr1==ptr2){
            return ptr1->data;
        }
        ptr1=ptr1->next;
        ptr2=ptr2->next;
    }
    return -1;
}

//merge 2 sorted linked list
node* merge(node* &head1, node* &head2){
    node* p1=head1;
    node* p2=head2;
    node* dummyNode=new node(-1);
    while(p1!=NULL && p2!=NULL){
        if(p1->data<p2->data){
            p3->next=p1;
            p1=p1->next;
        }
        else{
            p3->next=p2;
            p2=p2->next;
        }
        p3=p3->next;
    }
    while(p1!=NULL){
        p3->next=p1;
        p1=p1->next;
        p3=p3->next;
    }
    while(p2!=NULL){
        p3->next=p2;
        p2=p2->next;
        p3=p3->next;
    }
    return dummyNode->next;
    }

    //circular linked list
    #include <iostream>
    using namespace std;
    class node{
        public:
        int data;
        node* next;
        node(int val){
            data=val;
            next=NULL;
        }
    }
    void insertAtHead(node* &head, int val){
        node* n=new node(val);
        if(head==NULL){
            n->next=n;
            head=n;
            return;
        }
        node* temp=head;
        while(temp->next!=head){
            temp=temp->next;
        }
        temp->next=n;
        n->next=head;
        head=n;
    }
    void insertAtTail(node* &head, int val){
        if(head==NULL){
            insertAtHead(head,val);
            return;
        }


        node* n = new node(val);
        node* temp=head;
        while(temp->next!=head){
            temp=temp->next;
        }
        temp->next=n;
        n->next=head;
    }
    void display(node* head){
        node* temp=head;
        do{
            cout<<temp->data<<" ";
            temp=temp->next;
        }while (temp!=head);
        cout<<endl;
    }
    int main(){
        node* head=NULL;
        insertAtTail(head,1);
        insertAtTail(head,2);
         insertAtTail(head,3);
          insertAtTail(head,4);
          display(head);
           insertAtHead(head,5);
           display(head);
        
return 0;
    }

    //put even position nodes after odd position nodes
    void evenAfterodd(node* &head){
        node* odd = head;
        node* even = head->next;
        node* evenStart = even;
        while (odd->next != NULL && even->next != NULL){
            odd->next = even->next;
            odd = odd->next;
            even->next = odd->next;
            even = even->next;
        }
        odd->next = evenStart;
        if (odd->next != NULL){
            even ->next = NULL;
        }
    }