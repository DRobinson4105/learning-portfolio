#include <iostream>
#include <vector>

using namespace std;

#define GARBAGE -100001

int main()
{
    int a;

    cin >> a;

    for(int auction = 0; auction < a; auction++)
    {
        int n, x;
        int sum = 0;
        cin >> n >> x;

        vector<int> t;
        vector<int> m;
        vector<int> diff;

        for(int i = 0; i < n; i++)
        {
            int num;
            cin >> num;
            t.push_back(num);
        }

        for(int i = 0; i < n; i++)
        {
            int num;
            cin >> num;
            m.push_back(num);
            diff.push_back(m[i] - t[i]);
        }

        for(int prio = 0; prio < x; prio++)
        {
            int highestI = -1;
            for(int i = 0; i < n; i++)
            {
                if(highestI == -1 || diff[i] > diff[highestI])
                    highestI = i;
            }

            sum += m[highestI];
            diff[highestI] = GARBAGE;
        }

        for(int i = 0; i < n; i++)
        {
            if(diff[i] != GARBAGE) sum += t[i];
        }

        cout << sum << "\n";
    }
    return 0;
}