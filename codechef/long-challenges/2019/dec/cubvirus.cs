using System;
using System.Collections.Generic;
using System.Linq;

namespace CodeChefProblems
{
    class Program
    {
        static void Main(string[] args)
        {
            ThreeDimVirus.Run();
        }
    }

    class ThreeDimVirus
    {
        public static void Run()
        {
            int N = Int32.Parse(Console.ReadLine());
            bool[][][] infected = new bool[N][][];

            for (int i = 0; i < N; i++)
            {
                infected[i] = new bool[N][];
                for (int j = 0; j < N; j++)
                {
                    infected[i][j] = new bool[N];
                }
            }

            for (int k = 0; k < N; k++)
            {
                for (int j = 0; j < N; j++)
                {
                    string input = Console.ReadLine();
                    for (int i = 0; i < N; i++)
                    {
                        infected[i][j][k] = input[i] == '1';
                    }
                }
            }

            List<int> xperm = new List<int>();
            List<int> yperm = new List<int>();
            List<int> zperm = new List<int>();

            for (int i = 0; i < N; i++)
            {
                xperm.Add(i);
                yperm.Add(i);
                zperm.Add(i);
            }

            /*
             * Idea:
             * Pick an axis. Compute value for other two axes.
             * Create an array and sort for this axis.
             * Come up with new permutation.
             * Use that as new indices and optimize for another axis.
             * Do this iteratively as long as we get better.
             */

            List<int> xCost = new List<int>();
            List<int> yCost = new List<int>();
            List<int> zCost = new List<int>();
            for (int i = 0; i < N; i++)
            {
                xCost.Add(GetCost(i, N, infected, null, null, null, true, false));
            }

            // sort based on cost
            // sort in ascending order
            var sortedX = xCost.Select((x, i) => new KeyValuePair<int, int>(x, i)).OrderBy(x => x.Key).ToList();

            var newXIndices = sortedX.Select(x => x.Value).ToList();

            for (int i = 0; i < N; i++)
            {
                yCost.Add(GetCost(i, N, infected, newXIndices, null, null, false, true));
            }

            var sortedY = yCost.Select((y, i) => new KeyValuePair<int, int>(y, i)).OrderBy(y => y.Key).ToList();

            var newYIndices = sortedY.Select(x => x.Value).ToList();

            for (int i = 0; i < N; i++)
            {
                zCost.Add(GetCost(i, N, infected, newXIndices, newYIndices, null, false, false));
            }

            var sortedZ = zCost.Select((z, i) => new KeyValuePair<int, int>(z, i)).OrderBy(z => z.Key).ToList();

            var newZIndices = sortedZ.Select(x => x.Value).ToList();

            xCost = new List<int>();
            for (int i = 0; i < N; i++)
            {
                xCost.Add(GetCost(i, N, infected, null, null, newZIndices, true, false));
            }

            sortedX = xCost.Select((x, i) => new KeyValuePair<int, int>(x, i)).OrderBy(x => x.Key).ToList();

            Console.WriteLine(string.Join(" ", sortedX.Select(x => x.Value + 1)));
            Console.WriteLine(string.Join(" ", sortedY.Select(x => x.Value + 1)));
            Console.WriteLine(string.Join(" ", sortedZ.Select(x => x.Value + 1)));
        }

        static int GetCost(
            int idx,
            int N,
            bool[][][] arena,
            List<int> newXIndices,
            List<int> newYIndices,
            List<int> newZIndices,
            bool isX,
            bool isY)
        {
            int ans = 0;

            for (int i = 0; i < N; i++)
            {
                for (int j = 0; j < N; j++)
                {
                    if (isX && !isY)
                    {
                        if (newYIndices != null && newZIndices != null)
                        {
                            if (arena[idx][newYIndices[i]][newZIndices[j]] && (ans < (N - i) * (N - j)))
                            {
                                ans = (N - i) * (N - j);
                            }
                        }
                        else
                        {
                            if (arena[idx][i][j] && (ans < (N - i) * (N - j)))
                            {
                                ans = (N - i) * (N - j);
                            }
                        }
                    }
                    else if (isY)
                    {
                        if (newXIndices == null)
                        {
                            if (arena[i][idx][j] && (ans < (N - i) * (N - j)))
                            {
                                ans = (N - i) * (N - j);
                            }
                        }
                        else
                        {
                            if (arena[newXIndices[i]][idx][j] && (ans < (N - i) * (N - j)))
                            {
                                ans = (N - i) * (N - j);
                            }
                        }
                    }
                    else
                    {
                        if (newXIndices != null && newYIndices != null)
                        {
                            if (arena[newXIndices[i]][newYIndices[j]][idx] && (ans < (N - i) * (N - j)))
                            {
                                ans = (N - i) * (N - j);
                            }
                        }
                        else if (arena[i][j][idx] && (ans < (N - i) * (N - j)))
                        {
                            ans = (N - i) * (N - j);
                        }
                    }
                }
            }

            return ans;
        }
    }
}
