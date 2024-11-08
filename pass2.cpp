#include <iostream>
#include <string>
#include <cstdlib>
#include <time.h>
using namespace std;
int main()
{
    string su = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    string sl = "abcdefghijklmnopqrstuvwxyz";
    string characters = "!@#$%^&*()_+-=[{;:'\"|,.<>/?}]";
    string nums = "0123456789";

    cout << su.length() << endl;
    cout << sl.length() << endl;
    cout << nums.length() << endl;
    cout << characters.length() << endl;

    cout << "What do you want in your password please ans the below questions in 1(yes) or 0(no)\n";
    bool up = false;
    bool lo = false;
    bool n = false;
    bool c = false;
    cout << "Do you need uppercharactes\n";
    cin >> up;

    cout << "Do you need lowercharacters\n";
    cin >> lo;
    cout << "Do you need numbers\n";
    cin >> n;
    cout << "Do you need characters\n";
    cin >> c;

    int len;
    cout << "Enter the length of the password\n";
    cin >> len;
    srand(time(0));
    string pass;
    string ans;
    if (up)
        ans += su;
    if (lo)
        ans += sl;
    if (c)
        ans += characters;
    if (n)
        ans += nums;

    for (int i = 0; (i < len) && (pass.length() < len); i++)
    {
        int j = rand() % ans.length();
        pass.push_back(ans[j]);
    }

    cout << pass;
    return 0;
}