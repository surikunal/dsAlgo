#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class Node
{
public:
    int data = 0;
    vector<Node *> childs;
    Node()
    {
    }

    Node(int data)
    {
        this->data = data;
    }
};

Node *createTree(vector<int> &arr)
{
    stack<Node *> st;
    for (int i = 0; i < arr.size() - 1; i++)
    {
        if (arr[i] != -1)
        {
            Node *node = new Node(arr[i]);
            st.push(node);
        }
        else
        {
            Node *node = st.top();
            st.pop();
            st.top()->childs.push_back(node); //to create a connection btw child and parent
        }
    }
    return st.top();
}

void display(Node *node)
{
    cout << node->data << "->";
    for (Node *child : node->childs)
    {
        cout << child->data << ", ";
    }
    cout << endl;

    for (Node *child : node->childs)
    {
        display(child);
    }
}

Node *linearize_02(Node *node)
{
    if (node->childs.size() == 0)
    {
        return node;
    }

    Node *myTail = linearize_02(node->childs.back());

    for (int i = node->childs.size() - 2; i >= 0; i--)
    {
        Node *tail = linearize_02(node->childs[i]);
        tail->childs.push_back(node->childs.back());

        node->childs.pop_back();
    }
    return myTail;
}

/* for 1 tree */
bool isSymmetric(Node *node1, Node *node2)
{
    if (node1->childs.size() != node2->childs.size())
    {
        return false;
    }

    for (int i = 0, j = node1->childs.size() - 1; i <= j; i++, j--)
    {
        Node *child1 = node1->childs[i];
        Node *child2 = node2->childs[j];

        if (!isSymmetric(child1, child2))
        {
            return false;
        }
    }
    return true;
}

/* for 2 trees */
bool isTreeSymmetric(Node *node1, Node *node2)
{
    if (node1->childs.size() != node2->childs.size())
    {
        return false;
    }

    for (int i = 0, j = node1->childs.size() - 1; j >= 0; i++, j--)
    {
        Node *child1 = node1->childs[i];
        Node *child2 = node2->childs[j];

        if (!isSymmetric(child1, child2))
        {
            return false;
        }
    }
    return true;
}

bool isMirror(Node *node1, Node *node2)
{

    if (node1->childs.size() != node2->childs.size() || node1->data != node2->data)
    {
        return false;
    }

    for (int i = 0, j = node1->childs.size() - 1; i <= j; i++, j--)
    {
        Node *child1 = node1->childs[i];
        Node *child2 = node2->childs[j];

        if (!isMirror(child1, child2))
        {
            return false;
        }
    }
    return true;
}



void solve()
{
    vector<int> arr1{10, 20, 50, -1, 60, -1, -1, 30, 70, -1, 80, 100, -1, 110, -1, -1, 90, -1, -1, 40, -1, -1};
    // vector<int> arr2{10, 20, -1, 30, 80, -1, 40, -1};
    Node *root1 = createTree(arr1);
    // Node *root2 = createTree(arr2);
    // display(root);
    // cout << endl;

    // linearize_02(root);
    // display(root);
    // cout << endl;

    // cout << (boolalpha) << isSymmetric(root, root);

    // cout << (boolalpha) << isTreeSymmetric(root1, root2);

    // cout << (boolalpha) << isMirror(root, root);

    //TODO: there are some more questions too 
    @by kunal 
}

int main(int args, char **argv)
{
    solve();
    return 0;
}