#include<stack>
#include<list>
#include<queue>
#include<iostream>


namespace BinaryTree
{
    template<typename T>
    class Node
    {
    public:
        T val;
        Node* left = nullptr;
        Node* right = nullptr;

        Node(T data) { val = data; };
    };

    template<typename T>
    std::list<T> depthFirstTraversingUsingStack(Node<T>* root)
    {
        std::list<T> list;
        if (root)
        {
            std::stack<Node<T>*> stack;
            stack.push(root);
            while (!stack.empty())
            {
                Node* curNode = stack.top();
                stack.pop();
                list.push_back(curNode->val);
                if (curNode->right)
                    stack.push(curNode->right);
                if (curNode->left)
                    stack.push(curNode->left);
            }

        }
        return list;
    }

    template<typename T>
    std::list<T> depthFirstTraversingUsingRecusion(Node<T>* root)
    {
        std::list<T> list;
        if (root)
        {
            list.push_back(root->val);
            auto left = depthFirstTraversingUsingRecusion(root->left);
            auto right = depthFirstTraversingUsingRecusion(root->right);
            list.insert(list.end(), left.begin(), left.end());
            list.insert(list.end(), right.begin(), right.end());
        }
        return list;
    }

    template<typename T>
    std::list<T> breadthFirstTraversingUsingQueue(Node<T>* root)
    {
        std::list<T> list;
        if (root)
        {
            std::queue<Node<T>*> queue;
            queue.push(root);
            while (!queue.empty())
            {
                Node* curNode = queue.front();
                queue.pop();
                list.push_back(curNode->val);
                if (curNode->left)
                    queue.push(curNode->left);
                if (curNode->right)
                    queue.push(curNode->right);
            }

        }
        return list;
    }

    template<typename T>
    bool treeIncludesUsingBreadthFirstUsingQueue(Node<T>* root, T valIn)
    {
        bool foundIt = false;
        if (root)
        {
            std::queue<Node<T>*> queue;
            queue.push(root);
            while (!queue.empty())
            {
                Node* curNode = queue.front();
                queue.pop();
                if (curNode->val == valIn)
                    return true;
                if (curNode->left)
                    queue.push(curNode->left);
                if (curNode->right)
                    queue.push(curNode->right);
            }
        }
        return foundIt;
    }
    template<typename T>
    bool treeIncludesUsingDepthFirstUsingRecusion(Node<T>* root, T valIn)
    {
        if (!root) return false;
        if (root->val == valIn) return true;
        return (treeIncludesUsingDepthFirstUsingRecusion(root->left, valIn) || treeIncludesUsingDepthFirstUsingRecusion(root->right, valIn));
    }

    template<typename T>
    int treeSumUsingDepthFirstUsingRecusion(Node<T>* root)
    {
        if (!root) return 0;
        return (root->val + treeSumUsingDepthFirstUsingRecusion(root->left) + treeSumUsingDepthFirstUsingRecusion(root->right));
    }
};

using namespace BinaryTree;

void main()
{
    Node<int> A(1);
    Node<int> B(2);
    Node<int> C(3);
    Node<int> D(4);
    Node<int> E(5);
    Node<int> F(6);
    Node<int> G(7);

    A.left = &B;
    A.right = &C;
    B.left = &D;
    //B.right = &E;
    //C.left = &F;
    //C.right = &G;

    int isAvailable = treeSumUsingDepthFirstUsingRecusion(&A);
    std::cout << isAvailable << std::endl;

    //std::list<const char*> dataOut = breadthFirstTraversingUsingQueue(&A);

    /*for (auto data : dataOut)
        std::cout << data << std::endl;*/
}

