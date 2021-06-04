#include <bits/stdc++.h>
#include <iostream>
typedef std::unordered_map<int, std::vector<int>> mapiv;
typedef std::vector<std::vector<int>> vvi;
typedef std::vector<int> vi;
typedef std::vector<bool> vb;

using namespace std;

// http://www.degeneratestate.org/posts/2017/May/05/turing-patterns/

void dfs1(int node, vb &seen, mapiv &adjacency, vi &stack)
{
    seen[node] = true;
    for (int i = 0; i < adjacency[node].size(); ++i)
    {
        int tmp = adjacency[node][i];
        if (!seen[tmp])
            dfs1(tmp, seen, adjacency, stack);
    }
    stack.push_back(node);
};

void dfs2(int node, vb &seen, mapiv &adjacency, vvi &components)
{
    seen[node] = true;
    components[components.size() - 1].push_back(node);
    for (int i = 0; i < adjacency[node].size(); ++i)
    {
        int tmp = adjacency[node][i];
        if (!seen[tmp])
            dfs2(tmp, seen, adjacency, components);
    }
};

void fill_transpose(mapiv &adjacency, mapiv &transpose)
{
    for (const auto &pair : adjacency)
        for (int i = 0; i < pair.second.size(); ++i)
            transpose[pair.second[i]].push_back(pair.first);
};

vvi kosaraju(int num, mapiv &adjacency, mapiv &transpose, vb &seen, vi &stack)
{
    for (int i = 0; i < num; ++i)
    {
        if (!seen[i])
            dfs1(i, seen, adjacency, stack);
    }
    reverse(stack.begin(), stack.end());
    fill_transpose(adjacency, transpose);
    for (int i = 0; i < num; ++i)
        seen[i] = false;
    vvi components;
    while (stack.size() > 0)
    {
        int node = stack.back();
        stack.pop_back();
        if (!seen[node])
        {
            vi tmp;
            components.push_back(tmp);
            dfs2(node, seen, adjacency, components);
        }
    }
    return components;
};

int main()
{
    int num, con, from, to;
    cin >> num >> con;
    vector<bool> seen(num, false);
    vi stack;
    mapiv adjacency, transpose;
    while (con--)
    {
        cin >> from >> to;
        adjacency[from].push_back(to);
    }
    vvi components = kosaraju(num, adjacency, transpose, seen, stack);
    for (int i = 0; i < components.size(); ++i)
    {
        cout << "Component #" << i << endl;
        for (int node : components[i])
            cout << node << " ";
        cout << endl;
    }
}