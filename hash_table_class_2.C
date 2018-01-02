#include <iostream>
#include <fstream>
#include <unordered_map>
#include <vector>
#include <string>
 
using namespace std;

class Make
{
public:
    string Name;

 
    Make(string name)
    {
      Name = name;
    }

 
    bool operator==(const Make &make) const
    {
      return Name == make.Name;
    }
};

class Model
{
public:
    string Name;
    int Year;

 
    Model(string name, int year)
    {
      Name = name;
      Year = year;
    }

 
    bool operator==(const Model &model) const
    {
      return (Name == model.Name && Year == model.Year);
    }
};

class ModelHash
{
public:
    size_t operator()(const Model &model) const
    {
      return hash<string>()(model.Name) ^ hash<int>()(model.Year);
    }
};

class MakeHash
{
public:
    size_t operator()(const Make &make) const
    {
      return hash<string>()(make.Name);
    }
};

int main()
{
    unordered_map<Model, Make, ModelHash> model2make;
 
    Model camry2005("Camry", 2005);
    Model tercel1993("Tercel", 1993);
      
    Make toyota("Toyota");
 
    model2make.emplace(camry2005, toyota);
    model2make.emplace(tercel1993, toyota);

 
    for (auto &itr : model2make)
    {
      cout << itr.first.Name << " " << itr.first.Year << ": " << itr.second.Name << endl;
    }

    cout << endl;

    unordered_map<Make, vector<Model>, MakeHash> make2model;

    vector<Model> toyotaModels;
    toyotaModels.push_back(camry2005);

 
    make2model.emplace(toyota, toyotaModels);

 
    make2model[toyota].push_back(tercel1993);

 
    for (auto &make : make2model)
    {
      cout << make.first.Name << endl;
 
      vector<Model> models = make.second;

      for(auto &model : models)
      {
        cout << " " << model.Name << " " << model.Year << endl;
      }
    }

    return 0;
}
