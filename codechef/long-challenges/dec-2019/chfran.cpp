#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

struct range_node
{
    int val;
    bool is_start;
};

struct range_node_less_than
{
    inline bool operator() (const range_node& node1, const range_node& node2)
    {
        if (node1.val != node2.val)
        {
            return node1.val < node2.val;
        }
        else
        {
            if (node1.is_start)
            {
                return true;
            }
            return false;
        }
    }
};

range_node nodes[200001];

int main()
{
    int tests;
    int i;
    scanf("%d", &tests);
    long long start;
    long long end;
    long long ans;
    long long n;
    long long cur_active, remaining, covered;

    while (tests--)
    {
        scanf("%lld", &n);

        for (i = 0; i < n; i++)
        {
            scanf("%lld %lld", &start, &end);
            nodes[i * 2].val = start;
            nodes[i * 2].is_start = true;
            nodes[i * 2 + 1].val = end;
            nodes[i * 2 + 1].is_start = false;
        }

        sort(nodes, (nodes + 2 * n), range_node_less_than());

        ans = 100000000;
        cur_active = 1;
        remaining = n - 1;
        covered = 0;
        for (i = 1; i < 2 * n; i++)
        {
            if (nodes[i].val != nodes[i - 1].val)
            {
                if (covered > 0 && remaining > 0)
                {
                    if (cur_active < ans)
                    {
                        ans = cur_active;
                    }
                }
            }

            if (ans == 0)
            {
                break;
            }

            if (nodes[i].is_start)
            {
                remaining--;
                cur_active++;
            }
            else
            {
                cur_active--;
                covered++;
            }
        }

        if (ans == 100000000)
        {
            ans = -1;
        }

        printf("%lld\n", ans);
    }

    return 0;
}