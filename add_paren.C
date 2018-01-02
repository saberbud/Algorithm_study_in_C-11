#include <iostream>
#include <vector>
#include <string>
#include <map>
using namespace std;

typedef map<int, int> mi;

mi Map_m;
mi Map_p;

string add_string_paren(string a, char op, string b)
{
  string str;
  string ops=" ";
  ops[0]=op;

  str="("+a+")"+ops+"("+b+")";

  return str;
}

int placeParen(string exp, int result, int start, int end, mi &Map, int level, string &ostr, int mkey, int pind){
	// level++;
        int slen=end-start+1;
        ostr=exp.substr(start,slen);
	// cout << "level= " << level << " , string: " << exp.substr(start,slen) << endl;
        // cout << "level= " << level << " , string: " << ostr << endl;

        string str1, str2, str3;

	// int key = result*200 + start*7 + end*3;
        // int key = result*200 + start*10 + end*1;
        int key = level*1000+result*200 + start*10 + end*1;

	// cout << "level= " << level << " , string: " << ostr << " , key= " << key << " | start end= " << start << " " << end << " | map size= " << Map.size() << endl;

	if (Map.count(key))
		return Map[key];
	if (start == end) {
		if (exp[start] == '1' && result == 1)
			return 1;
		else if (exp[start] == '0' && result == 0)
			return 1;
		return 0;
	}
	int c=0;
        // int c_a=0;

	Map_m[key]=mkey;
        Map_p[key]=pind;

	int tempi;
	if (result) {
		for (int i = start + 1; i < end; i+=2) {
			tempi=100*i;
			char op = exp[i];
			if (op == '&')
				c+= placeParen(exp, 1, start, i-1, Map,level+1,str1,key,1+tempi) * placeParen(exp, 1, i+1, end, Map,level+1,str2,key,1+tempi);
			else if (op == '|') {
				c += placeParen(exp, 1, start, i-1, Map,level+1,str1,key,2+tempi) * placeParen(exp, 0, i+1, end, Map,level+1,str2,key,2+tempi);
				c += placeParen(exp, 0, start, i-1, Map,level+1,str1,key,3+tempi) * placeParen(exp, 1, i+1, end, Map,level+1,str2,key,3+tempi);
				c += placeParen(exp, 1, start, i-1, Map,level+1,str1,key,4+tempi) * placeParen(exp, 1, i+1, end, Map,level+1,str2,key,4+tempi);
			}
			else if (op == '^' ) {
				c += placeParen(exp, 1, start, i-1, Map,level+1,str1,key,5+tempi) * placeParen(exp, 0, i+1, end, Map,level+1,str2,key,5+tempi);
				c += placeParen(exp, 0, start, i-1, Map,level+1,str1,key,6+tempi) * placeParen(exp, 1, i+1, end, Map,level+1,str2,key,6+tempi);
			}
		}
	}
	else{
		for (int i = start + 1; i < end; i+=2) {
			tempi=100*i;
			char op = exp[i];
			if (op == '&') {
				c += placeParen(exp, 0, start, i-1, Map,level+1,str1,key,7+tempi) * placeParen(exp, 1, i+1, end, Map,level+1,str2,key,7+tempi);
				c += placeParen(exp, 1, start, i-1, Map,level+1,str1,key,8+tempi) * placeParen(exp, 0, i+1, end, Map,level+1,str2,key,8+tempi);
				c += placeParen(exp, 0, start, i-1, Map,level+1,str1,key,9+tempi) * placeParen(exp, 0, i+1, end, Map,level+1,str2,key,9+tempi);
			}
			else if (op == '|')
				c += placeParen(exp, 0, start, i-1, Map,level+1,str1,key,10+tempi) * placeParen(exp, 0, i+1, end, Map,level+1,str2,key,10+tempi);
			else if (op == '^' ) {
				c += placeParen(exp, 1, start, i-1, Map,level+1,str1,key,11+tempi) * placeParen(exp, 1, i+1, end, Map,level+1,str2,key,11+tempi);
				c += placeParen(exp, 0, start, i-1, Map,level+1,str1,key,12+tempi) * placeParen(exp, 0, i+1, end, Map,level+1,str2,key,12+tempi);
			}
		}
	}
	Map[key] = c;
	return c;
}

int main(){
        int level=0;
        string ost="";

	mi Map;
	string s = "1&0&1|1";
	cout<<placeParen(s, 1, 0, s.length()-1, Map,level,ost,0,0) << endl;

	cout << "Map size= " << Map.size() << endl;

	for(auto &n:Map){
	  cout << n.first << " , " << n.second << endl;
	}

        cout << "Map_m size= " << Map_m.size() << endl;
        
        for(auto &n:Map_m){ 
          cout << n.first << " , " << n.second << endl;
        }

        cout << "Map_p size= " << Map_p.size() << endl;

        for(auto &n:Map_p){
          cout << n.first << " , " << n.second << endl;
        }


        /*int len=s.length();
        int iv;
        int kv;
        for(int i=0;i<len;i++){
          for(int j=i;j<len;j++){
            kv=200+i*7+j*3;
            iv=Map[kv];
            cout << i << " " << j << " : " << iv << endl;
          }
        }
        */

	return 0;
}










