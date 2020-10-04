#include <stdio.h>

int main()
{
	int tests;
	int cities[1001];
	int size, start, step, mine;
	int i;

	scanf("%d", &tests);

	while (tests--)
	{
		scanf("%d %d %d %d", &size, &step, &start, &mine);

		for (i = 0; i <= size; i++)
		{
			cities[i] = 0;
		}

		cities[start] = 1;

		for (i = 0; i < size; i++)
		{
			start = (start + step) % size;
			cities[start] = 1;
		}

		if (cities[mine])
		{
			printf("YES\n");
		}
		else
		{
			printf("NO\n");
		}
	}

	return 0;
}
