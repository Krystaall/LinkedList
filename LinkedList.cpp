//sll
#include<iostream>
using namespace std;

class Node{
public:
	int key;
	int data;
	Node* next;

	Node(){  //this is a constructor
		key=0;
		data=0;
		next=NULL;
	}
	Node(int k, int d){  //this is also constructor.
		key=k;              //both constructors have same name i.e. Node therefore constructor overloading.
		data=d;
	}
	friend class Sll;
};
//keyword - 'friend class' used for Sll instead of declaring public-key , data and next pointer.
class Sll{
public:
	Node* head;
	Sll(){
		head=NULL;
	}
	Sll(Node* n){
		head=n;
	}
	//the above 2 constructors are also- constructor overloading.

Node* nodeExist(int k){   //this is a method with return type as pointer.
	Node* temp=NULL;
	Node* ptr= head;
	while(ptr!=NULL){
		if(ptr->key==k){
			temp=ptr;
		}
		ptr=ptr->next;
	}
	return temp;
}

void appendNode(Node* n){
	if(nodeExist(n->key)!=NULL){
		cout<<"node already exists"<<endl;
	}
	else{
		if(head==NULL){
			head=n;
			cout<<"node appended"<<endl;
		}
		else{
			Node* ptr=head;
			while(ptr->next!=0){
				ptr=ptr->next;
			}
			ptr->next=n;
			cout<<"node appended"<<endl;
		}
	}
}

void prependNode(Node* n){

			if(nodeExist(n->key)!=NULL){
				cout<<"Node already exists"<<endl;
			}
			else{
				n->next=head;
				head=n;
				cout<<"node prepended";
			}

}
void insertNode(int k,Node* n){


		Node* ptr=nodeExist(k);
		if(ptr==NULL){
			cout<<"no node exists with key value. therefore cannot be appended"<<endl;
		}
		else{
			if(nodeExist(n->key)!=NULL){
				cout<<"Node already exists"<<endl;
			}
			else{
				n->next=ptr->next;
				ptr->next=n;
				cout<<"node inserted"<<endl;
			}
		}


	}
void deleteNode(int k){
	if(head==NULL){
		cout<<"List is empty"<<endl;

	}
	else if(head!=NULL){
		if(head->key==k){  //it means we want to delete the first node.
			head=head->next;
			cout<<"first node deleted";
		}

	else{ //deleting any other random node.
		Node* temp=NULL;
		Node *prevptr=head;
		Node *curptr=head->next;
		while(curptr!=NULL){
			if(curptr->key==k){
				temp=curptr;
				curptr=NULL;
			}
			else{
				prevptr=prevptr->next;
				curptr=curptr->next;

			}
		}
		if(temp!=NULL){
			prevptr->next=temp->next;
			cout<<"node deleted"<<endl;
		}
		else{
			cout<<"node doesn't exist with given key value"<<endl;
		}

	}
	}
}
void updateNode(int k, int d){
	Node* ptr=nodeExist(k);
	if(ptr!=NULL){
		ptr->data=d;
		cout<<"data updated"<<endl;
	}
	else{
		cout<<"node doesn't exist"<<endl;
	}
}

void printList(){
	if(head==NULL){
		cout<<"list is empty"<<endl;
	}
	else{
		Node* temp=head;
		while(temp!=NULL){
			cout<<"("<<temp->key<<" , "<<temp->data<<" ) ";
			temp=temp->next;

		}
	}
}








};

int main(){
	Sll s;
	int ch;
	int key1, data1,k1;

	while(ch!=0){
	cout<<""<<endl;
	cout<<"0. END"<<endl;
	cout<<"1. search node."<<endl;
	cout<<"2. append node"<<endl;
	cout<<"3. prepend node"<<endl;
	cout<<"4. Insert a node"<<endl;
	cout<<"5. delete a node"<<endl;
	cout<<"6. update node"<<endl;
	cout<<"7. print list"<<endl;


    cout<<"Enter your choice: "<<endl;
    cin>>ch;
    Node* n1=new Node();
    switch(ch){
    case 0:
    	break;

    case 1:
    cout<<"enter the value of key";
    cin>>k1;
    if(s.nodeExist(k1)!=NULL){
    cout<<"node already present"<<endl;
    }
    else{
    cout<<"node not found"<<endl;
    }
    break;

    case 2:
	cout<<"Enter the value of key and data to be appended"<<endl;
	cin>>key1;
	cin>>data1;
	n1->key=key1;
	n1->data=data1;
	s.appendNode(n1);
	break;

    case 3:
    cout<<"enter new key and data to be prepended"<<endl;
    cin>>key1;
    cin>>data1;
    n1->key=key1;
    n1->data=data1;
    s.prependNode(n1);
    break;

    case 4:
    cout<<"Enter the key of existing node after which u want to append new node"<<endl;
    cin>>k1;
    cout<<"enter key and data of new node"<<endl;
    cin>>key1;
    cin>>data1;
    s.insertNode(k1,n1);
    break;

    case 5:
    cout<<"enter the value of key to be deleted"<<endl;
    cin>>key1;
    n1->key=key1;
    s.deleteNode(k1);
    break;

    case 6:
    cout<<"enter the key and new data to be updated"<<endl;
    cin>>key1;
    cin>>data1;
    s.updateNode(key1,data1);
    break;

    case 7:
    	s.printList();
    	break;





    }
	}
	return 0;



}









