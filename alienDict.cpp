/*Given a sorted dictionary of an alien language having N words and k starting alphabets of standard dictionary the task is to complete the function which returns a string denoting the order of characters in the language.
Note: Many orders may be possible for a particular test case, thus you may return any valid order.
Examples:
Input:  Dict[ ] = { "baa", "abcd", "abca", "cab", "cad" }, k = 4
Output: Function returns "bdac"
Here order of characters is 'b', 'd', 'a', 'c'
Note that words are sorted and in the given language "baa"
comes before "abcd", therefore 'b' is before 'a' in output.
Similarly we can find other orders.

Input: Dict[] = { "caa", "aaa", "aab" }, k = 3
Output: Function returns "cab"*/

#include <bits/stdc++.h>
using namespace std;

class Graph
{
    int v;
    set<int> adj[26];

public:
    Graph(int V)
    {
        this->v = V;
        //adj= new vector <set <int>>[V];
    }

    void addEdge(int u, int v)
    {
        adj[u].insert(v);
    }
    void printEdges()
    {
        for (int i = 0; i < v; ++i)
        {
            cout << "\n"
                 << i << "..";
            for (auto j = adj[i].begin(); j != adj[i].end(); ++j)
                cout << *j << " ";
        }
    }

    void topologicalSortRecursive(int v, vector<bool> &visited, stack<int> &s)
    {
        visited[v] = true;
        for (auto i = adj[v].begin(); i != adj[v].end(); ++i)
        {
            if (!visited[*i])
                topologicalSortRecursive(*i, visited, s);
        }
        s.push(v);
    }

    string topologicalSort()
    {
        stack<int> s;
        vector<bool> visited(v, false);
        for (int i = 0; i < v; ++i)
        {
            if (!visited[i])
                topologicalSortRecursive(i, visited, s);
        }
        string str;
        while (!s.empty())
        {
            str.push_back(s.top() + 'a');
            // cout <<(char) (s.top()+'a');
            s.pop();
        }
        return str;
    }
};
string order(string dict[], int n, int k)
{
    Graph g(k);
    for (int i = 0; i < n - 1; ++i)
    {

        if (dict[i] != dict[j])
        {
            auto mis = mismatch(dict[i].begin(), dict[i].end(), dict[j].begin());
            if (mis.first != dict[i].end() && mis.second != dict[i + 1].end())
                g.addEdge(*mis.first - 'a', *mis.second - 'a');
            // cout << *mis.first - 'a' << " " << *mis.second - 'a' << "..\n";
        }
    }
    //g.printEdges();

    return g.topologicalSort();
}
int main()
{
    int t, n, k;
    cin >> t;
    while (t--)
    {
        cin >> n >> k;
        string dict[n];
        for (int i = 0; i < n; ++i)
            cin >> dict[i];
        cout << order(dict, n, k) << "\n";
    }
}
