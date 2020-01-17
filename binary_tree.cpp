/*Binary tree Construction from inorder and preorder traversals. */
#include <bits/stdc++.h>
using namespace std;

struct node
{
    int data;
    struct node *left;
    struct node *right;
};

struct node *newnode(int x)
{
    struct node *new_node = new node;
    new_node->data = x;
    new_node->left = NULL;
    new_node->right = NULL;
    return new_node;
}

void print_vector(vector<int> a)
{
    for (auto i = a.begin(); i != a.end(); ++i)
    {
        cout << *i << " ";
    }
}

void read_vector(vector<int> &a, int n)
{
    int temp;
    for (int i = 0; i < n; ++i)
    {
        cin >> temp;
        a.push_back(temp);
    }
}

struct node *create_tree(vector<int> in, int start, int end, vector<int> &pre)
{
    if (start == end)
    {
        return NULL;
    }
    int ele = *(pre.begin());
    remove(pre.begin(), pre.end(), ele);
    struct node *n = newnode(ele);
    auto index = find(in.begin() + start, in.begin() + end, ele) - in.begin();
    n->left = create_tree(in, start, index, pre);
    n->right = create_tree(in, index + 1, end, pre);

    return n;
}

void inorder(struct node *tree)
{
    if (tree == NULL)
    {
        return;
    }
    inorder(tree->left);
    cout << tree->data << " ";
    inorder(tree->right);
}

void preorder(struct node *tree)
{
    if (tree == NULL)
    {
        return;
    }

    cout << tree->data << " ";
    preorder(tree->left);
    preorder(tree->right);
}

void postorder(struct node *tree)
{
    if (tree == NULL)
    {
        return;
    }

    postorder(tree->left);
    postorder(tree->right);
    cout << tree->data << " ";
}

void levelorder(struct node* tree)
{
    queue <struct node*> q;
    q.push(tree);
    while(!q.empty())
    {
        struct node* ele=q.front();
        q.pop();
        cout<<ele->data<<" ";
        if (ele->left)
            q.push(ele->left);
        if (ele->right)
            q.push(ele->right);

    }
}
int main()
{
    int t, n, temp;

    cin >> t;
    while (t--)
    {
        cin >> n;

        vector<int> in, pre;
        read_vector(in, n);
        read_vector(pre, n);
        struct node *tree = create_tree(in, 0, n, pre);

        inorder(tree);
        cout << "\n";

        preorder(tree);
        cout << "\n";

        postorder(tree);
        cout << "\n";

        levelorder(tree);

    }

    return 0;
}