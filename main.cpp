#include <iostream>
using namespace std;
class linklist{
    struct node{
        int data;
        node *next;
    };
    node *start,*temp,*newnode,*temp1,*temp2,*temp3,*temp4,*a;
    int data1,num,num1,num2;
public:
    linklist(){
        start=NULL;
    }
    void enter();
    void display();
    int swap_value();
};
void linklist::enter(){
    cout<<"Enter the number of nodes:-";
    cin>>num;
    for(int i=0;i<num;i++){
        cout<<"\nEnter the data:-";
        cin>>data1;
        if(start == NULL){
            start = new node;
            start->data = data1;
            start->next = NULL;
        }
        else{
            temp = start;
            while(temp->next != NULL){
                temp = temp->next;
            }
            newnode = new node;
            newnode->data = data1;
            newnode->next = NULL;
            temp->next = newnode;
        }
    }
}
void linklist::display(){
    temp = start;
    while(temp!=NULL){
        cout<<temp->data<<"\t";
        temp=temp->next;
    }
}
int linklist::swap_value(){
    if(num==1){
        cout<<"\nOnly one data present.Nothing to swap ";
        return 0;
    }
    temp = start;
    cout<<"\nEnter the data to swap:-";
    cin>>num1>>num2;
    if(num1>1){
        while(temp!=NULL){
            if(temp->data == num1){
                temp2 =temp1;
            }
            else if(temp->data == num2){
                temp3 = temp1;
            }
            temp1 = temp;
            temp = temp->next;
        }
        if(temp2->next == temp3){
            temp = temp3->next->next;
            temp1 = temp3->next;
            temp3->next->next = temp3;
            temp3->next=temp;
            temp2->next=temp1;
        }
        else{
            temp = temp2->next->next;
            temp1 = temp3->next->next;
            a = temp3->next;
            temp3->next->next=temp;
            temp2->next->next = temp1;
            temp3->next = temp2->next;
            temp2->next = a;
        }
        display();
    }
    else{
        while(temp!=NULL){
             if(temp->data == num2){
                temp3 =temp1;
            }
            temp1 = temp;
            temp =temp->next;
        }
        temp2 = start;
        if(temp2 == temp3){
            temp = temp3->next->next;
            temp3 = temp2->next;
            temp3->next = temp2;
            temp2->next = temp;
            temp = temp3;
            while(temp!=NULL){
                cout<<temp->data<<"\t";
                temp=temp->next;
            }
        }
        else{
            temp = temp3->next->next;
            temp1 = temp3->next;
            a = temp2->next;
            temp3->next->next = a;
            temp3->next= temp2;
            temp2->next=temp;
            temp = temp1;
            while(temp!=NULL){
                cout<<temp->data<<"\t";
                temp=temp->next;
            }
        }
    }
    return 0;
}
int main()
{
    linklist l;
    l.enter();
    l.display();
    l.swap_value();
}
