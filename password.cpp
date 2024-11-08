#include <iostream>
#include <string>
#include <cstdlib>
#include <time.h>
using namespace std;
int main()
{
    string su = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    string sl = "abcdefghijklmnopqrstuvwxys";
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
    for (int i = 0; (i < len) && (pass.length() < len); i++)
    {
        int j = 0;
        // cout << rand() % 26 << " | ";
        if (up && lo && n && c)
        {
            j = rand() % su.length();
            pass.push_back(su[j]);
            j = rand() % sl.length();
            pass.push_back(sl[j]);
            j = rand() % nums.length();
            pass.push_back(nums[j]);
            j = rand() % characters.length();
            pass.push_back(characters[j]);
        }
        else if (up && lo && n)
        {
            j = rand() % su.length();
            pass.push_back(su[j]);
            j = rand() % sl.length();
            pass.push_back(sl[j]);
            j = rand() % nums.length();
            pass.push_back(nums[j]);
        }
        else if (up && lo)
        {
            j = rand() % su.length();
            pass.push_back(su[j]);
            j = rand() % sl.length();
            pass.push_back(sl[j]);
        }
        else if (up)
        {
            j = rand() % su.length();
            pass.push_back(su[j]);
            // j = rand() % sl.length();
            // pass.push_back(sl[j]);
        }
        else if (lo)
        {
            j = rand() % su.length();
            // pass.push_back(su[j]);
            j = rand() % sl.length();
            pass.push_back(sl[j]);
        }
        else if (n)
        {

            j = rand() % nums.length();
            pass.push_back(nums[j]);
        }
        else if (c)
        {
            j = rand() % characters.length();
            pass.push_back(characters[j]);
        }
        else if (n && c)
        {
            j = rand() % nums.length();
            pass.push_back(nums[j]);
            j = rand() % characters.length();
            pass.push_back(characters[j]);
        }
        else if (lo && c)
        {
            j = rand() % su.length();
            j = rand() % sl.length();
            pass.push_back(sl[j]);
            j = rand() % characters.length();
            pass.push_back(characters[j]);
        }
        else if (up && c)
        {
            j = rand() % su.length();
            pass.push_back(su[j]);
            j = rand() % characters.length();
            pass.push_back(characters[j]);
        }
        else if (n && lo)
        {
            j = rand() % su.length();
            j = rand() % sl.length();
            pass.push_back(sl[j]);
            j = rand() % nums.length();
            pass.push_back(nums[j]);
        }
        else if (n && up)
        {
            j = rand() % su.length();
            pass.push_back(su[j]);
            j = rand() % nums.length();
            pass.push_back(nums[j]);
        }
        else
        {
            cout << "as you have not selected what you want as input , we are assuming you need all , uppercase, lowercase, numbers and characters\n";
            j = rand() % su.length();
            pass.push_back(su[j]);
            j = rand() % sl.length();
            pass.push_back(sl[j]);
            j = rand() % nums.length();
            pass.push_back(nums[j]);
            j = rand() % characters.length();
            pass.push_back(characters[j]);
        }
    }

    cout << pass;
    return 0;
}