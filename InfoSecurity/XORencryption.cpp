#include <iostream>
#include <string>
#include <cmath>
using namespace std;

// Prototypes of Each Function

string decToBin(int);
void reverseString(string &input);
string textToBin(string);
string encryption(string, string);
// int binToDec(string);
int binToDec(string);

int main()
{
    // string plainText{};
    // cout<<"Enter Plain Text"<<endl;
    // cin>>plainText;

    // string key{};
    // cout<<"Enter a Key"<<endl;
    // cin>>key;

    // cout<<textToBin(plainText)<<endl;
    // cout<<textToBin(key)<<endl;

    // cout<<encryption(plainText,key);

    string num{""};
    cout << "Enter a binary String" << endl;
    cin >> num;

    cout << binToDec(num);

    return 0;
}

// Converts Each Digit to Binary Code

string decToBin(int num)
{
    string binString{""};
    while (num > 0)
    {
        binString += to_string(num % 2);
        num /= 2;
    }
    while (binString.length() < 8)
    {
        binString += '0';
    }
    reverseString(binString);
    return binString;
}

void reverseString(string &input)
{
    int left = 0;
    int right = input.length() - 1;

    while (left < right)
    {
        // Swap characters at the left and right positions
        swap(input[left], input[right]);

        left += 1;
        right -= 1;
    }
}

// Binary String Generator

string textToBin(string plainText)
{
    string binString{""};
    for (int i{}; i < plainText.length(); i += 1)
    {
        int asci = plainText[i];
        binString += decToBin(asci);
    }
    return binString;
}

// Encryption Method Which Encrypts the Text of any Type of String

string encryption(string strPT, string strKey)
{
    string plainText = textToBin(strPT);
    string key = textToBin(strKey);

    int sizePT = plainText.length();
    int sizeK = key.length();

    string cipher{""};
    int j{};
    for (int i{}; i < sizePT; i += 1)
    {
        cipher += to_string(int(plainText[i]) ^ int(key[j]));
        j += 1;
        j %= sizeK;
    }
    return cipher;
}

// Binary to Decimal

int binToDec(string binString)
{
    // string decString{""};
    int decNum;
    int size = binString.length();
    int base{1};

    for (int i{}; i < binString.length(); i += 1)
    {
        int binNum = int(binString[i]);
        decNum += binNum * base;
        base *= 2;
        // power += 1;
    }
    return decNum;
}

