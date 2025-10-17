#include <iostream>
#include <vector>
using namespace std;

class Node
{
public:
    string key;
    int value;
    Node *next;
    Node(string key, int value)
    {
        this->key = key;
        this->value = value;
        next = nullptr;
    }
};

class HashTable
{
private:
    static const int SIZE = 7;
    Node *dataMap[SIZE];

public:
    HashTable()
    {
        for (int i = 0; i < SIZE; i++)
        {
            dataMap[i] = nullptr;
        }
    }

    int hash(string key)
    {
        int hash = 0;
        for (int i = 0; i < key.length(); i++)
        {
            int asciiValue = int(key[i]);
            hash = (hash + asciiValue * 23) % SIZE;
        }
        return hash;
    }

    void set(string key, int value)
    {
        int index = hash(key);
        Node *newNode = new Node(key, value);
        if (dataMap[index] == nullptr)
        {
            dataMap[index] = newNode;
        }
        else
        {
            Node *temp = dataMap[index];
            while (temp->next != nullptr)
            {
                temp = temp->next;
            }
            temp->next = newNode;
        }
    }

    int get(string key)
    {
        int index = hash(key);
        Node *temp = dataMap[index];
        while (temp)
        {
            if (temp->key == key)
            {
                return temp->value;
            }
            temp = temp->next;
        }
        delete (temp);
        return 0;
    }

    vector<string> keys()
    {
        vector<string> allKeys;
        for (int i = 0; i < SIZE; i++)
        {
            Node *temp = dataMap[i];
            while (temp != nullptr)
            {
                allKeys.push_back(temp->key);
                temp = temp->next;
            }
            delete (temp);
        }
        return allKeys;
    }

    void printKeys()
    {
        vector<string> allKeys = keys();
        cout << "[";
        for (size_t i = 0; i < allKeys.size(); ++i)
        {
            cout << allKeys[i];
            if (i != allKeys.size() - 1)
                cout << ", ";
        }
        cout << "]" << endl;
    }

    void printTable()
    {
        for (int i = 0; i < SIZE; i++)
        {
            cout << "Index " << i << ": ";
            if (dataMap[i])
            {
                cout << "Contains => ";
                Node *temp = dataMap[i];
                while (temp)
                {
                    cout << "{" << temp->key << ", " << temp->value << "}";
                    temp = temp->next;
                    if (temp)
                        cout << ", ";
                }
                cout << endl;
            }
            else
            {
                cout << "Empty" << endl;
            }
        }
    }

    ~HashTable()
    {
        for (int i = 0; i < SIZE; i++)
        {
            Node *head = dataMap[i];
            Node *temp = head;
            while (head)
            {
                head = head->next;
                delete temp;
                temp = head;
            }
        }
    }
};

int main()
{
    HashTable *myHashTable = new HashTable();
    myHashTable->set("nails", 100);
    myHashTable->set("tile", 50);
    myHashTable->set("lumber", 80);

    myHashTable->set("bolts", 200);
    myHashTable->set("screws", 140);
    myHashTable->printTable();
    cout << myHashTable->get("screws") << endl;
    myHashTable->printKeys();

    return 0;
}