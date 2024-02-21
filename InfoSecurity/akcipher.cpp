#include <iostream>
using namespace std;

string textToBin(char text);
string asciiToBin(int num);
void reverseString(string &input);
string swapBinString(string &str);
string initialPermutation(string &str);
// string encryption(string strText, char key);
string encryption(char strText, char key);

int main()
{
    char plainText{};
    cout << "Enter One Character to Encrypt" << endl;
    cin >> plainText;

    char key{};
    cout << "Enter One Character for Key" << endl;
    cin >> key;

    // string ctext = textToBin(plainText);
    // cout << ctext << endl;
    // cout << swapBinString(ctext) << endl;
    // string swapedString = swapBinString(ctext);
    // cout << initialPermutation(swapedString) << endl;
    // string permutatedString = initialPermutation(swapedString);

    string cipherText = encryption(plainText, key);
    // cout << "Key Is " << textToBin(key) << endl;
    cout << "Cipher Text Is " << cipherText << endl;
}

//// Converts Text To Binary ////

string textToBin(char text)
{
    int ascii = text;
    string binString{""};
    binString = asciiToBin(ascii);
    return binString;
}

string asciiToBin(int num)
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

//// Reverse Strings ////

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

//// Swap String Such That Right Part of String Become Left and Left Part of String Become Right ////

string swapBinString(string &str)
{
    string swapString{""};
    string leftString{""};
    string rightString{""};

    for (int i{0}; i < 4; i += 1)
    {
        leftString += str[i];
    }
    for (int i{4}; i < 8; i += 1)
    {
        rightString += str[i];
    }

    reverseString(rightString);
    reverseString(leftString);
    swapString += rightString;
    swapString += leftString;

    return swapString;
}

// Permutate the String According to Given Algorithm

string initialPermutation(string &str)
{
    string ipString{""};
    string leftString{""};
    string rightString{""};

    for (int i{0}; i < 8; i += 1)
    {
        if (i % 2 == 0)
        {
            rightString += str[i];
        }
        else
        {
            leftString += str[i];
        }
    }

    reverseString(leftString);
    reverseString(rightString);

    ipString += leftString;
    ipString += rightString;

    return ipString;
}

// Encryption Method to Encrypt the Cipher

string encryption(char strText, char key)
{
    string binText = textToBin(strText);
    string swapedString = swapBinString(binText);
    string permutatedString = initialPermutation(swapedString);

    string cipherText{""};
    // Binary Key
    string strKey = textToBin(key);

    reverseString(strKey);
    for (int i{}; i < 8; i += 1)
    {
        int textNum = permutatedString[i] - '0';
        int keyNum = strKey[i] - '0';
        cipherText += ((textNum ^ keyNum) + '0');
    }
    reverseString(cipherText);
    return cipherText;
}