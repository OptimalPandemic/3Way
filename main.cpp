#include <iostream>

struct Node
{
    int v1, v2;
    Node *c1, *c2, *c3; // Almost fell for that one!
    void addNode(int, int);
    void addNode(Node&);
    Node(int, int, Node*, Node*, Node*);
    void showTree();
};

/**
 * @param v1 use -1 as NULL
 * @param v2 use -1 as NULL
 */
void Node::addNode(int v1, int v2)
{
    Node *n = new Node(v1, v2, NULL, NULL, NULL);
    if(this->c1 == NULL)
        this->c1 = n;
    else if(this->c2 == NULL)
        this->c2 = n;
    else if(this->c3 == NULL)
    {
        this->c3 = n;
    }
    else
        throw "Failed to add Node, no child slots available.";
}

/**
 * @param v1 use -1 as NULL
 * @param v2 use -1 as NULL
 */
void Node::addNode(Node &n)
{
    if(this->c1 == NULL)
        this->c1 = &n;
    else if(this->c2 == NULL)
        this->c2 = &n;
    else if(this->c3 == NULL)
        this->c3 = &n;
    else
        throw "Failed to add Node, no child slots available.";
}

/**
 * @param v1 use -1 as NULL
 * @param v2 use -1 as NULL
 */
Node::Node(int v1, int v2, Node* c1, Node* c2, Node* c3)
{
    this->v1 = v1;
    this->v2 = v2;
    this->c1 = c1;
    this->c2 = c2;
    this->c3 = c3;
}

void Node::showTree()
{
    std::cout << " NODE VALUE 1: " << this->v1 << std::endl;
    std::cout << " NODE VALUE 2: " << this->v2 << std::endl;
    if(this->c1 != NULL)
    {
        std::cout << "----TREE OF CHILD 1 START----" << std:: endl;
        this->c1->showTree();
        std::cout << "----TREE OF CHILD 1 END----" << std:: endl;
    }
    if(this->c2 != NULL)
    {
        std::cout << "----TREE OF CHILD 2 START----" << std:: endl;
        this->c2->showTree();
        std::cout << "----TREE OF CHILD 2 END----" << std:: endl;
    }
    if(this->c3 != NULL)
    {
        std::cout << "----TREE OF CHILD 3 START----" << std:: endl;
        this->c3->showTree();
        std::cout << "----TREE OF CHILD 3 END----" << std:: endl;
    }
};

int main()
{
    Node n(25, 30, NULL, NULL, NULL); // Instantiate a node with no children
    Node n2(500, -1, NULL, NULL, NULL);

    n.addNode(50, 45);
    n.addNode(n2);

    n.showTree();
    return 0;
}