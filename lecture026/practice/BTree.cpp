#include <iostream>
#include <string>
#include <vector>
#include <queue>
using namespace std;
class Node
{
public:
    int data = 0;
    struct Node *left = NULL;
    struct Node *right = NULL;

    // Node()
    // {
    //     this->data = 0;
    //     this->left = nullptr;
    //     this->right = nullptr;
    // }
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
    if (node == nullptr)
        return;

    string str = "";
    str += node->left == nullptr ? " . " : to_string(node->left->data);
    str += " => " + to_string(node->data) + " <= ";
    str += node->right == nullptr ? " . " : to_string(node->right->data);
    cout << str << endl;

    display(node->left);
    display(node->right);
}

static int idx = 0;

Node *constructor(vector<int> &arr)
{
    if(idx >= arr.size() || arr[idx] == -1)
    {
        idx++;
        return nullptr;
    }

    Node *node = new Node(arr[idx]);
    idx++;
    node->left = constructor(arr);
    node->right = constructor(arr);

    return node;
}
void levelOrder(Node* root)
{
    if(root == NULL)  return;

    queue<Node* > myQue;
    myQue.push(root);

    while (!myQue.empty())
    {
        Node* node = myQue.front();
        cout << node->data << " ";
        myQue.pop();
    
    if (node->left != nullptr)
        myQue.push(node->left);

    if (node->right != nullptr)
        myQue.push(node->right);
    }
}
void levelOrder2_1(Node *root)
{
    queue<Node *> que1;
    queue<Node *> que2;
    que1.push(root);
    while(!que1.empty())
    {
        Node *node = que1.front();
        cout<<node->data<<" ";
        que1.pop();

        if(node->left != nullptr)
        que2.push(node->left);

        if(node->right != nullptr)
        que2.push(node->right);

        if(que1.size() == 0)
        {
            cout<<"\n";
            queue<Node *> temp = que1;
            que1=que2;
            que2=temp;
        }
    }
}
void levelOrder2_2(Node* root)
{
    queue<Node *> que;
    que.push(root);
    while(!que.empty())
    {
        int size = que.size();
        while(size --> 0)
        {
            Node* proc = que.front();
            cout<<proc->data<<" ";
            que.pop();

            if(proc->left != nullptr)   que.push(proc->left);
            if(proc->right != nullptr)   que.push(proc->right);
        }
        cout<<"\n";
    }
}
void levelOrder2_3(Node* root)
{
    queue<Node *> que;
    que.push(root);
    que.push(nullptr);
    while(!que.empty())
    {
        Node *node = que.front();
        que.pop();

        if(node == nullptr && que.size() > 0)
        {
            que.push(nullptr);
            cout<<"\n";
        }
        else{
            if(node != nullptr)
            {
                cout<<node->data<<" ";
                if(node->left != nullptr)
                que.push(node->left);

                if(node->right != nullptr)
                que.push(node->right);
            }
        }
    }
}
void solve()
{
    vector<int> arr = {10, 20, 40, 80, -1, -1, 90, -1, -1, 50, 100, -1, -1, -1, 30, 60, -1, 110, -1, -1, 70, 120, -1, -1, -1 };
    Node *root = constructor(arr);
    // display(root);
    // levelOrder(root);
    // levelOrder2_1(root);
    // levelOrder2_2(root);
    // levelOrder2_3(root);
}
int main(int args, char **argv)
{
    solve();
    return 0;
}