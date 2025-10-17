#include <iostream>
using namespace std;
class Node
{
public:
    int value;
    Node *next;
    Node(int value)
    {
        this->value = value;
        next = nullptr;
    }
};

class LinkedList
{
private:
    Node *head;
    Node *tail;
    int length = 0;

public:
    LinkedList(int value)
    {
        Node *newNode = new Node(value);
        head = newNode;
        tail = newNode;
        length = 1;
    }

    void Append(int value)
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
            tail = newNode;
        }
        length += 1;
    }

    void deleteLast()
    {
        if (length == 0)
        {
            return;
        }
        Node *temp = head;
        if (length == 1)
        {
            head = nullptr;
            tail = nullptr;
        }
        else
        {
            Node *pre = head;
            while (temp->next != nullptr)
            {
                pre = temp;
                temp = temp->next;
            }
            tail = pre;
            tail->next = nullptr;
        }
        length -= 1;
        delete temp;
    }

    void deleteFirst()
    {
        if (length == 0)
        {
            return;
        }
        Node *temp = head;
        if (length == 1)
        {
            head = nullptr;
            tail = nullptr;
        }
        else
        {
            head = head->next;
        }
        length -= 1;
        delete temp;
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
            head = newNode;
        }
        length += 1;
    }

    void makeEmpty()
    {
        Node *temp = head;
        while (head)
        {
            head = head->next;
            delete temp;
            temp = head;
        }
        tail = nullptr;
        length = 0;
    }

    void printList()
    {
        Node *temp = head;
        if (temp == nullptr)
        {
            cout << "empty";
        }
        else
        {
            while (temp != nullptr)
            {
                cout << temp->value;
                temp = temp->next;
                if (temp != nullptr)
                {
                    cout << " -> ";
                }
            }
        }
        cout << endl;
    }

    Node *get(int index)
    {
        if (index < 0 || index >= length)
        {
            return nullptr;
        }
        Node *temp = head;
        for (int i = 0; i < index; i++)
        {
            temp = temp->next;
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
        {
            return false;
        }
        if (index == 0)
        {
            prepend(value);
            return true;
        }
        if (index == length)
        {
            Append(value);
            return true;
        }
        Node *newNode = new Node(value);
        Node *temp = get(index - 1);

        newNode->next = temp->next;
        temp->next = newNode;
        length++;
        return true;
    }

    void deleteNode(int index)
    {
        if (index < 0 || index >= length)
        {
            return;
        }
        else if (index == 0)
        {
            return deleteFirst();
        }
        else if (index == length - 1)
        {
            return deleteLast();
        }
        else
        {
            Node *prev = get(index - 1);
            Node *temp = prev->next;
            prev->next = temp->next;
            delete temp;
            length--;
        }
    }

    void reverse()
    {
        Node *temp = head;
        head = tail;
        tail = temp;
        Node *after = temp->next;
        Node *before = nullptr;
        for (int i = 0; i < length; i++)
        {
            after = temp->next;
            temp->next = before;
            before = temp;
            temp = after;
        }
    }

    Node *findMiddleNode()
    {
        // Initialize slow and fast pointers to head
        Node *slow = head;
        Node *fast = head;

        // Traverse the list until fast reaches the end
        while (fast != nullptr && fast->next != nullptr)
        {
            // Move slow pointer one step forward
            slow = slow->next;

            // Move fast pointer two steps forward
            fast = fast->next->next;
        }

        // When the loop ends, slow points to the middle
        return slow;
    }

    bool hasLoop()
    {
        Node *fast = head;
        Node *slow = head;
        while (fast != nullptr && fast->next != nullptr)
        {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast)
            {
                return true;
            }
        }
        return false;
    }

    Node *findKthFromEnd(int k)
    {
        Node *fast = head;
        Node *slow = head;
        for (int i = 0; i < k; i++)
        {
            if (fast == nullptr)
            {
                return nullptr;
            }
            fast = fast->next;
        }
        while (fast != nullptr)
        {
            slow = slow->next;
            fast = fast->next;
        }
        return slow;
    }

    Node *removeNthFromEnd(int n)
    {
        Node dummy(0);     // create a dummy node
        dummy.next = head; // point it to head
        Node *fast = &dummy;
        Node *slow = &dummy;

        // Move fast pointer n+1 steps ahead
        for (int i = 0; i < n + 1; i++)
        {
            if (fast == nullptr)
                return head; // n is larger than list length
            fast = fast->next;
        }

        // Move both until fast reaches the end
        while (fast != nullptr)
        {
            slow = slow->next;
            fast = fast->next;
        }

        // Remove the node
        Node *temp = slow->next;
        if (temp != nullptr)
        {
            slow->next = temp->next;
            delete temp;
        }

        head = dummy.next; // update head in case the first node was removed
        return head;
    }

    void removeDuplicates()
    {
        Node *current = head;
        while (current != nullptr)
        {
            Node *runner = current;
            while (runner->next != nullptr)
            {
                if (runner->next->value == current->value)
                {
                    Node *temp = runner->next;
                    runner->next = runner->next->next;
                    delete temp;
                    length -= 1;
                }
                else
                {
                    runner = runner->next;
                }
            }
            current = current->next;
        }
    }

    int binaryToDecimal()
    {
        Node *cur = head;
        int sum = 0;
        while (cur)
        {
            sum = sum * 2 + cur->value; // shift left and add current bit
            cur = cur->next;
        }
        return sum;
    }

    void partitionList(int x)
    {
        // Return if the list is empty
        if (head == nullptr)
            return;

        // Create dummy nodes for two lists
        Node dummy1(0);
        Node dummy2(0);
        // Initialize pointers for two lists
        Node *prev1 = &dummy1;
        Node *prev2 = &dummy2;
        // Initialize the current pointer
        Node *current = head;

        // Iterate through the list
        while (current != nullptr)
        {
            // If the value is less than x
            if (current->value < x)
            {
                prev1->next = current;
                prev1 = current;
            }
            else
            { // If the value is >= x
                prev2->next = current;
                prev2 = current;
            }
            // Move to the next node
            current = current->next;
        }

        // Terminate the second list
        prev2->next = nullptr;
        // Connect the two lists
        prev1->next = dummy2.next;
        // Update the head of the list
        head = dummy1.next;
    }

    void reverseBetween(int m, int n)
    {
        // 1. Initial Check:
        // If the list is empty, there's nothing to reverse.
        // So, exit the function without doing anything.
        if (head == nullptr)
            return;

        // 2. Dummy Node Creation:
        // We initiate a new 'dummy' node with value 0.
        // This is a trick to simplify the edge cases.
        Node *dummy = new Node(0);

        // Connect our actual list right after the dummy node.
        // So, the dummy node temporarily stands before the head.
        dummy->next = head;

        // 3. Positioning 'prev':
        // Start with 'prev' pointing to the dummy node.
        Node *prev = dummy;

        // Move 'prev' up to the node just before the starting
        // point of the section we want to reverse.
        for (int i = 0; i < m; i++)
        {
            prev = prev->next;
        }

        // 4. Setting up 'current':
        // 'current' is set right after 'prev'.
        // It marks the start of the section to be reversed.
        Node *current = prev->next;

        // 5. Main Reversal Logic:
        // We now enter our core reversal loop.
        for (int i = 0; i < n - m; i++)
        {
            // 'temp' points to the node that's next in line
            // for our reversal process.
            Node *temp = current->next;

            // Detach 'temp' from the current sequence by
            // making 'current' skip over 'temp'.
            current->next = temp->next;

            // To move 'temp' to the start of our reversed section,
            // we first let 'temp' point to whatever node 'prev' is pointing to.
            temp->next = prev->next;

            // Finally, we adjust 'prev' to point to 'temp', thereby
            // moving 'temp' to the front of the reversed section.
            prev->next = temp;
        }

        // 6. Updating Head:
        // If our reversed section included the original head of the list,
        // our list's head would have changed.
        // So, we need to update the head of our list.
        head = dummy->next;

        // 7. Cleanup:
        // The dummy node has served its purpose.
        // We free up its memory to avoid memory leaks.
        delete dummy;
    }

    void swapPairs()
    {
        // Create a dummy node that points to head
        Node *dummy = new Node(0);
        dummy->next = head;

        // Start with dummy before the first pair
        Node *previous = dummy;
        Node *first = head;

        // Continue as long as we have at least two nodes
        while (first != nullptr && first->next != nullptr)
        {
            Node *second = first->next; // Second node of the pair

            previous->next = second;    // Step 1: Link prev to second
            first->next = second->next; // Step 2: Link first to the node after second
            second->next = first;       // Step 3: Link second to first

            previous = first;    // Move previous to first
            first = first->next; // Move to the next pair
        }

        // Update the head pointer
        head = dummy->next;
        delete dummy;
    }

    void reorderList()
    {
        // base case : linkedlist is empty
        if (!head)
            return;

        // finding the middle with the help of two pointer approach
        Node *tmp = head, *first = head, *half = head, *prev = NULL;
        while (tmp->next && tmp->next->next)
        {
            tmp = tmp->next->next;
            half = half->next;
        }

        cout << tmp->value << " : " << half->value << endl;

        // adding one bit in case of lists with even length
        if (tmp->next)
            half = half->next;

        cout << tmp->value << " : " << half->value << endl;
        // Now reverse the second half
        while (half)
        {
            tmp = half->next;
            half->next = prev;
            prev = half;
            half = tmp;
        }
        half = prev;

        // After reversing the second half, let's merge both the halfes
        while (first && half)
        {
            tmp = first->next;
            prev = half->next;
            first->next = half;
            half->next = tmp;
            first = tmp;
            half = prev;
        }

        // Base case : closing when we had even length arrays
        if (first && first->next)
            first->next->next = NULL;
    }

    Node *mergeTwoLists(Node *list1, Node *list2)
    {
        Node *dummy = new Node(0);
        Node *current = dummy;

        while (list1 != nullptr && list2 != nullptr)
        {
            if (list1->value <= list2->value)
            {
                current->next = list1;
                list1 = list1->next;
            }
            else
            {
                current->next = list2;
                list2 = list2->next;
            }
            current = current->next;
        }

        if (list1 != nullptr)
        {
            current->next = list1;
        }
        else
        {
            current->next = list2;
        }

        Node *head = dummy->next;
        delete dummy;
        return head;
    }

    Node *swapPairs(Node *head)
    {
        // Node dummy(0, head);
        Node *dummy = new Node(0);
        dummy->next = head;
        Node *prev = dummy;
        Node *cur = head;
        while (cur && cur->next)
        {
            Node *nextPair = cur->next->next;
            Node *second = cur->next;

            second->next = cur;
            cur->next = nextPair;
            prev->next = second;

            prev = cur;
            cur = nextPair;
        }

        return dummy->next;
    }

    ~LinkedList()
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
    // LinkedList *ll = new LinkedList(43);
    // ll->Append(23);
    // ll->Append(86);
    // ll->Append(22);
    // ll->Append(22);
    // ll->printList();
    // ll->set(1, 24);
    // ll->printList();
    // ll->insert(3, 85);
    // ll->printList();
    // // ll->reverse();
    // // ll->printList();
    // cout << "Middle Node: " << ll->findMiddleNode()->value << endl;
    // cout << "----------------------" << endl;
    // ll->removeDuplicates();
    // ll->printList();
    // ll->swapPairs();
    // ll->printList();
    LinkedList *ll = new LinkedList(1);
    ll->Append(2);
    ll->Append(3);
    ll->Append(4);
    ll->Append(5);
    ll->Append(6);
    // ll->reorderList();
    ll->printList();
    cout << ll->removeNthFromEnd(3)->value << endl;
    ll->printList();
    delete ll;
    return 0;
}