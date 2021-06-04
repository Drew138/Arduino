#include <bits/stdc++.h>
#include <iostream>
typedef std::unordered_map<int, std::vector<int>> mapiv;
typedef std::vector<std::vector<int>> vvi;
typedef std::vector<int> vi;
typedef std::vector<bool> vb;

using namespace std;

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

void dfs2(int node, vb &seen, mapiv &adjacency, vi &components, int component)
{
    seen[node] = true;
    components[node] = component;
    for (int i = 0; i < adjacency[node].size(); ++i)
    {
        int tmp = adjacency[node][i];
        if (!seen[tmp])
            dfs2(tmp, seen, adjacency, components, component);
    }
};

void fill_transpose(mapiv &adjacency, mapiv &transpose)
{
    for (const auto &pair : adjacency)
        for (int i = 0; i < pair.second.size(); ++i)
            transpose[pair.second[i]].push_back(pair.first);
};

int main()
{
    int num, con, from, to, answer = 1;
    cin >> num >> con;
    vector<bool> seen(num, false);
    vi stack, components(num, -1);
    mapiv adjacency, transpose, scc_adjacency;
    while (con--)
    {
        cin >> from >> to;
        adjacency[from].push_back(to);
    }
    for (int i = 0; i < num; ++i)
    {
        if (!seen[i])
            dfs1(i, seen, adjacency, stack);
    }
    reverse(stack.begin(), stack.end());
    fill_transpose(adjacency, transpose);
    for (int i = 0; i < num; ++i)
        seen[i] = false;
    int component = 0;
    while (stack.size() > 0)
    {
        int node = stack.back();
        stack.pop_back();
        if (!seen[node])
        {
            dfs2(node, seen, adjacency, components, component);
        }
    }
    vi degree(component + 1, 0);
    for (const auto &pair : adjacency)
    {
        for (int i = 0; i < pair.second.size(); ++i)
            if (components[pair.first] != components[pair.second[i]])
                ++degree[components[pair.second[i]]];
    }
    for (auto &deg : degree)
        if (!deg)
            answer++;
    cout << answer << endl;
}