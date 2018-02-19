#include <iostream>
using namespace std;
class linklist{
    struct node{
        int data;
        node *next;
    };
    node *start,*temp,*newnode,*temp1;
    int data1,num;
public:
    linklist(){
        start=NULL;
    }
    void enter();
    void display();
    void loop();
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
    temp1 = start;                                                /*creating a loop(line no->40-43)*/
    for(int b =0;b<2;b++)
        temp1 = temp1->next;
    newnode->next = temp1;
}
void linklist::loop(){
    int flag =0;
    temp = start;
    node *a[num];
    int i;
    a[0] = temp;
    temp = temp->next;
    for(i=1;i<num;i++){
        for(int b=0;b<num;b++){
            if(a[b] == temp->next){
                cout<<temp->data;
                flag =1;
                break;
            }
        }
        if(flag == 1){
            cout<<"\nloop found";
            break;
        }
        else{
            cout<<temp->data<<"\t";
            a[i] = temp->next;
            temp = temp->next;
            flag =0;
        }
    }
    if(flag ==0)
        cout<<"\nloop not found";
}
int main()
{
    linklist l;
    l.enter();
    l.loop();
}
