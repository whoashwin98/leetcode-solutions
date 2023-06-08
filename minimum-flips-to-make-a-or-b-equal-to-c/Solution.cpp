class Solution
{
public:
    int minFlips(int a, int b, int c)
    {
        int d = a | b;
        int ans = 0;
        int it = max(c, d);

        while (it != 0)
        {
            int presentBit = d & 1;
            int reqdBit = c & 1;

            if (presentBit != reqdBit)
            {
                int aBit = a & 1;
                int bBit = b & 1;
                if (reqdBit == 1)
                {
                    ans++;
                }

                else if (reqdBit == 0)
                {
                    if (aBit != bBit)
                        ans++;
                    else if (aBit == 1 && bBit == 1)
                        ans += 2;
                }
            }

            a = a >> 1;
            b = b >> 1;
            c = c >> 1;
            d = d >> 1;
            it = it >> 1;
        }

        return ans;
    }
};