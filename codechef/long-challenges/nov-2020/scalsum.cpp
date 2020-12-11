#include <stdio.h>
#include <vector>
#include <iostream>
#include <unordered_map>
#include <math.h>

using namespace std;

long long int path[300001];

class Node
{
public:
    int idx;
    long long int weight;
    long long int cost;
    Node* parent;
    vector<Node*> neighbors;

    void visit(Node* node_above)
    {
        this->parent = node_above;

        if (this->parent != NULL)
        {
            this->cost = (this->parent->cost + (this->weight * this->weight) & 0xFFFFFFFF) & 0xFFFFFFFF;
        }
        else
        {
            this->cost = (this->weight * this->weight) & 0xFFFFFFFF;
        }

        int i;
        for (i = 0; i < neighbors.size(); i++)
        {
            if (neighbors[i] != this->parent)
            {
                neighbors[i]->visit(this);
            }
        }
    }
};

int main()
{
    int n, q;
    int i, j;
    int left, right;
    long long int wt;
    int path_len;
    long long int pos;
    long long int pos2;
    long long int ans;
    long long int cur_cost;
    long long int temp;

    scanf("%d %d", &n, &q);

    Node* nodes = (Node*)malloc(sizeof(Node) * n);
    for (i = 0; i < n; i++)
    {
        scanf("%lld", &wt);
        nodes[i] = Node();
        nodes[i].idx = i;
        nodes[i].weight = wt;
    }

    for (i = 0; i < n - 1; i++)
    {
        scanf("%d %d", &left, &right);
        nodes[left - 1].neighbors.push_back(&nodes[right - 1]);
        nodes[right - 1].neighbors.push_back(&nodes[left - 1]);
    }

    nodes[0].visit(NULL);

    unordered_map<long long int, long long int> cost_cache;

    for (i = 0; i < q; i++)
    {
        scanf("%d %d", &left, &right);
        left--;
        right--;

        pos = ((long long int)left << 32) + right;
        pos2 = ((long long int) right << 32) + left;
        // printf("checking cost for %lld\n", pos);
        if (cost_cache.find(pos) != cost_cache.end())
        {
            // print answer and continue
            printf("%lld\n", cost_cache[pos]);
        }
        else if (cost_cache.find(pos2) != cost_cache.end())
        {
            // print answer and continue
            printf("%lld\n", cost_cache[pos2]);
        }
        else
        {
            path_len = 0;
            ans = 0;
            while (left != right)
            {
                // printf("entering with %d %d\n", left, right);
                pos = ((long long int) left << 32) + right;
                pos2 = ((long long int) right << 32) + left;
                if (cost_cache.find(pos) != cost_cache.end())
                {
                    cur_cost = cost_cache[pos];
                    ans = (ans + cur_cost) & 0xFFFFFFFF;
                    left = right = -1;
                    break;
                }

                if (cost_cache.find(pos2) != cost_cache.end())
                {
                    cur_cost = cost_cache[pos2];
                    ans = (ans + cur_cost) & 0xFFFFFFFF;
                    left = right = -1;
                    break;
                }

                path[path_len++] = pos;

                ans = (ans + (nodes[left].weight * nodes[right].weight) & 0xFFFFFFFF) & 0xFFFFFFFF;
                left = nodes[left].parent->idx;
                right = nodes[right].parent->idx;
            }

            if (left != -1)
            {
                // now add the cost
                cur_cost = nodes[left].cost;
                ans = (ans + cur_cost) & 0xFFFFFFFF;
            }

            // reverse the path
            for (j = 0; j < (path_len / 2); j++)
            {
                temp = path[j];
                path[j] = path[path_len - j - 1];
                path[path_len - j - 1] = temp;
            }

            // keep adding the cost
            j = 0;
            while (j < path_len)
            {
                right = path[j] & 0xFFFFFFFF;
                left = path[j] >> 32;
                cur_cost = (cur_cost + (nodes[left].weight * nodes[right].weight) & 0xFFFFFFFF) & 0xFFFFFFFF;
                cost_cache[path[j]] = cur_cost;
                // printf("adding cost for %lld with %lld\n", path[j], cur_cost);
                j++;
            }

            printf("%lld\n", ans);
        }
    }

    return 0;
}