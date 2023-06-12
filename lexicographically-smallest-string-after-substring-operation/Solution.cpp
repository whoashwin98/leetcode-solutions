class Solution
{
public:
    string smallestString(string s)
    {
        int n = s.length();
        int start_index = 0;

        while (start_index < n && s[start_index] == 'a')
            start_index++;

        // all a's
        if (start_index == n)
        {
            s[n - 1] = 'z';
            return s;
        }

        for (int i = start_index; i < n; i++)
        {
            if (s[i] == 'a')
                break;
            s[i] = s[i] - 1;
        }

        return s;
    }
};