#include <iostream>

using namespace std;

struct Node
{
    char *name;
    int age;
    Node(char *n = "", int a = 0)
    {
        name = strdup(n);
        age = a;
    }
    Node(const Node &n)
    {
        name = strdup(n.name);
        age = n.age;
    }
    Node &operator=(const Node &n)
    {
        if (this != &n)
        {
            if (name != 0)
            {
                free(name);
            }
            name = strdup(n.name);
            age = n.age;
        }
    }
    ~Node()
    {
        if (name != 0)
        {
            free(name);
        }
    }
};

int main()
{
    Node node1("ahmed", 26), node2 = node1;

    strcpy(node2.name, "ali");
    node2.age = 30;

    cout << node1.name << " " << node1.age << " " << node2.name << " " << node2.age << endl;

    return 0;
}