#include <iostream>
// #include <string>
#include <string.h>

using namespace std;

void xy_reverse(char *str)
{
    // cout << "Total size: " << sizeof(str) << endl;
    // cout << "Actual length: " << strlen(str) << endl;

    // cout << str[0] << endl;

    const int n=strlen(str);
    // char temp[]=str;
    char *temp;
    temp=new char[n];

    // cout << "n= " << n << " , temp size= " << strlen(temp) << endl;
    // cout << "str: " << str << " , temp:" << temp << endl;


    int id;
    int nl=n/2;
    // cout << "n loop= " << nl << endl;

    for(int i=0;i<nl;i++){
      id=n-1-i;
      temp[i]=str[id];
      str[id]=str[i];
      str[i]=temp[i];
      // cout << "str: " << str << " , temp: " << temp << endl;
    }
    // cout << "temp length: " << strlen(temp) << endl;
    // cout << "str: " << str << " , temp: " << temp << endl;

    delete[] temp;
    // cout << "temp after delete: " << temp << endl;
    // cout << "temp length: " << strlen(temp) << endl;
    
}

int main()
{
    char a[10]="abc";
    cout << "Original char: " << a << endl;

    xy_reverse(a);

    cout << "Reversed char: " << a << endl;

    return 0;
}
