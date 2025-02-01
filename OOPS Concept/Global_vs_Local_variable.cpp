#include <iostream>
using namespace std;

int x = 2; // Global variable
void fun()
{
    int x= 60;
    cout << x << endl;
    ::x = 40;
    cout << ::x << endl;
}
int main()
{
    ::x = 4;    // global x
    int x = 20; // local to main() fn.
    cout << x << endl;
    cout << ::x << endl; // accessing Global variable with ::

    {
        int x= 50;
        cout << x << endl;
        cout << ::x << endl;
    }
    fun();

    return 0;
}