/*
	author : arv
*/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define INF INFINITY; // macro
#define pi 3.142;
#define REP(i, a, b) for (int i = a; i <= b; i++)
#define SQ(a) (a) * (a)

struct node{
	int data;
	struct node *next;
};

struct node *head = NULL;

void insertNode(){
	int data;
	cout << "Enter a number:- ";
	scanf("%d", &data);

	node *newNode = new node;
	newNode->data = data;
	newNode->next = NULL;

	if (head == NULL)
	{
		head = newNode;
	} else {
		node *t;
		t = head;
		while (t->next != NULL){
			t = t->next;
		}
		t->next = newNode;
	}
}
void insertAfter(int fData){
	int data;
	cout << "Enter a Number:- ";
	cin >> data;

	node* newNode = new node;
	newNode->data = data;

	node* t;
	t = head;
	while(t != NULL){
		if(t->data == fData){
			break;
		}
		t = t->next;
	}

	if(t->data == fData){
		newNode->next = t->next;
		t->next = newNode;
	} else {
		cout<<"\nData not found!";
	}

}

void showNodes(){
	node *t;
	t = head;
	while (t != NULL){
		cout << t->data << '\n';
		t = t->next;
	}
}

int main()
{
	int option;
	
	while (1){
		cout << "1.Show \n2.Insert \n3.Insert after a number\nOption:- ";
		cin >> option;
		switch (option){
		case 1:
			showNodes();
			break;
		case 2:
			insertNode();
			break;
		case 3:
			{
				int d;
				cout<<"Enter number:- ";
				cin>>d;
				insertAfter(d);
			}
			break;
		default:
			cout << "Etner valid data";
			break;
		}
	}

	return 0;
}