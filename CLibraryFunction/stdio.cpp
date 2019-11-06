#include <iostream>
#include <stdio.h>

using namespace std;

int main()
{
    char buffer[50];
    float a = 5.92837f;
    int n;
    n = sprintf(buffer, "a = %.2f\n", a);
    cout << "n = " << n << "\tbuffer=" << buffer << endl;
    return 0;
}
