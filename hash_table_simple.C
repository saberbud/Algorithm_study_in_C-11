#include <iostream>
#include <fstream>
#include <unordered_map>
#include <string>
 
using namespace std;

 
int main()
{
    unordered_map<string, string> hashtable;
    hashtable.emplace("Xuefei.Yan", "saberbud");
 
    cout << "Nick name of Xuefei.Yan: " << hashtable["Xuefei.Yan"] << endl;
 
    return 0;
}
