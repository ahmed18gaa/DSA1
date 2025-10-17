#include <iostream>
using namespace std;

class Node
{
public:
    int value;
    Node *next;
    Node *prev;
    Node(int value)
    {
        this->value = value;
        this->next = nullptr;
        this->prev = nullptr;
    }
};

class DoublyLinkedList
{
private:
    Node *head;
    Node *tail;
    int length = 0;

public:
    DoublyLinkedList(int value)
    {
        Node *newNode = new Node(value);
        head = newNode;
        tail = newNode;
        length = 1;
    }

    void append(int value)
    {
        Node *newNode = new Node(value);
        if (length == 0)
        {
            head = newNode;
            tail = newNode;
        }
        else
        {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
        length++;
    }

    void deleteLast()
    {
        if (length == 0)
            return;
        Node *temp = tail;
        if (length == 1)
        {
            head = nullptr;
            tail = nullptr;
        }
        else
        {
            tail = tail->prev;
            tail->next = nullptr;
        }
        delete temp;
        length--;
    }

    void prepend(int value)
    {
        Node *newNode = new Node(value);
        if (length == 0)
        {
            head = newNode;
            tail = newNode;
        }
        else
        {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
        length++;
    }

    void deleteFirst()
    {
        if (length == 0)
            return;
        Node *temp = head;
        if (length == 1)
        {
            head = nullptr;
            tail = nullptr;
        }
        else
        {
            head = head->next;
            head->prev = nullptr;
            temp->next = nullptr;
        }
        delete temp;
        length--;
    }

    void printList()
    {
        Node *temp = head;
        if (temp == nullptr)
        {
            cout << "empty" << endl;
            return;
        }
        while (temp->next != nullptr)
        {
            cout << temp->value << " <-> ";
            temp = temp->next;
        }
        cout << temp->value << endl;
    }

    Node *get(int index)
    {
        if (index < 0 || index >= length)
            return nullptr;
        Node *temp = head;
        if (index < length / 2)
        {
            for (int i = 0; i < index; i++)
            {
                temp = temp->next;
            }
        }
        else
        {
            temp = tail;
            for (int i = length - 1; i > index; i--)
            {
                temp = temp->prev;
            }
        }

        return temp;
    }

    bool set(int index, int value)
    {
        Node *temp = get(index);
        if (temp)
        {
            temp->value = value;
            return true;
        }
        return false;
    }

    bool insert(int index, int value)
    {
        if (index < 0 || index > length)
            return false;
        if (index == 0)
        {
            prepend(value);
            return true;
        }
        if (index == length - 1)
        {
            append(value);
            return true;
        }

        Node *newNode = new Node(value);
        Node *before = get(index - 1);
        Node *after = before->next;
        newNode->prev = before;
        newNode->next = after;
        before->next = newNode;
        after->prev = newNode;
        length++;
        return true;
    }

    void deleteNode(int index)
    {
        if (index < 0 || index > length)
            return;
        if (index == 0)
            return deleteFirst();
        if (index == length - 1)
            return deleteLast();
        Node *temp = get(index);
        temp->next->prev = temp->prev;
        temp->prev->next = temp->next;
        // Node *before = get(index - 1);
        // Node *temp = before->next;
        // Node *after = before->next->next;

        // before->next = after;
        // after->prev = before;
        length--;
        delete temp;
    }

    Node *getHead()
    {
        return head;
    }

    Node *getTail()
    {
        return tail;
    }

    bool isPalindrome()
    {
        if (length <= 1)
            return true;

        Node *forwardNode = head;
        Node *backwardNode = tail;
        for (int i = 0; i < length / 2; i++)
        {
            if (forwardNode->value != backwardNode->value)
                return false;
            forwardNode = forwardNode->next;
            backwardNode = backwardNode->prev;
        }
        return true;
    }

    int getLength()
    {
        return length;
    }

    void reverse()
    {
        Node *current = head;
        Node *temp = nullptr;

        while (current != nullptr)
        {
            temp = current->prev;
            current->prev = current->next;
            current->next = temp;
            current = current->prev;
        }

        temp = head;
        head = tail;
        tail = temp;
    }

    void partitionList(int x)
    {
        // If the list is empty, do nothing
        if (!head)
            return;

        // Create two dummy nodes to start the two partitions
        Node *dummy1 = new Node(0); // For values < x
        Node *dummy2 = new Node(0); // For values >= x

        // prev1 and prev2 will build the two lists
        Node *prev1 = dummy1;
        Node *prev2 = dummy2;

        Node *current = head;

        while (current != nullptr)
        {
            Node *nextNode = current->next; // Save the next node

            // Disconnect the node from the list
            current->next = nullptr;
            current->prev = nullptr;

            if (current->value < x)
            {
                // Append to the 'less than x' list
                prev1->next = current;
                current->prev = prev1;
                prev1 = current;
            }
            else
            {
                // Append to the 'greater or equal to x' list
                prev2->next = current;
                current->prev = prev2;
                prev2 = current;
            }

            current = nextNode;
        }

        // Terminate the greater-or-equal list
        prev2->next = nullptr;

        // Connect the two lists
        prev1->next = dummy2->next;

        if (dummy2->next != nullptr)
        {
            dummy2->next->prev = prev1;
        }

        // Update the head of the full list
        head = dummy1->next;
        if (head)
            head->prev = nullptr;

        // Clean up
        delete dummy1;
        delete dummy2;
    }

    void reverseBetween(int startIndex, int endIndex)
    {
        // Return early if list is empty or no range to reverse
        if (head == nullptr || startIndex == endIndex)
            return;

        // Dummy node simplifies edge case handling
        Node *dummy = new Node(0);
        dummy->next = head;
        head->prev = dummy;

        // Traverse to node BEFORE start index
        Node *prev = dummy;
        for (int i = 0; i < startIndex; i++)
        {
            prev = prev->next;
        }

        // 'current' is the start of the sublist to reverse
        Node *current = prev->next;

        // Reverse using node splicing
        for (int i = 0; i < endIndex - startIndex; i++)
        {
            Node *nodeToMove = current->next;

            // Detach nodeToMove
            current->next = nodeToMove->next;
            if (nodeToMove->next)
            {
                nodeToMove->next->prev = current;
            }

            // Insert nodeToMove after prev
            nodeToMove->next = prev->next;
            prev->next->prev = nodeToMove;
            prev->next = nodeToMove;
            nodeToMove->prev = prev;
        }

        // Update head in case it changed
        head = dummy->next;
        head->prev = nullptr;

        delete dummy;
    }

    void swapPairs()
    {
        // Create a dummyNode with value 0. This node serves as
        // a placeholder that sits before the actual head node.
        // This makes it easier to swap the head node later.
        Node dummyNode(0);

        // Connect the next pointer of dummyNode to the current
        // head of the linked list. This links dummyNode to
        // the first node in the list.
        dummyNode.next = head;

        // Initialize previousNode to point to dummyNode.
        // This node helps us keep track of the last node we
        // visited as we traverse the list.
        Node *previousNode = &dummyNode;

        // Begin a loop that continues as long as there are
        // at least two more nodes to swap.
        while (head != nullptr && head->next != nullptr)
        {

            // Initialize firstNode and secondNode to point to the
            // two nodes we will swap. firstNode points to what
            // head is pointing to, and secondNode points to the
            // node right after firstNode.
            Node *firstNode = head;
            Node *secondNode = head->next;

            // Unlink firstNode and secondNode from the list and
            // link secondNode to previousNode.
            previousNode->next = secondNode;

            // Unlink secondNode from its next node and link
            // it to firstNode.
            firstNode->next = secondNode->next;

            // Link secondNode back to firstNode.
            secondNode->next = firstNode;

            // Update the 'prev' pointers to maintain the
            // doubly-linked list structure.
            secondNode->prev = previousNode;
            firstNode->prev = secondNode;

            // If a node exists after firstNode, update its 'prev'
            // to point back to firstNode.
            if (firstNode->next != nullptr)
            {
                firstNode->next->prev = firstNode;
            }

            // Move head and previousNode pointers to their
            // next positions for the following iteration.
            head = firstNode->next;
            previousNode = firstNode;
        }

        // After all pairs are swapped, update the actual
        // head of the list to point to the new first node.
        head = dummyNode.next;

        // Ensure the 'prev' of the new head node is null.
        if (head)
            head->prev = nullptr;
    }

    void makeEmpty()
    {
        Node *current = head;
        while (current != nullptr)
        {
            Node *nodeToDelete = current;
            current = current->next;
            delete nodeToDelete;
        }
        head = nullptr;
        tail = nullptr;
        length = 0;
    }

    ~DoublyLinkedList()
    {
        Node *temp = head;
        while (head)
        {
            head = head->next;
            delete temp;
            temp = head;
        }
    }
};

int main()
{
    DoublyLinkedList *dll = new DoublyLinkedList(6);
    dll->append(1);
    dll->append(5);
    dll->append(2);
    dll->append(4);
    dll->append(3);
    dll->printList();
    dll->partitionList(3);
    dll->printList();
    // dll->reverse();
    // dll->printList();
    // cout << dll->isPalindrome() << endl;
    // dll->deleteNode(2);
    // dll->printList();
    // dll->insert(1, 7);
    // dll->insert(6, 8);
    // dll->printList();
    // dll->deleteLast();
    // dll->printList();
    // dll->prepend(0);
    // dll->printList();
    // dll->deleteFirst();
    // dll->deleteFirst();
    // dll->deleteFirst();
    // dll->printList();
    // cout << dll->get(0)->value << endl;
    delete dll;
    return 0;
}