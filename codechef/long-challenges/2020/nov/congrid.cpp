#include <stdio.h>
#include <algorithm>
#include <vector>

using namespace std;

typedef struct _point
{
    int idx;
    int x;
    int y;
    int min;
    int max;
} point;

bool compare_points(point const& p1, point const& p2)
{
    if (p1.x != p2.x)
    {
        return p1.x < p2.x;
    }
    else
    {
        return p1.y < p2.y;
    }
}

int get_abs(int x)
{
    return x > 0 ? x : -x;
}

char grid[501][501];
point ends[250000];
point starts[200000];
point edges[200000];

int main()
{
    int n;
    int k;
    int i;
    int j;
    int l;
    int buffer;
    int x;
    int y;
    int min;
    int max;
    int ans = 0;
    int end_x;
    int end_y;
    int passes;
    int tried;
    int length;

    scanf("%d %d", &n, &k);

    for (i = 1; i <= 500; i++)
    {
        for (j = 1; j <= 500; j++)
        {
            grid[i][j] = 0;
        }
    }

    for (i = 0; i < k; i++)
    {
        scanf("%d %d %d %d", &x, &y, &min, &max);
        ends[i].idx = i + 1;
        ends[i].x = x;
        ends[i].y = y;
        ends[i].min = min;
        ends[i].max = max;
        grid[x][y] = 'C';
    }

    sort(ends, ends + k, &compare_points);

    // for (i = 0; i < k; i++)
    // {
    //     printf("%d %d %d %d\n", ends[i].x, ends[i].y, ends[i].min, ends[i].max);
    // }

    for (passes = 0; passes < 3; passes++)
    for (i = 0; i < k - 1; i++)
    {
        for (tried = 0, buffer = i + 500; tried < 26 && buffer > 0; buffer--)
        {
            if (i + buffer >= k)
            {
                continue;
            }

            // first check if we can build a path
            if (grid[ends[i].x][ends[i].y] == 'C')
            {
                if (grid[ends[i + buffer].x][ends[i + buffer].y] == 'C')
                {
                    length = get_abs(ends[i + buffer].x - ends[i].x) + get_abs(ends[i + buffer].y - ends[i].y) + 1;

                    if (length > ends[i].max || length < ends[i].min || length > ends[i + buffer].max || length < ends[i + buffer].min)
                    {
                        continue;
                    }
                }

                tried++;

                // see if you can build a path with next point
                end_x = ends[i + buffer].x;
                end_y = ends[i + buffer].y;

                x = ends[i].x;
                y = ends[i].y;

                // printf("Entered for point #%d. End is %d %d\n", i, end_x, end_y);
                // set grid to zero first
                grid[x][y] = 0;

                length = 1;

                while (x != end_x || y != end_y)
                {
                    if (grid[x][y] != 0)
                    {
                        // printf("Grid isn't zero at %d %d\n", x, y);
                        break;
                    }
                    else
                    {
                        length++;

                        // let's see which direction we should pick
                        if (x < end_x)
                        {
                            x++;
                        }
                        else if (x > end_x)
                        {
                            x--;
                        }
                        else
                        {
                            if (y < end_y)
                            {
                                y++;
                            }
                            else if (y > end_y)
                            {
                                y--;
                            }
                        }
                    }
                }

                // printf("Complete with %d %d and length is %d\n", x, y, length);

                if (grid[x][y] == 'C'
                    && x == end_x 
                    && y == end_y 
                    && length >= ends[i].min 
                    && length >= ends[i + buffer].min 
                    && length <= ends[i].max 
                    && length <= ends[i + buffer].max)
                {
                    // now pave the path
                    end_x = ends[i + buffer].x;
                    end_y = ends[i + buffer].y;

                    x = ends[i].x;
                    y = ends[i].y;

                    starts[ans].x = x;
                    starts[ans].y = y;

                    edges[ans].x = ends[i].idx;
                    edges[ans].y = ends[i + buffer].idx;

                    ans++;

                    while (true)
                    {
                        if (x == end_x && y == end_y)
                        {
                            grid[x][y] = 'E';
                            break;
                        }
                        
                        // let's see which direction we should pick
                        if (x < end_x)
                        {
                            grid[x][y] = 'D';
                            x++;
                        }
                        else if (x > end_x)
                        {
                            grid[x][y] = 'U';
                            x--;
                        }
                        else
                        {
                            if (y < end_y)
                            {
                                grid[x][y] = 'R';
                                y++;
                            }
                            else if (y > end_y)
                            {
                                grid[x][y] = 'L';
                                y--;
                            }
                        }
                    }
                }
                else
                {
                    grid[ends[i].x][ends[i].y] = 'C';
                }
                

                // for (j = 1; j <= n; j++)
                // {
                //     for (l = 1; l <= n; l++)
                //     {
                //         printf("%c", grid[j][l]);
                //     }
                //     printf("\n");
                // }
            }
            
        }
    }

    printf("%d\n", ans);

    for (i = 0; i < ans; i++)
    {
        x = starts[i].x;
        y = starts[i].y;

        printf("%d %d ", edges[i].x, edges[i].y);

        while (grid[x][y] != 'E')
        {
            printf("%c", grid[x][y]);
            switch (grid[x][y])
            {
                case 'D':
                    x++;
                    break;
                case 'U':
                    x--;
                    break;
                case 'L':
                    y--;
                    break;
                case 'R':
                    y++;
                    break;
            }
        }

        printf("\n");
    }

    return 0;
}
