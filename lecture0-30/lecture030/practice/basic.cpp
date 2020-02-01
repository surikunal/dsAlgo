#include <iostream>
#include <vector>
#include <string>
using namespace std;
class Node
{
public:
    int data = 0;
    Node *left = nullptr;
    Node *right = nullptr;

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
    int mid = ((si + ei) >> 1);

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
    str += "=>" + to_string(node->data) + "<=";
    str += node->right == nullptr ? " . " : to_string(node->right->data);

    cout << str << endl;

    display(node->left);
    display(node->right);
}

int height(Node *node)
{
    return node == NULL ? 0 : max(height(node->left), height(node->right)) + 1;
}
int size(Node *node)
{
    return node == NULL ? 0 : size(node->left) + size(node->right) + 1;
}
int maxi(Node *node)
{
    Node *curr = node;
    while (curr->right != NULL)
    {
        curr = curr->right;
    }
    return curr->data;
}
int mini(Node *node)
{
    Node *curr = node;
    while (curr->left != NULL)
    {
        curr = curr->left;
    }
    return curr->data;
}
bool find(Node *node, int data, int level, string ans)
{
    if (node == nullptr)
        return false;

    if (node->data < data)
    {
        return find(node->right, data, level + 1, ans + to_string(node->data));
    }
    else if (node->data < data)
    {
        return find(node->left, data, level + 1, ans + to_string(node->data));
    }
    else if (node->data == data)
    {
        cout << "height is " << level << endl;
        return true;
    }
}
int LCA(Node *node, int n1, int n2)
{
    if (node == NULL)
        return -1;

    if (node->data < n1)
    {
        return LCA(node->right, n1, n2);
    }
    else if (node->data > n2)
    {
        return LCA(node->left, n1, n2);
    }
    else
    {
        return node->data;
    }
}
int main(int args, char **argv)
{
    vector<int> arr = {10, 20, 30, 40, 50, 60, 70, 80, 90, 100, 110, 120};
    Node *root = create(arr, 0, arr.size() - 1);
    // display(root);
    // cout << height(root) << endl;
    // cout << size(root) << endl;
    // cout << mini(root) << endl;
    // cout << maxi(root) << endl;
    // cout << (boolalpha) << find(root, 30, 0, "") << endl;
    // cout << LCA(root, 80, 100);
    return 0;
}