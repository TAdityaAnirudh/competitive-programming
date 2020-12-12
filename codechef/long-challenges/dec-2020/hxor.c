#include <stdio.h>

unsigned int input[100001];
int bit_count[32];
int pending_op[32];

int main()
{
    int tests;
    int n;
    int x;
    int i;
    int j;
    unsigned int mask;
    int removable_bits;
    int odd_counts;
    int pending_op_count;

    scanf("%d", &tests);
    while (tests--)
    {
        // initialize bit counts
        for (i = 0; i < 32; i++)
        {
            bit_count[i] = 0;
            pending_op[i] = 0;
        }

        scanf("%d %d", &n, &x);
        for (i = 0; i < n; i++)
        {
            scanf("%u", &input[i]);

            // update bit count
            mask = 1;
            for (j = 0; j < 32; j++)
            {
                if (input[i] & mask)
                {
                    bit_count[j]++;
                }

                mask <<= 1;
            }
        }

        // total count of even no. of bits
        removable_bits = 0;
        odd_counts = 0;
        for (j = 0; j < 32; j++)
        {
            removable_bits += bit_count[j];
            if ((bit_count[j] & 1) != 0)
            {
                if ((input[n - 1] & (1 << j)) == 0)
                {
                    // one bit can be moved to the ending
                    // add it to operations
                    odd_counts++;
                }

                removable_bits--;
            }
        }

        // make it half to get no. of steps required
        removable_bits >>= 1;
        removable_bits += odd_counts;

        // can we do all operations?
        if (removable_bits <= x)
        {
            if (removable_bits == 0 && x == 1)
            {
                // there are no operations we can perform
                // means all numbers except last one are zeroes
                // this means we should do some undesirable operation
                // let's flip last bit of nth and n-1th numbers
                input[n - 1] ^= 1;
                input[n - 2] ^= 1;

                for (i = 0; i < n; i++)
                {
                    printf("%u ", input[i]);
                }

                printf("\n");
                continue;
            }

            // we can always adjust if there are enough operations or more
            for (i = 0; i < n - 1; i++)
            {
                input[i] = 0;
            }

            // compute last number to be printed
            input[n - 1] = 0;
            mask = 1;
            for (i = 0; i < 32; i++)
            {
                if ((bit_count[i] & 1) != 0)
                {
                    input[n - 1] |= mask;
                }

                mask <<= 1;
            }

            if (n == 2 && (x - removable_bits) %2 != 0)
            {
                input[n - 1] ^= 1;
                input[n - 2] ^= 1;
            }

            for (i = 0; i < n; i++)
            {
                printf("%u ", input[i]);
            }

            printf("\n");
        }
        else
        {
            // we cannot do everything
            // go step by step
            pending_op_count = 0;
            i = 0;

            while (1 == 1)
            {
                if (i == n)
                {
                    break;
                }

                // no more resources to work with
                if (x == 0 && pending_op_count == 0)
                {
                    break;
                }

                // find MSB of input[i]
                mask = (unsigned int)(1 << 31);
                j = 31;
                while (j >= 0)
                {
                    // a bit is found
                    if ((input[i] & mask) != 0)
                    {
                        if (pending_op[j] > 0)
                        {
                            // use pending operation
                            input[i] ^= mask;
                            pending_op[j]--;
                            pending_op_count--;
                        }
                        else if (x > 0 && (i < n - 1))
                        {
                            // is this the last bit remaining in this sequence?
                            if (bit_count[j] == 1)
                            {
                                // move this to the last number
                                input[i] ^= mask;
                                input[n - 1] ^= mask;
                            }
                            else
                            {
                                // update number and add to pending ops
                                input[i] ^= mask;
                                pending_op[j]++;
                                bit_count[j] -= 2;
                                pending_op_count++;
                            }

                            // reduce operation count
                            x--;
                        }
                    }

                    j--;
                    mask >>= 1;
                }

                i++;
            }

            for (i = 0; i < n; i++)
            {
                printf("%u ", input[i]);
            }

            printf("\n");
        }
    }

    return 0;
}
