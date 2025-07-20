#include <iostream>
using namespace std;
class Node
{
public:
    int value;
    Node *next;
    Node(int value)
    {
        this->value = value;
        this->next = nullptr;
    }
};
class LinkedList
{
public:
    Node *head;
    LinkedList()
    {
        head = nullptr;
    }
    void insertathead(int val)
    {
        Node *newnode = new Node(val);
        if (head == NULL)
        {
            head = newnode;
            return;
        }
        newnode->next = head;
        head = newnode;
        return;
    }
    void insertatend(int val)
    {
        Node *newnode = new Node(val);
        if (head == NULL)
        {
            head = newnode;
            return;
        }
        Node *temp = head;
        while (temp->next)
        {
            temp = temp->next;
        }
        temp->next = newnode;
    }
    void deleteathead()
    {
        Node *temp = head;
        head = temp->next;
        delete temp;
        temp = NULL;
    }
    void deleteatend()
    {
        Node *temp = head;
        if (!head->next)
        {
            delete head;
            return;
        }
        while (temp->next->next)
        {
            temp = temp->next;
        }
        delete temp->next;
        temp->next = NULL;
    }
    void deletebyval(int tar)
    {
        Node *temp = head;
        while (temp->next && temp->next->value != tar)
        {
            temp = temp->next;
        }
        if (!temp->next)
        {
            cout << "value not found";
            return;
        }
        Node *todelete = temp->next;
        temp->next = temp->next->next;
        delete todelete;
        todelete = NULL;
    }
    void getmiddle(){
        Node *mid=middle(head);
        cout<<"middle element is "<<mid->value;
    }
    void print()
    {
        if (!head)
        {
            cout << "empty linked list";
            return;
        }
        Node *temp = head;
        while (temp)
        {
            cout << temp->value << "->";
            temp = temp->next;
        }
    }
    void reverselist(){
       head= reverse(head);
        
    }
    bool isPalidrome(){
        Node* newhead=reverse(head);
        Node* temp1=head;
        Node* temp2=newhead;
        while(temp1){
            if(temp1->value != temp2->value) return false;
            temp1=temp1->next;
            temp2=temp2->next;
        }
        return true;
    }
    void odd_even_segregation(){
        // list  2,1,3,5,6,4,7
        // output 2,3,6,7,1,5,4
        // i am taking 0 index as starting 
        Node* evenhead=head;
        Node* oddhead=head->next;
        Node* eventemp=evenhead;
        Node* oddtemp=oddhead;
        while(oddtemp && oddtemp->next){
            eventemp->next=oddtemp->next;
            eventemp=eventemp->next;
            oddtemp->next=eventemp->next;
            oddtemp=oddtemp->next;

        }
        eventemp->next=oddhead;
        Node * temp=evenhead;

          while (temp)
        {
            cout << temp->value << "->";
            temp = temp->next;
        }

    }
    void removeNthNodeFromlast(int n){
        Node* slow=head;
        Node* fast=head;
        for(int i=0;i<n;i++){
            fast=fast->next;
        }
        while(fast && fast->next){
            slow=slow->next;
            fast=fast->next;
        }
        Node* todelete=slow->next;
        slow->next=slow->next->next;
        delete todelete;
        print();

    }
    void getsorted(){
        Node * sortedhead =sorted(head);
        print();

    }
    private:
    Node* reverse(Node * head){
        if(head ==NULL || head->next ==NULL) return head;
            Node * newhead=reverse(head->next);
            Node * front= head->next;
            front->next=head;
            head->next=NULL;
            return newhead;
        
    }
    Node* middle(Node * head){
        Node* slow=head;
        Node* fast=head;
        while(fast && fast->next ){
            slow=slow->next;
            fast=fast->next->next;
        }
        return slow;

    }
    Node* merge(Node* left,Node* right){
     if(left==NULL) return right;
     if(right==NULL) return left;
     if(left->value<=right->value){
     left->next=merge(left->next,right);
     return left;
     } 
  else{
    right->next=merge(left,right->next);
    return right;
  }
}
    Node* sorted(Node* head){
        if(!head || !head->next) return head;
        Node * mid=middle(head);
        Node* right=mid->next;
        mid->next=NULL;
        Node* left=head;
        left=sorted(left);
        right=sorted(right);
        return merge(left,right);



    }
};
int main()
{
    // LinkedList l1;
    // l1.insertathead(1);
    // l1.insertathead(2);
    // l1.insertathead(9);
    // l1.deleteathead();
    // l1.deleteatend();
    // l1.insertathead(1);
    // l1.insertathead(2);
    // l1.insertathead(9);
    // // l1.deletebyval(1);
    // // l1.deletebyval(7);
    // l1.insertathead(8);
    
    // l1.print();
    // // l1.middle();
    // //l1.reverselist();
    // cout<<endl;
    // l1.print();
    // l1.isPalidrome() ?cout<<"true":cout<<"false";

    // LinkedList l2;
    // l2.insertatend(1);
    // l2.insertatend(2);
    // l2.insertatend(2);
    // l2.insertatend(1);
    // l2.print();
    // l2.isPalidrome() ?cout<<"true":cout<<"false";

    LinkedList l3;
    // l3.insertatend(1);
    // l3.insertatend(2);
    // l3.insertatend(3);
    // l3.insertatend(4);
    // l3.insertatend(5);
    // // l3.odd_even_segregation();
    // // l3.removeNthNodeFromlast(2);
    // l3.getmiddle();
    
}
 