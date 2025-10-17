#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

bool iteminCommon(vector<int> vect1, vector<int> vect2)
{
    unordered_map<int, bool> myMap;
    for (auto i : vect1)
    {
        myMap.insert({i, true});
    }
    for (auto j : vect2)
    {
        if (myMap[j])
            return true;
    }
    return false;
}

vector<int> findDuplicates(const vector<int> &nums)
{
    unordered_map<int, bool> myMap;
    vector<int> result;
    for (auto i : nums)
    {
        if (myMap[i])
        {
            result.push_back(i);
        }
        else
        {
            myMap[i] = true;
        }
    }
    return result;
}

void printDuplicates(vector<int> nums)
{
    vector<int> duplicates = findDuplicates(nums);
    for (int num : duplicates)
    {
        cout << num << " ";
    }
    cout << endl;
}

char firstNonRepeatingChar(const string &input_string)
{
    unordered_map<char, int> charCounts;

    for (char c : input_string)
    {
        charCounts[c]++;
    }

    for (char c : input_string)
    {
        if (charCounts[c] == 1)
        {
            return c;
        }
    }

    return '\0';
}

vector<vector<string>> groupAnagrams(const vector<string> &strings)
{
    // Map to store anagram groups with canonical forms as keys
    unordered_map<string, vector<string>> anagramGroups;

    for (const string &str : strings)
    {
        // Create the canonical form by sorting the string
        string canonical = str;
        sort(canonical.begin(), canonical.end());

        // Add the string to its anagram group
        anagramGroups[canonical].push_back(str);
    }

    // Vector to store the final result
    vector<vector<string>> result;

    // Iterate through anagram groups
    for (const auto &group : anagramGroups)
    {
        // Add the anagram group to the result
        result.push_back(group.second);
    }

    // Return the grouped anagrams
    return result;
}

int main()
{
    // vector<int> vec1{1, 3, 5};
    // vector<int> vec2{2, 4, 5};
    // cout << iteminCommon(vec1, vec2) << endl;
    vector<int> nums{1, 2, 3, 4, 4, 5, 5, 6, 7, 8};
    printDuplicates(nums);
    return 0;
}