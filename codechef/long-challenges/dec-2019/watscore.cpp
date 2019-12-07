#include <stdio.h>

int main()
{
	int tests;
	int n;
	int scores[9];

	scanf("%d", &tests);

	while (tests--)
	{
		scanf("%d", &n);

		int idx, score;
		int i;

		for (i = 1; i <= 8; i++)
		{
			scores[i] = 0;
		}

		for (i = 0; i < n; i++)
		{
			scanf("%d %d", &idx, &score);
			if (idx >= 9)
			{
				continue;
			}

			if (scores[idx] < score)
			{
				scores[idx] = score;
			}
		}

		int ans = 0;
		for (i = 1; i <= 8; i++)
		{
			ans += scores[i];
		}

		printf("%d\n", ans);
	}

	return 0;
}