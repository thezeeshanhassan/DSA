#include<iostream>
using namespace std;

int decToBin(int);
int encryption(int ,int);
int binToDec(int);

int main()
{
    int plainText{};
    cout<<"Enter Plain Text in Decimal"<<endl;
    cin>>plainText;
    cout<<decToBin(plainText)<<endl;

    int key{};
    cout<<"Enter a Key"<<endl;
    cin>>key;
    cout<<decToBin(key)<<endl;

    // Encryption
    cout<<encryption(plainText,key);

    return 0;
}

// Decimal to Binary Converter

int decToBin(int decNum)
{
    int binNum{};
    int base{1};
    while(decNum > 0)
    {
        int lastDigit = decNum % 2;
        binNum += lastDigit * base;
        base *= 10;
        decNum /= 2;
    }
    return binNum;
}

// Binary To Decimal Converter

int binToDec(int binNum)
{
    int decNum{};
    int base{1};

    while(binNum > 0)
    {
        int lastDigit = binNum % 10;
        decNum += lastDigit * base;
        base *= 2;
        binNum /= 10;
    }
}

// Encryption Method

int encryption(int text,int key)
{
    int binText = decToBin(text);
    int binKey = decToBin(key);
    int cipherText = text ^ key;
    return cipherText;
}