#include<iostream>
using namespace std;

class node{
    public:
    int data; node* next;
    node(int d){
        data = d;
        next = NULL;
    }
};
void append(node *& x, int a){
    node* temp = new node(a);
    x->next = temp;
    x = x->next;
}
void insertAtPosition(int position, int value, node*& h){
    node* temp = new node(value);
    node* ptr = h;
    for (int i = 0; i < position; i++){
        ptr = ptr->next;
    }
    temp->next =  ptr->next; 
    ptr->next = temp;   
}
void printFromStart(node*& d){
    node* ktemp = d;
    while( ktemp != NULL){
        cout << ktemp->data << " "; ktemp = ktemp->next;
    }

}
void pop(node*& tale, node*& hade) {
    if (hade == NULL) {
        cout << "List is empty." << endl;
        return;
    }

    if (hade->next == NULL) {
        delete hade;
        hade = NULL;
        tale = NULL;
        return;
    }

    node* prev = NULL;
    node* current = hade;

    while (current->next != NULL) {
        prev = current;
        current = current->next;
    }

    delete current;
    prev->next = NULL;
    tale = prev;
}
void AlternateMerge(node*& l1, node*& l2){
    int a = 0;
    node* temp = l1->next; node* start = l1;
    for (int i = 0; i <= 8; i++){
        if (a == 0){
            l1->next = l2;
            l1 = l1->next; l2 = l2->next;
            a = 1;
            continue;
        }
        if (a == 1){
            l1->next = temp;
            temp = temp->next; l1 = l1->next;
            a =0 ;
            continue;
        }
    }
    printFromStart(start);
}


int main(){
    int k; node* tail; node* tail1; node* head; node* head1;
    for (int i = 0; i < 5; i++){
        if (i == 0){
            cin >> k; head = new node(k); tail = head; continue; 
        }   
        cin >> k; append(tail, k);
    }
    cout << "enter 2nd ll " << endl;
    for (int i = 0; i < 5; i++){
        if (i == 0){
            cin >> k; head1 = new node(k); tail1 = head1; continue; 
        }   
        cin >> k; append(tail1, k);
    }  
    AlternateMerge(head, head1);


}
