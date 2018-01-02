#include <iostream>
#include <string>

using namespace std;

void xy_reverse(string &str)
{
    string temp;
    temp.resize(str.length());

    unsigned int id;
    for(unsigned int i=0;i<str.length();i++){
      id=str.length()-1-i;
      temp[id]=str[i];
    }

    // cout << "Reversed string: |" << temp << "|" << endl;
    str=temp;
}

int main()
{
    string a="abcd";
    cout << "Oringinal string: |" << a << "|" << endl;

    xy_reverse(a);

    cout << "Reversed string: |" << a << "|" << endl;

    return 0;
}
