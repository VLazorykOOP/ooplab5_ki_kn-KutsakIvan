#include <iostream>
#include <Windows.h>

using namespace std;

class Node
{
public:
    int data;
    Node* left;
    Node* right;

    Node(int data)
    {
        this->data = data;
        left = NULL;
        right = NULL;
    }
};

class BinaryTree
{
public:
    Node* root;

    BinaryTree()
    {
        root = NULL;
    }

    void insert(int data)
    {
        int x = data, k = 0;
        while (k == 0)
        {
            Node* node = new Node(x);
            if (root == NULL)
            {
                root = node; k = 1;
            }
            else
            {
                Node* current = root;
                while (true)
                {
                    if (x < current->data)
                    {
                        if (current->left == NULL)
                        {
                            current->left = node; k = 1;
                            break;
                        }
                        else
                        {
                            current = current->left;
                        }
                    }
                    else if (x > current->data)
                    {
                        if (current->right == NULL)
                        {
                            current->right = node; k = 1;
                            break;
                        }
                        else
                        {
                            current = current->right;
                        }
                    }
                    else
                    {
                        cout << "Значення вже існує. Введіть інше число" << endl; cin >> x;
                        delete node;
                        break;
                    }
                }
            }
        }
    }

    void inOrder(Node* node) //Послідовний обхід
    {
        if (node == NULL)
        {
            return;
        }
        inOrder(node->left);
        cout << node->data << " ";
        inOrder(node->right);
    }

    void postOrder(Node* node) //Зворотній обхід
    {
        if (node == NULL)
        {
            return;
        }
        postOrder(node->left);
        postOrder(node->right);
        cout << node->data << " ";
    }
};

void main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    int n, x;
    BinaryTree tree;
    cout << "Введіть кількість вузлів в дереві: "; cin >> n;
    cout << "\nЗаповніть інформацію\n";
    for (int i = 0; i < n; i++)
    {
        cin >> x;
        tree.insert(x);
    }

    cout << "Послідовний обхід: ";
    tree.inOrder(tree.root);
    cout << endl;

    cout << "Зворотній обхід: ";
    tree.postOrder(tree.root);
    cout << endl;
}
