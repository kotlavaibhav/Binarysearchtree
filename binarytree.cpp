#include "binarytree.h"

using namespace std;

struct node {
	node *llink;
	node *rlink;
	int info;
};

bst::bst() {
	root = NULL;
}

void bst::insert(int item) {

	node * newnode = new node;
	assert(newnode != NULL);
	newnode->info = item;
	newnode->llink = NULL;
	newnode->rlink = NULL;
	if (root == NULL) {
		root = newnode;
	}
	else {
		
		node *current = root;
		node *trailcurrent = NULL;
		while (current != NULL)
		{
			trailcurrent = current;
			if (current->info == item) {
				cout << "item already exists";
				return;
			}
			else if (current->info > item)
				current = current->llink;
			else
				current = current->rlink;
		}
		if (trailcurrent->info > item)
			trailcurrent->llink = newnode;
		else
			trailcurrent->rlink = newnode;
	}
}

void bst::deleteitem(int item) {
	if (root == NULL)
		return;
	else {
		node *current = root;
		node *trailcurrent = NULL;
		bool found = false;
		while (current != NULL && !found)
		{
			if (current->info == item) {
				found = true;
			}
			else {
				trailcurrent = current;
				if (current->info > item) {
					current = current->llink;
				}
				else
					current = current->rlink;
			}
		}
		if (current == NULL) {
			cout << "not found";
			return;
		}
		else if (found) {
			if (current == root)
				deletefromtree(root);
			else if (trailcurrent->info > item)
				deletefromtree(trailcurrent->llink);
			else
				deletefromtree(trailcurrent->rlink);
		}
	}
}
void bst::deletefromtree(node* &p) {
	node *temp;
	if (p == NULL)
		return;
	if (p->llink == NULL && p->rlink == NULL)
	{
		temp = p;
		p = NULL;
		delete temp;
	}
	else if (p->llink == NULL)
	{
		temp = p;
		p = temp->rlink;
		delete temp;

	}
	else if (p->rlink == NULL) {
		temp = p;
		p = temp->llink;
		delete temp;
	}
	else {
		node *trailcurrent = NULL;
		node *current = p;
		current = current->llink;
		while (current != NULL) {
			trailcurrent = current;
			current = current->rlink;
		}
		p->info = current->info;
		if (trailcurrent == NULL) {
			p->llink = current->llink;
		}
		else
		{
			trailcurrent->rlink = current->llink;
		}
		delete current;
	}
}

void bst::levelordertraversal(node * current)
{
	if (root == NULL)
		return;
	else {
		if (current != NULL) {
			queue<node*> q;
			q.push(current);
			while (!q.empty()) {
				node* temp = q.front();
				cout << temp->info;
				q.pop();
				if (temp->llink != NULL)
					q.push(temp->llink);
				if (temp->rlink != NULL)
					q.push(temp->rlink);

			}
		}
	}
}
void bst::lot()
{
	levelordertraversal(root);
}
node* bst::leastcommonancestor(node *current,int A, int B) {
	if (current== NULL)
		return NULL;
	if (current->info == A || current->info == B)
		return current;
	leastcommonancestor(current->llink, A, B);
	leastcommonancestor(current->rlink, A, B);
	if (current->llink != NULL && current->rlink != NULL)
		return current;
	if (current->llink == NULL)
		return current->rlink;
	else
		return current->llink;
}

void bst::lothelp(int A,int B) {
	cout <<leastcommonancestor(root,A,B)->info;
}
void bst::deleteall(node* p) {
	if (p == NULL)
		return;
	deleteall(p->llink);
	deleteall(p->rlink);
	delete p;
}
void bst::deleteallhelper() {
	deleteall(root);
}
void bst::deleteallleaves(node* p){
if (p == NULL) {
	return;
}
else {
	if (p->llink != NULL || p->rlink != NULL) {
		deleteallleaves(p->llink);
		deleteallleaves(p->rlink);
	}
	else {
		deleteitem(p->info);
		return;
	}
}
}
int bst::count1(node* p) {
	static int count = 0;
	if (p == NULL) {
		count++;
 		return count;
	}
	else
	{
		count1(p->llink);
		count1(p->rlink);
	}
	return count;
}
	void bst::counthelp() {
		cout << count1(root);
	}

void bst::deleteallleaves1() {
	deleteallleaves(root);
}
int main() {
	bst a;
	a.insert(8);
	a.insert(4);
	a.insert(3);
	a.insert(5);
	a.counthelp();
	return 0;
}
