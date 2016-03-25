#include <iostream>
using namespace std;
struct Node
{
    int data;
    Node *next;
};
//global variable root is used to record the head of link list
Node* root = NULL;


Node* findTheEnd(){
     Node *temp=root; 
     while(temp->next!=NULL){
        temp=temp->next;
     }
     return temp;
}


Node* findTheEndPre(){
     Node *temp=root;
     Node *temp2=root;
     while(temp->next!=NULL){
        temp2=temp;
        temp=temp->next;
     }
     return temp2;
}


void InsertNode(int x){
    Node *m;
    Node *op;
    op=new Node ;
    op->data=x;
    m=findTheEnd(); 
    m->next=op;
}

void Display(){
     Node *temp=root; 
     while(temp->next!=NULL){
        temp=temp->next;
        cout<<temp->data;
        if(temp!=findTheEnd()){
             cout<<"->";
        }
     }
     cout<<"\n";
}

int DeleteNode(int x){
    int scc=0;
    Node *temp=root;
    Node *pre=root;
    Node *nex=root;
    while(temp->data!=x){
        pre=temp;
        temp=temp->next;
        if(temp->data==x){
             scc=1;
        }
        if(temp->next==NULL){
             break;
        }
    }
    if(scc==1){
        if(temp==root){
             root=root->next;
        }else if(temp==findTheEnd()){
             findTheEndPre()->next=NULL;     
        }else{
            nex=temp->next;
            pre->next=nex;
        }
        return 1;
    }
    return 0;
}


int main()
{
    size_t i = 0;
    root=new Node;
    //root->next=NULL;
    //root->data=1;
    /*
    InsertNode(5);
    InsertNode(7);
    InsertNode(9);
    Display();
    DeleteNode(5);
    Display();
    DeleteNode(3);
    Display();
    DeleteNode(9);
    Display();
*/    
    while (1)
    {
        cout << "Please select an option:" << endl
            << "1.Insert a node" << endl
            << "2.Delete a node" << endl
            << "3.Display the list" << endl
            << "4.End" << endl;
        cin >> i;
        int data;

        switch(i)
        {

            case 1:
                cout << "Please enter the number:" << endl;
                cin >> data;
                InsertNode(data);
                break;
            case 2:
                cout << "Please enter the number:" << endl;
                cin >> data;
                if ( !DeleteNode(data) )
                    cout << "Failed to delete node " << data << endl;
                break;
            case 3:
                Display();
                break;
            case 4:
                return 0;
            default:
                break;
        }

    }

}
