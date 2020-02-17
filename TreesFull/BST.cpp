#include <iostream>
#include <vector>
using namespace std;
class Node
{
public:
    int data = 0;
    Node *left = nullptr;
    Node *right = nullptr;
    int freq = 1;

    Node(int data)
    {
        this->data = data;
    }

    Node(int data, Node *left, Node *right)
    {
        this->data = data;
        this->left = left;
        this->right = right;
    }
};

Node *create(vector<int> &arr, int si, int ei)
{
    if (si > ei)
        return NULL;

    if (si == ei)
    {
        Node *node = new Node(arr[si]);
        return node;
    }

    int mid = (si + ei) >> 1;

    Node *node = new Node(arr[mid]);

    node->left = create(arr, si, mid - 1);
    node->right = create(arr, mid + 1, ei);

    return node;
}

void display(Node *node)
{
    if (node == nullptr)
        return;

    string str = "";
    str += node->left == nullptr ? " . " : to_string(node->left->data);
    str += "=> " + to_string(node->data) + " <=";
    str += node->right == nullptr ? " . " : to_string(node->right->data);

    cout << str << "----" << node->freq << endl;

    display(node->left);
    display(node->right);
}

int mini(Node *node)
{
    Node *curr = node;
    while (curr->left != nullptr)
    {
        curr = curr->left;
    }
    return curr->data;
}

int maxi(Node *node)
{
    Node *curr = node;
    while (curr->right != nullptr)
    {
        curr = curr->right;
    }
    return curr->data;
}

int height(Node *node)
{
    return (node == nullptr) ? 0 : max(height(node->left), height(node->right)) + 1;
}

int size(Node *node)
{
    return (node == nullptr) ? 0 : size(node->left) + size(node->right) + 1;
}

bool find(Node *node, int data, int level)
{
    if (node == nullptr)
        return false;

    if (node->data < data)
        return find(node->right, data, level + 1);
    
    else if (node->data > data)
        return find(node->left, data, level + 1);

    else
    {
        cout << level + 1 << endl;
        return true;
    }
}

 /*Lowest common Ancester */

int LCA(Node *node, int n1, int n2)
{
    if (node == nullptr)
        return -1;

    if (node->data < n1 && node->data < n2)
    {
        return LCA(node->right, n1, n2);
    }

    else if (node->data > n2 && node->data > n1)
    {
        return LCA(node->left, n1, n2);
    }

    else
    {
        return node->data;
    }
}

Node *pre = NULL;
Node *pred = NULL;
Node *succ = NULL;
void predSucc_01(Node *node, int data)
{
    if (node == NULL)
        return;

    predSucc_01(node->left, data);

    if (node->data == data)
        pred = pre;
    if (pre != NULL && pre->data == data)
        succ = node;

    pre = node;

    predSucc_01(node->right, data);
}

/* add and delete nodes */

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

void addNode_01(Node *node, Node *par, int data, bool isLeft)
{
    if (node == nullptr)
    {
        Node *child = new Node(data);
        if (isLeft)
            par->left = child;

        else
            par->right = child;

        return;
    }

    if (node->data == data)
    {
        node->freq++;
        return;
    }

    else if (node->data < data)
    {
        addNode_01(node->right, par, data, false);
    }

    else
    {
        addNode_01(node->left, par, data, true);
    }
}

Node *deleteNode(Node *node, int data)
{
    if (node == nullptr)
    {
        return nullptr;
    }    

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
            if (node->left == nullptr || node->right == nullptr)
            {
                Node *n = node->left == nullptr ? node->right : node->left;
                delete node;
                return n;
            }

            int max_ = maxi(node->left);
            node->data = max_;
            node->left = deleteNode(node->left, max_);
        }
    }
    return node;
}

void solve()
{
    // vector<int> arr = {10, 20, 30, 40, 50, 60, 70, 80, 90, 100, 110, 120};
    // Node *root = create(arr, 0, arr.size() - 1);
    // display(root);
    // cout << endl;
    // cout << mini(root) << endl;
    // cout << maxi(root) << endl;
    // cout << height(root) << endl;
    // cout << size(root) << endl;
    // cout << (boolalpha) << find(root, 80, 0) << endl;

    // cout << LCA(root, 100, 120) << endl;  

    // predSucc_01(root, 70);

    vector<int> arr = {9, 10, 13, 25, 26, 27, 29, 30, 45, 50, 60, 63, 72, 75, 85};
    Node *root = create(arr, 0, arr.size() - 1);
    // display(root);
    // cout << endl;

    root = addNode(root, 65);
    display(root);
    cout << endl;

    addNode_01(root, root, 65, true);
    display(root);
    cout << endl;

    deleteNode(root, 65);
    display(root);
}

int main(int args, char **argv)
{
    solve();
    return 0;
}