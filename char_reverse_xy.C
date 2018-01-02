#include <iostream>
// #include <string>
#include <string.h>

using namespace std;

void xy_reverse(char *str)
{
    const int n=strlen(str);
    char temp[1];

    int id;
    int nl=n/2;

    for(int i=0;i<nl;i++){
      id=n-1-i;
      temp[0]=str[id];
      str[id]=str[i];
      str[i]=temp[0];
    }
    
}

int main()
{
    char a[10]="abcde";
    cout << "Original char: " << a << endl;

    xy_reverse(a);

    cout << "Reversed char: " << a << endl;

    return 0;
}
