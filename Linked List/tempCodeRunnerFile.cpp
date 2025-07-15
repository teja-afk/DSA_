void insertAtTail(int value, Node *&head, Node *&tail)
{
    if (head == NULL && tail == NULL)
    {
        // LL is empty
        // step1: create node, head on that node, tail on that node
        Node *newNode = new Node(value);
        // step2: connect LL to newNode
        head = newNode;
        // step3: update tail
        tail = newNode;
    }
    else
    {
        // LL is not empty
        // step1: create node
        Node *newNode = new Node(value);
        // step2: tail node ko new node se connect karo
        tail->next = newNode;
        // step3: tail update
        tail = newNode;
    }
}