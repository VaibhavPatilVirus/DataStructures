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
                Node<T>* curNode = queue.front();
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

    template<typename T>
    void printList(std::list<T> listIn)
    {
        for (auto data : listIn)
            std::cout << data << std::endl;
    }
    template<typename T>
    Node<T>* createBinaryTree(const std::list<T>& listIn)
    {
        std::queue<Node<T>*> stack;
        Node<T>* rootNode = nullptr;
        for (auto data: listIn)
        {
            if (rootNode == nullptr)
            {
                rootNode = new Node<T>(data);
                stack.push(rootNode);
            }
            else
            {
                Node<T>* nodeToAppend = stack.front();
                Node<T>* newNode = new Node<T>(data);
                if (nodeToAppend->left == nullptr)
                    nodeToAppend->left = newNode;
                else if (nodeToAppend->right == nullptr)
                {
                    nodeToAppend->right = newNode;
                    stack.pop();
                }
                stack.push(newNode);
            }
        }
        return rootNode;
    }

    template <typename T>
    Node<T>* addNode(Node<T>* root, Node<T>* newNode)
    {
        if (root == nullptr)
            return newNode;

        std::queue<Node<T>*> queue;
        queue.push(root);
        while (!queue.empty())
        {
            Node<T>* exitingNode = queue.front();
            if (exitingNode->left == nullptr)
            {
                exitingNode->left = newNode;
                break;
            }
            else
                queue.push(exitingNode->left);
            
            if (exitingNode->right == nullptr)
            {
                exitingNode->right = newNode;
                break;
            }
            else
            {
                queue.push(exitingNode->right);
                queue.pop();
            }
        }
    
        return root;
    }

    template <typename T>
    Node<T>* addNode(Node<T>* root,const T& dataIn)
    {
        return addNode(root, new Node<T>(dataIn));
    }

    template <typename T>
    void deleteNode(Node<T>* root, int pos)
    {
        if (root == nullptr) return;


    }
};

using namespace BinaryTree;

void main()
{
    //Node<int> A(1);
    //Node<int> B(2);
    //Node<int> C(3);
    //Node<int> D(4);
    //Node<int> E(5);
    //Node<int> F(6);
    //Node<int> G(7);

    //A.left = &B;
    //A.right = &C;
    //B.left = &D;
    ////B.right = &E;
    ////C.left = &F;
    ////C.right = &G;

    /*int isAvailable = treeSumUsingDepthFirstUsingRecusion(&A);
    std::cout << isAvailable << std::endl;*/

    std::list<int> list = { 1,2 };
    Node<int>* binaryTree = createBinaryTree(list);
    
    binaryTree = addNode(binaryTree, 3);
    binaryTree = addNode(binaryTree, 4);
    //binaryTree = addNode(binaryTree, 5);
    binaryTree = addNode(binaryTree, 6);
    std::list<int> dataOut = breadthFirstTraversingUsingQueue(binaryTree);
}

