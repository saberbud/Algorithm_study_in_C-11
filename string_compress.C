#include <iostream>
#include <string>

using namespace std;

void xy_compress(string &str)
{
    unsigned int n=str.length();
    unsigned int nsave=0;
    unsigned int nrp;
    char buff[50];
    string temp;
    char tc[1];

    if(n<1){
      cout << "Empty string." << endl;
      return;
    }

    string ntr;
    ntr.resize(0);
    nrp=1;
    for(unsigned int i=0;i<n;i++){
      if(i>0){
        if(str[i]==str[i-1] && i<(n-1)){
          nrp++;
          nsave++;
        }else{
          if(i==(n-1) && str[i]==str[i-1]){
            nrp++;
            nsave++;
          }

          tc[0]=str[i-1];
          temp=tc;
          temp.resize(1);
          ntr.append(temp);

          sprintf(buff,"%d",nrp);
          temp=buff;
          nsave=nsave-temp.length();

          ntr.append(temp);

          nrp=1;

        }
      }
      
    }


    if(nsave<1){
      return;
    }

    str=ntr;

}

int main()
{
    // string a="aaaabbbbbbbbbbccc";
    // string a="aabbcc";
    string a="aabbccc";
    cout << "Original string: " << a << " , length= " << a.length() << endl;

    xy_compress(a);

    cout << "Compressed string: " << a << " , length= " << a.length() << endl;

    return 0;
}
