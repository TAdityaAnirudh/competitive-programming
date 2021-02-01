#include <stdio.h>
#include <string.h>

// global variables
int sheets_fl[100001];
int blocks_fl[100001];
char input[100001];

int get_abs(int x)
{
    return x > 0 ? x : -x;
}

int get_attraction(int i, int j, int k)
{
    if (blocks_fl[i] != blocks_fl[j])
    {
        return 0;
    }

    return k - get_abs(i - j) + 1 - get_abs(sheets_fl[i] - sheets_fl[j]);
}

int main()
{
    int tests;
    int n;
    int i;
    int k;

    int blocks;
    int sheets;
    int magnet_pos;
    int iron_pos;
    int ans;

    scanf("%d", &tests);
    while (tests--)
    {
        scanf("%d %d", &n, &k);
        scanf("%s", input);

        sheets = 0;
        blocks = 0;
        for (i = 0; i < n; i++)
        {
            if (input[i] == ':')
            {
                sheets++;
            }
            else if (input[i] == 'X')
            {
                blocks++;
            }

            sheets_fl[i] = sheets;
            blocks_fl[i] = blocks;
        }

        magnet_pos = 0;
        iron_pos = 0;
        ans = 0;

        while (magnet_pos < n && input[magnet_pos] != 'M')
        {
            magnet_pos++;
        }

        while (iron_pos < n && input[iron_pos] != 'I')
        {
            iron_pos++;
        }

        while (magnet_pos < n && iron_pos < n)
        {
            // printf("%d %d\n", magnet_pos, iron_pos);

            // see if we can assign an iron for this magnet
            if (get_attraction(magnet_pos, iron_pos, k) > 0)
            {
                // assign it
                ans++;

                magnet_pos++;
                iron_pos++;

                // find next magnet
                while (magnet_pos < n && input[magnet_pos] != 'M')
                {
                    magnet_pos++;
                }

                // find next iron
                while (iron_pos < n && input[iron_pos] != 'I')
                {
                    iron_pos++;
                }
            }
            else
            {
                // we cannot assign
                // if magnet is behind, move magnet
                // else move iron
                if (magnet_pos < iron_pos)
                {
                    magnet_pos++;

                    while (magnet_pos < n && input[magnet_pos] != 'M')
                    {
                        magnet_pos++;
                    }
                }
                else
                {
                    iron_pos++;

                    while (iron_pos < n && input[iron_pos] != 'I')
                    {
                        iron_pos++;
                    }   
                }                
            }
        }

        printf("%d\n", ans);
    }

    return 0;
}
