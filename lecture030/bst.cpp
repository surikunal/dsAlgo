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
void display(Node *node)
{
    if (node == nullptr) // nullptr and NULL are equal
        return;

    string str = "";
    str += node->left != nullptr ? to_string(node->left->data) : " . ";
    str += " => " + to_string(node->data) + " <= ";
    str += node->right != nullptr ? to_string(node->right->data) : " . ";
    cout << str << endl;

    display(node->left);
    display(node->right);
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

int minimum(Node *node)
{
    Node *curr = node;
    while (curr->left != nullptr)
    {
        curr = curr->left;
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

    else if (node->data == data)
    {
        cout << "Height of data " << level << endl;
        return true;
    }
}
bool find1(Node *node, int data, int level, string ans)
{
    if (node == nullptr)
        return false;

    if (node->data < data)
        return find1(node->right, data, level + 1, ans + to_string(node->data) + " ");

    else if (node->data > data)
        return find1(node->left, data, level + 1, ans + to_string(node->data) + " ");

    else if (node->data == data)
    {
        cout << ans << " " << data << endl;
        cout << "Height of data " << level << endl;
        return true;
    }
}
int LCA(Node *node, int n1, int n2)
{
    if (node == nullptr)
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
Node* pre = NULL;
Node* succ = NULL;
void preSucc_01(Node* node, int data)
{
    if(node == nullptr)
    return ;

    if(node -> data == data)
    {
        if(node -> left != nullptr)
        {
            Node* temp = node->left;
            while(temp->right)
            {
                temp = temp->right;
            }
            pre = temp;
        }
        if(node->right != NULL)
        {
            Node* temp = node->right;
            while(temp->left)
            {
                temp = temp->left;
            }
            succ = temp;
        }
        return;
    }
    if(node->data > data)
    {
        succ=root;
        preSucc_01(node->left, data);
    }
    else{
        pre = root;
        preSucc_01(node->right, data);
    }
}

void solve()
{
    vector<int> arr = {10, 20, 30, 40, 50, 60, 70, 80, 90, 100, 110, 120};
    Node *root = create(arr, 0, arr.size() - 1);
    display(root);
    // cout << maximum(root)<<endl;
    // cout << minimum(root)<<endl;
    // cout << height(root)<<endl;
    // cout << size(root)<<endl;
    // cout<<(boolalpha)<<find(root,80,0);              //TO FIND AT WHICH LEVEL WE FOUND DATA
    // cout << (boolalpha) << find1(root, 80, 0, ""); //TO TRACE THE PATH ALSO

    // cout<<LCA(root, 70, 110);

    cout<<preSucc_01(root, 70);
}
int main(int args, char **argv)
{
    solve();
    return 0;
}