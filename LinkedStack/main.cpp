#include <fstream>
#include <iostream>

#include "Instagram.h"
#include "Stack.h"
#include "structProfile.cpp"

using namespace std;

int main(int argc, char* argv[])
{
    string presidents = argv[1];

    Instagram<Profile> instaPerson;
    Stack<Profile> stackStart;
    Profile* pres = NULL;

    string line;
    int lineLength;
    string presName;
    string presState;

    ifstream inStream;
    inStream.open(presidents, ios::in);

    stackStart.isEmpty();
    cout << endl;

    while (inStream.peek() != EOF)
    {
        getline(inStream, line);

        lineLength = line.length();
        presName = line.substr(0, (lineLength - 3));
        presState = line.substr((lineLength - 2), lineLength);

        pres = new Profile(presName, presState);

        stackStart.push(pres);

    }

    stackStart.print();
    cout << endl;

    stackStart.isEmpty();
    cout << endl;

    stackStart.peek();
    cout << endl;

    stackStart.pop();
    cout << endl;

    stackStart.peek();
    cout << endl;

    stackStart.makeEmpty();
    cout << endl;

    stackStart.isEmpty();
}