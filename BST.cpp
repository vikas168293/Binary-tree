#include<bits/stdc++.h>
using namespace std;

class Node{
public:
	int data;
	Node*left;
	Node*right;
public:
Node(int d){
	data = d;
	left = NULL;
	right = NULL;

 }
};

void postprint(Node *root){
	if(root==NULL)
	return  ;
	
	 postprint(root->left);
	 postprint(root->right);
         cout<<root->data<<" ";
	 
}
void print(Node *root){
	if(root==NULL)
	return  ;
	cout<<root->data<<" ";
	 print(root->left);
	 print(root->right);
	 
}
// O(height) - average case complexity
Node * insertBST(Node *root,int d){
	if(root==NULL){
	Node *n = new Node(d);
	return n;
	}

	if(d<root->data)
	root->left = insertBST(root->left,d);

	
	if(d>root->data)
	root->right = insertBST(root->right,d);

	return root;
}

bool search(Node *root,int key)
{
	if(root==NULL)
	return false;
	if(root->data == key)
	return true;
	if(root->data >key)
	return search(root->left,key);
	return search(root->right,key);
}

Node *del(Node *root,int key){
if(root==NULL)
return NULL;

if(root->data==key){
if(root->left == NULL and root->right==NULL){
delete root;
return NULL;
}

else if(root->left!=NULL and root->right==NULL){
Node *temp = root->left;
delete root;
return temp;
} 
else if(root->left==NULL and root->right!=NULL){
Node *temp = root->right;
delete root;
return temp;
} 
else{
Node *temp = root->right;
while(temp->left!=NULL){
temp = temp->left;
}
root->data = temp->data;
root->right = del(root->right,root->data);
return root;
}

}
else if(root->data>key){
root->left = del(root->left,key);
return root;

}
else{
root->right = del(root->right,key);
}

}

Node *heightBalance(int arr[],int s,int e){
	if(s>e){
	return NULL;
	}
	int mid = (s+e)/2;
	Node *root  = new Node(arr[mid]);
	root->left = heightBalance(arr,s,mid-1);
	root->right = heightBalance(arr,mid+1,e);
	return root;

}

Node *preO(int *pre,int *in,int s,int e){
	static int x = 0;
	if(s>e){
	return NULL;	
	}
	int j;
	Node *root = new Node(pre[x]);
	for( j = 0;j<=e;j++){
	if(in[j]==pre[x]){
	break;
		}
		
	}x++;
	root->left = preO(pre,in,s,j-1);
	root->right = preO(pre,in,j+1,e);
	return root;
}

int countBST(int n){
if(n==0)
return 1;
int ans = 0;
for(int i = 0;i<n;i++){

ans +=countBST(i-1)*countBST(n-i);
}
return ans;
}

int main(){
	Node * root = NULL;
	int n;
	cin>>n;
	for(int i = 0;i<n;i++){
	int a;
	cin>>a;
	root = insertBST(root,a);

	}
	print(root);
	
//int key ;
//cin>>key;
//cout<<search(root,key);
//root = del(root,key);
//int in[7]={1,3,5,7,9,10,11};
//int pre[7] = {7,3,1,5,10,9,11};
//root=heightBalance(arr,0,6);
//Node *root = preO(pre,in,0,6);

//print(root);
//cout<<endl;
//postprint(root);
//int n = 3;
//cout<<countBST(3);
return 0;
}
