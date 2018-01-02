#include <iostream>
#include <string>

using namespace std;

void xy_replace(string &str)
{
    unsigned int n=str.length();
    unsigned int nr=n;
    for(unsigned int i=0;i<n;i++){
      if(str[i]==' ')nr=nr+2;
    }

    string temp=" ";
    temp.resize(nr);
    // cout << "nr= " << nr << " temp size= " << temp.length() << endl;

    unsigned int id=0;
    for(unsigned int i=0;i<n;i++){
      if(str[i]==' '){
        temp[id]='%';id++;
        temp[id]='2';id++;
        temp[id]='0';
      }else{
        temp[id]=str[i];
      }
      id++;
    }

    // cout << "temp: " << temp << endl;
    str=temp;
}

int main()
{
    string a="abc d efg";
    cout << "Original a: " << a << endl;

    xy_replace(a);
    cout << "Replaced a: " << a << endl;


    return 0;
}
