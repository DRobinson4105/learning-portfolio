#include <iostream>

using namespace std;

int main()
{
    int t;
    cin >> t;

    for (int i=0; i < t; i++)
    {
        int money;
        cin >> money;

        //Double the money
        //and remove the last digit of the number
        int doubled = money * 2;
        int lastDigit = doubled % 10;
        doubled /= 10;

        int answer = money - doubled;

        cout << "Trade #"<< i+1 << ": "<<  answer << endl;
       

    }
}