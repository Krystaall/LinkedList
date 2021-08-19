#include<iostream>
using namespace std;

class Node{
	int key;
	int data;
	Node* next;
	Node* prev;

	Node(){
		key=0;
		data=0;
		next=NULL;
		prev=NULL;
	}
	Node(int k, int d){
		key=k;
		data=d;
	}
};

class DoublyLinkedList{
public:
	Node* head;
	 DoublyLinkedList(){
		 head=NULL;
	 }

	 DoublyLinkedList(Node* n){
			 head=n;
		 }

	 //1.check if node exists using key value.
	 Node* nodeExists(int k){
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

	 //2.append a new node at the end of list
	 void appendNode(Node* n){
		 if(nodeExists(n->key)!=NULL){
			 cout<<"Node already exists. append a node with different key value!";
		 }
		 else{
			 if(head==NULL){
				 head=n;
				 cout<<"Node appended as head node!";
			 }
			 else{
				 Node* ptr=head;
				 while(ptr -> next != NULL){
					 ptr= ptr->next;
				 }
				 ptr->next=n;
				 n->prev= ptr;
				 cout<<"Node appended";
			 }
		 }
	 }

	 //3.prepend node
	 void prependNode(Node* n){
		 if(nodeExists(n->key)!=NULL){
		 	cout<<"Node already exists. Prepend a node with different key value!";
		 }
		 else{
			 if(head==NULL){
				 head=n;
				 cout<<"Node prepended as head node!";
			 }
			 else{
			   head->prev=n;
			   n->next=head;
			   head=n;
			   cout<<"Node prepended";
		     }
	     }

	 }

	 //4.Insert a node after a specific node.
	 void insertNodeAfter(int k, Node* n){
		 Node* ptr = nodeExists(k);
		 if(ptr==NULL)
		 {
			 cout<<"No node exists with this key";
		 }
		 else{
			 if(nodeExists(n->key)!=NULL){
				 cout<<"node already exists.insert node with different key value";
			 }
			 else{
				 cout<<"INSERTING";
				 Node *nextNode=ptr->next;

				 //appending at the end.
				 if(nextNode== NULL){
					 ptr->next=n;
					 n->prev=ptr;
					 cout<<"Node inserted at the end";
				 }
				 //appending in between.
				 else{
					 n->next=nextNode;
					 nextNode->prev=n;
					 n->prev=ptr;
					 ptr->next=n;

					 cout<<"Node inserted in between";
				 }
			 }
		 }
	 }

	 //5.delete node by unique key. basically de-link not delete.
	 void deleteNodeByKey(int k){
		 Node* ptr = nodeExists(k);
		 if(ptr==NULL){
			 cout<<"no node exists with given key value";
		 }
		 else{
				 if(head->key==k){    //if head is to be deleted
					 head= head->next;
					 cout<<"Node unlinked";
				 }
				 else{
					 Node *nextNode = ptr->next;
					 Node *prevNode= ptr->prev;

					 //deleting at end
					 if(nextNode==NULL){
						 prevNode->next=NULL;
						 cout<<"node deleted at the end";
					 }
					 //deleting in between
					 else{
						 prevNode->next=nextNode;
						 nextNode->prev=prevNode;
						 cout<<"node deleted in between";

					 }

				 }
			 }
		 }

	 //6. update node
	 void updateNodeByKey(int k, int d){
		 Node *ptr=nodeExists(k);
		 if(ptr!=NULL){
			 ptr->data=d;
			 cout<<"node data updated";
		 }
		 else{
			 cout<<"node doesn't exist with given key value.";
		 }
	 }

	 //7.print
	 void printList(){
		 if(head==NULL){
			 cout<<"no nodes exist in doubly linked list";
		  }
		 else{
			 cout<<endl<<"doubly linked list values:  ";
			 Node* temp= head;

			 while(temp!=NULL){
				 cout<<"("<<temp->key<<","<<temp->data<<") <-->";
				 temp= temp->next;
			 }
		 }
	 }
};



int main(){
	DoublyLinkedList s;
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
					s.deleteNodeByKey(k1);
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




