#include<iostream>
using namespace std;

class Node{
public:
	int key;
	int data;
	Node* next;
	Node(){
		key=0;
		data=0;
		next=NULL;
	}
	Node(int k, int d){
		key=k;
		data=d;
	}
};

class CircularLinkedList
{
public:
	Node* head;
	CircularLinkedList(){
		head=NULL;
	}


//1. CHECK IF NODE EXISTS USING KEY VALUE
Node* nodeExist(int k){
	Node* temp=NULL;
	Node* ptr=head;
	if(ptr==NULL){
		return temp;
	}
	else{
		do{
			if(ptr->key=k){
				temp=ptr;
			}
			ptr=ptr->next;
		}while(ptr!=head);
		return temp;
	}

}

//2. append node at the end
void appendNode(Node* n){    //here n stands for new node.
	if(nodeExist(n->key)!=NULL){
		cout<<"node already exists"<<endl;
	}
	else{
		if(head==NULL){
			head=n;
			n->next=head;
			cout<<"node appended at head position"<<endl;
		}
		else{
			Node* ptr=head;
			while(ptr->next!=head){
				ptr=ptr->next;
			}
			ptr->next=n;
			n->next=head;
			cout<<"node appended"<<endl;

		}
	}

}

//3. prepend node : to the start
void prependNode(Node* n){
	if(nodeExist(n->key)!=NULL){
		cout<<"node already exists"<<endl;
	}
	else{
		if(head==NULL){
			head=n;
			n->next=head;
			cout<<"node appended at head position"<<endl;
		}
		else{
		Node* ptr=head;
		while(ptr->next!=head){
			ptr=ptr->next;
		}
		ptr->next=n;
		n->next=head;
		head=n;
		cout<<"node prepended"<<endl;
		}
	}
}


//4.insert node after a particular node
void insertNodeAfter(int k,Node* n){
	Node* ptr=nodeExist(k);
	if(ptr==NULL){
		cout<<"no node exist with given key value"<<endl;
	}
	else{
		if(nodeExist(n->key)!=NULL){
			cout<<"node already exists with given key value"<<endl;
		}
		else{
			if(ptr->next==head){
				n->next=head;
				ptr->next=n;
				cout<<"node inserted at the end"<<endl;
			}
			else{
				n->next=ptr->next;
				ptr->next=n;
				cout<<"node inserted in between"<<endl;
			}
		}
	}
}

//delete node by unique key
void deleteNode(int k){
	Node* ptr= nodeExist(k);
	if(ptr==NULL){
		cout<<"no node exists with entered key value"<<endl;
	}
	else{
		if(ptr==head){            //when head node is to be deleted
			if(head->next=NULL)   //when theres only single node i.e. head node
			{
				head=NULL;
				cout<<"head node unlinked...list is empty now"<<endl;
			}
			else{                    //when there are more nodes than a single head node
				Node* ptr1=head;
				while(ptr1->next!=head){
					ptr1=ptr1->next;
				}
				ptr1->next=head->next;
				head=head->next;
				cout<<"node unlinked with given key values"<<endl;

		    }
		}
		else{          //when node to be deleted is random node except head node.
			Node* temp=NULL;
			Node* prevptr=head;
			Node* curptr= head->next;
			while(curptr!=head){
				if(curptr->key==k){
					temp=curptr;
					curptr=NULL;
				}
				else{
					prevptr=prevptr->next;
					curptr=curptr->next;
				}
			}
			prevptr->next=temp->next;
			cout<<"node unlinked with given key values "<<endl;

		}
	}
}

//6. update node data
void updateNodeByKey(int k,int d){
	Node* ptr= nodeExist(k);
	if(ptr!=NULL){
		ptr->data=d;
		cout<<"data updated for given key value"<<endl;
	}
	else{
		cout<<"no node exists with given key value"<<endl;
	}

}

//7.printing list
void printList(){
	if(head==NULL){
		cout<<"no nodes in list"<<endl;
	}
	else{
		Node * temp= head;
		do{
			cout<<"("<< temp->key <<" , "<<temp->data<<" , "<<temp->next<<") -->";
			temp=temp->next;
		}while(temp!=head);
	}
}

};

int main(){
	CircularLinkedList s;
		int option;
		int key1,k1,data1;

		do{
			cout<<"select option no. :"<<endl;
			cout<<"1. appendNode()"<<endl;
			cout<<"2. prependNode()"<<endl;
			cout<<"3. insertNodeAfter()"<<endl;
			cout<<"4. deleteNodeByKey()"<<endl;
			cout<<"5. updateNodeByKey()"<<endl;
			cout<<"6. print()"<<endl;
			cout<<"7. clear screen()"<<endl;

			cin>>option;
			Node* n1= new Node();

			switch(option){
			case 0:
				break;
			case 1:
				cout<<"Enter key and data to be appended"<<endl;
			cin>>key1;
			cin>>data1;
			n1->key= key1;
			n1->data= data1;
			s.appendNode(n1);
			break;

			case 2:
				cout<<"Enter key and data to be prepended"<<endl;
					cin>>key1;
					cin>>data1;
					n1->key= key1;
					n1->data= data1;
					s.prependNode(n1);
					break;
			case 3:
				cout<<"Enter the key of existing node after which u want to insert new node "<<endl;
					cin>>k1;
					cout<<"enter key and data of new node"<<endl;
					cin>>key1;
					cin>>data1;
					n1->key= key1;
					n1->data= data1;
					s.insertNodeAfter(k1,n1);
					break;

			case 4:
					cout<<"Enter key to be deleted"<<endl;
					cin>>k1;
					s.deleteNode(k1);
					break;

			case 5:
				cout<<"Enter key and new data to be updated"<<endl;
				cin>>key1;
				cin>>data1;
				s.updateNodeByKey(key1,data1);
				break;

			case 6:
				s.printList();
				break;

			case 7:
				system("cls");
				break;

			default:
				cout<<" enter valid option";
	        }
	    }while(option!=0);



	return 0;
}










