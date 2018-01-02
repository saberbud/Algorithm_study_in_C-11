#include <iostream>
#include <string>

using namespace std;

bool is_rotation(const string &A, const string &B)
{
    unsigned int l=A.length();

    string C=A+A;

    if(l==B.length() && l>0){
      return C.find(B) != string::npos;
    }

    return false;
}

int main()
{
    string a="abcd";
    string b="cdab";

    cout << "Is |" << b << "| a rotation from |" << a << "| ?" << endl;

    cout << is_rotation(a,b) << endl;

    return 0;
}
