#include <iostream>
#include <unordered_map>
using namespace std;

int main()
{
    unordered_map<string, int> m;
    m["gfg"] = 30;
    m["ide"] = 20;
    m["course"] = 15;
    // for (auto x : m)
    // {
    //     cout << x.first << " " << x.second << endl;
    // }

    // for (auto it = m.begin(); it != m.end(); it++)
    // {
    //     cout << it->first << " " << it->second << endl;
    // }

    // if (m.find("ide") != m.end())
    // {
    //     cout << "Found\n";
    // }
    // else
    // {
    //     cout << "Not Found\n";
    // }

    // auto it = m.find("ide");
    // if (it != m.end())
    // {
    //     cout << it->second << endl;
    // }

    // if (m.count("ide") > 0)
    // {
    //     cout << "Found\n";
    // }
    // else
    // {
    //     cout << "Not Found\n";
    // }

    cout << m.size() << endl;
    // m.erase("ide");
    // m.erase(m.begin());
    m.erase(m.begin(), m.end());
    cout << m.size() << endl;
    return 0;
}