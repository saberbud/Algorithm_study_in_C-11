#include <iostream>
#include <fstream>
#include <string>

using namespace std;

bool xy_is_unique(const string &str)
{
    if(str.length()>256){
      return false;
    }

    bool ascii_set[256]={ false };

    int value;
    for(unsigned int i=0;i<str.length();i++){
      value=str[i];
      if(ascii_set[value]){
        return false;
      }

      ascii_set[value]=true;
    }


    return true;
}

int main()
{
    string a="aab";
    bool uni=xy_is_unique(a);

    cout << "string |" << a << "| has unique char: " << uni << endl;

    a="abc";
    uni=xy_is_unique(a);
    cout << "string |" << a << "| has unique char: " << uni << endl;

    return 0;
}
