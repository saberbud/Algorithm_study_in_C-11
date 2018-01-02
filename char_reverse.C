#include <iostream>

using namespace std;

void xy_reverse(char *str)
{
    char *pstr=str;
    char temp;

    cout << "pstr: " << pstr << endl;

    while(*pstr){
      pstr++;

      // cout << "xy1" << endl;
      cout << "pstr: " << pstr << endl;
    }

    cout << "pstr: " << pstr << endl;

    pstr--;

    cout << "pstr: " << pstr << endl;

    while(str < pstr){
      cout << "str: " << str << " , pstr: " << pstr << endl;

      temp=*str;
      *str++=*pstr;
      *pstr--=temp;

      cout << "  temp: " << temp << " , str: " << str << " , pstr: " << pstr << endl;
    }
    cout << "str: " << str << " , pstr: " << pstr << endl;

}

int main()
{
    char a[10]="abcd";
    cout << "Original char: |" << a << "|" << endl;

    xy_reverse(a);
    cout << "Reversed char: |" << a << "|" << endl;

    return 0;
}
