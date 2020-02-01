#include <iostream>
#include <vector>
#include <string>
using namespace std;
class Node
{
public:
    int data = 0;
    Node *left = NULL;
    Node *right = NULL;
    int freq = 1;

    Node(int data)
    {
        this->data = data;
    }
    Node(int data, Node *left, Node *right)
    {
        this->data = data;
        this->right = right;
        this->left = left;
    }
};
void display(Node *node)
{
    if (node == nullptr) // nullptr and NULL are equal
        return;

    string str = "";
    str += node->left != nullptr ? to_string(node->left->data) : " . ";
    str += " => " + to_string(node->data) + " <= ";
    str += node->right != nullptr ? to_string(node->right->data) : " . ";
    cout << str << "----" << node->freq << endl;

    display(node->left);
    display(node->right);
}
Node *create(vector<int> &arr, int si, int ei)
{
    if (si > ei)
    {
        return nullptr;
    }
    if (si == ei)
    {
        Node *node = new Node(arr[si]);
        return node;
    }

    int mid = ((si + ei) >> 1); // ((si + ei)/2)   both are same

    Node *node = new Node(arr[mid]);

    node->left = create(arr, si, mid - 1);
    node->right = create(arr, mid + 1, ei);

    return node;
}

int maximum(Node *node)
{
    Node *curr = node;
    while (curr->right != nullptr)
    {
        curr = curr->right;
    }
    return curr->data;
}

void addNode_01(Node *node, Node *par, int data, bool isLeft)
{
    if (node == NULL)
    {
        Node *child = new Node(data);
        if (isLeft)
        {
            par->left = child;
        }
        else
        {
            par->right = child;
        }
        return;
    }
    if (node->data == data)
    {
        node->freq++;
        return;
    }
    else if (node->data < data)
    {
        addNode_01(node->right, node, data, false);
    }
    else
    {
        addNode_01(node->left, node, data, true);
    }
}

Node *addNode(Node *node, int data)
{
    if (node == nullptr)
    {
        return new Node(data);
    }
    if (node->data == data)
    {
        node->freq++;
        cout << node->freq;
        return node;
    }
    else if (node->data < data)
    {
        node->right = addNode(node->right, data);
    }
    else
    {
        node->left = addNode(node->left, data);
    }
    return node;
}

void addNode_02(Node *&node, int data) //now it is sending the address directly , and this method will not work in java
{
    if (node == nullptr)
    {
        node = new Node(data);
        return;
    }
    if (node->data == data)
    {
        node->freq++;
        return;
    }
    else if (node->data < data)
    {
        addNode_02(node->right, data);
    }
    else
    {
        addNode_02(node->left, data);
    }
    return;
}

//this one is same as that of last one
//last is using & and this one is show us the working of &
// in bakckgroung & is working same as this program

void addNode_03(Node **node, int data)
{
    if ((*node) == nullptr)
    {
        (*node) = new Node(data);
        return;
    }
    if ((*node)->data == data)
    {
        (*node)->freq++;
        return;
    }
    else if ((*node)->data < data)
    {
        addNode_03(&(*node)->right, data);
    }
    else
    {
        addNode_03(&(*node)->left, data);
    }
    return;
}
Node *deleteNode(Node *node, int data)
{
    if (node == nullptr)
        return nullptr;

    if (node->data > data)
    {
        node->left = deleteNode(node->left, data);
    }
    else if (node->data < data)
    {
        node->right = deleteNode(node->right, data);
    }
    else
    {
        if (node->freq > 1)
        {
            node->freq--;
        }
        else
        {
            if (node->left == NULL || node->right == NULL)
            {
                Node *n = node->left != NULL ? node->left : node->right;
                delete node;
                return n;
            }
            int max_ = maximum(node->left);
            node->data = max_;
            node->left = deleteNode(node->left, max_);
        }
    }
    return node;
}
void solve()
{
    // vector<int> arr = {10, 20, 30, 40, 50, 60, 70, 80, 90, 100, 110, 120};
    vector<int> arr = {9, 10, 13, 25, 26, 27, 29, 30, 45, 50, 60, 63, 72, 75, 85};
    Node *root = create(arr, 0, arr.size() - 1);
    // display(root);
    cout << "\n";
    addNode_01(root, root, 65, true);
    display(root);
    cout<<"\n";
    root = addNode(root, 65);
    display(root);
    cout<<"\n";
    addNode_02(root, 65);
    display(root);
    cout<<"\n";
    addNode_03(&root, 65);
    display(root);
    cout<<"\n";
    deleteNode(root, 65);
    display(root);
}
int main(int args, char **argv)
{
    solve();
    return 0;
}