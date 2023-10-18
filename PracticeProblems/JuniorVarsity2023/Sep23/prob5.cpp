#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    vector<string> words(6);
    words[0] = "thousand";
    words[1] = "million";
    words[2] = "billion";
    words[3] = "trillion";
    words[4] = "quadrillion";
    words[5] = "quintillion";

    vector<string> ones(9);
    ones[0] = "one";
    ones[1] = "two";
    ones[2] = "three";
    ones[3] = "four";
    ones[4] = "five";
    ones[5] = "six";
    ones[6] = "seven";
    ones[7] = "eight";
    ones[8] = "nine";

    vector<string> tens(8);
    tens[0] = "ten";
    tens[1] = "twenty";
    tens[2] = "thirty";
    tens[3] = "forty";
    tens[4] = "fifty";
    tens[5] = "sixty";
    tens[6] = "seventy";
    tens[7] = "eighty";
    tens[8] = "ninety";

    vector<string> teens(9);
    teens[0] = "eleven";
    teens[1] = "twelve";
    teens[2] = "thirteen";
    teens[3] = "fourteen";
    teens[4] = "fifteen";
    teens[5] = "sixteen";
    teens[6] = "seventeen";
    teens[7] = "eighteen";
    teens[8] = "nineteen";
    
    int t;
    cin >> t;
    for (int idk = 0; idk < t; idk++) {
        long long int n;
        cin >> n;
        int count = -1;

        string result = "";
        while (n > 0) {
            vector<string> tmp;
            if (n % 1000 == 0) {
                n /= 1000;
                count++;
                continue;
            }
            if (count != -1) {
                tmp.push_back(words[count]);
            }
            if (n > 10 && n < 20) {
                tmp.push_back(teens[(n % 10) - 1]);
                n /= 100;
            } else {
                if (n % 10 > 0) {
                    tmp.push_back(ones[(n % 10) - 1]);
                }
                
                n /= 10;

                if (n % 10 > 0) {
                    tmp.push_back(tens[(n % 10) - 1]);
                }
                n /= 10;
            }

            if (n % 10 > 0) {
                tmp.push_back("hundred");
                tmp.push_back(ones[(n % 10) - 1]);
            }

            n /= 10;
            count++;

            for (int i = 0; i < tmp.size(); i++) {
                result = tmp[i] + " " + result;
            }
        }

        cout << result << endl;
    }
    return 0;

}