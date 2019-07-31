/* Diameter of a tree
*/

#include<bits/stdc++.h>
using namespace std;

struct node
{
    int data;
    struct node* left;
    struct node* right;
};

struct node * newnode(int x)
{
    struct node *new_node=new node;
    new_node->data=x;
    new_node->left=NULL;
    new_node->right=NULL;
    return new_node;  
}
struct node* insert(struct node* a,int x)
{
    if (a==NULL)
        return newnode(x);
           
    if (x>a->data)
        a->right=insert(a->right,x);
    else
        a->left= insert(a->left,x);
    return a;
    
}

void inorder(struct node* x)
{
    if (x==NULL)
        return;
    inorder(x->left);
    cout<<x->data<<" ";
    inorder(x->right);
}

int count(struct node* x)
{
    if (x==NULL)
        return 0;
    return 1 + count(x->left)+ count(x->right);
}

int height(struct node* x)
{
    if (x==NULL)
        return 0;
    return 1+ max(height(x->left),height(x->right));
}

int distance_from_root(struct node* a, int x)
{
    //cout<<"a is "<<a->data;
    if(a->data==x)
        return 0;
    else if (x>a->data)
        return 1+ distance_from_root(a->right,x);
    else
        return 1+ distance_from_root(a->left,x);

}

struct node * get_node(struct node* a,int x)
{
    if (a==NULL || a->data==x)
        return a;

    if(x>a->data)
        return get_node(a->right,x);
    else
        return get_node(a->left,x);
}

bool isancestor(struct node*  a,int x,int y)
{   
    if (x==y || x==a->data)
        return true;
    if(y==a->data)
        return false;
    
    if(y>a->data)
        return isancestor(a->right,x,y);
    else
        return isancestor(a->left,x,y);
}

int distance_nodes(struct node* a,int x,int y)
{   
    if (a->left!=NULL && isancestor(a,(a->left)->data,x)&&isancestor(a,(a->left)->data,y))
        return distance_nodes(a->left,x,y);
    else if (a->right!=NULL && isancestor(a,(a->right)->data,x)&&isancestor(a,(a->right)->data,y))
        return distance_nodes(a->right,x,y);
    else
        return distance_from_root(a,x)+distance_from_root(a,y);
}

int max_distance_nodes(struct node* a)
{   
    if (!a)
        return 0;
    return max(height(a->left)+height(a->right),max(max_distance_nodes(a->left),max_distance_nodes(a->right)));

}

int main()
{
    int n,temp;
    cin>>n;
    struct node* a=NULL;
    while(n--)
    {
        cin>>temp;
        a=insert(a,temp);

    }
    cout<<max_distance_nodes(a);
    return 0;
}