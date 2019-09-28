//Cesar Sepulveda
#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <cctype>
#include <iomanip>
using namespace std;

class Keywords{
  private:
    string key1 = "int";
    string key2 = "float";
    string key3 = "bool";
    string key4 = "if";
    string key5 = "else";
    string key6 = "then";
    string key7 = "endif";
    string key8 = "while";
    string key9 = "whileend";
    string key10 = "do";
    string key11 = "doend";
    string key12 = "for";
    string key13 = "forend";
    string key14 = "input";
    string key15 = "output";
    string key16 = "and";
    string key17 = "or";
    string key18 = "function";
    vector<string> key;
  public:
    void addKeyword(){
      key.push_back(key1);
      key.push_back(key2);
      key.push_back(key3);
      key.push_back(key4);
      key.push_back(key5);
      key.push_back(key6);
      key.push_back(key7);
      key.push_back(key8);
      key.push_back(key9);
      key.push_back(key10);
      key.push_back(key11);
      key.push_back(key12);
      key.push_back(key13);
      key.push_back(key14);
      key.push_back(key15);
      key.push_back(key16);
      key.push_back(key17);
      key.push_back(key18);
  }
  void getKeys(vector<string>& temp){
    for(int i = 0; i < key.size(); i++){
      temp.push_back(key.at(i));
    }
  }
};

class Separators{
  private:
    string sep1 = "'";
    string sep2 = "(";
    string sep3 = ")";
    string sep4 = "{";
    string sep5 = "}";
    string sep6 = "[";
    string sep7 = "]";
    string sep8 = ",";
    string sep9 = ".";
    string sep10 = ":";
    string sep11 = ";";
    string sep12 = "!";
    string sep13 = " ";
    vector<string> separator;
  public:
    void addSeparator(){
      separator.push_back(sep1);
      separator.push_back(sep2);
      separator.push_back(sep3);
      separator.push_back(sep4);
      separator.push_back(sep5);
      separator.push_back(sep6);
      separator.push_back(sep7);
      separator.push_back(sep8);
      separator.push_back(sep9);
      separator.push_back(sep10);
      separator.push_back(sep11);
      separator.push_back(sep12);
      separator.push_back(sep13);
    }
    void getSeparators(vector<string>& temp){
      for(int i =0; i < separator.size(); i++){
        temp.push_back(separator.at(i));
      }
    }
};

class Operators{
  private:
    string op1 = "*";
    string op2 = "+";
    string op3 = "-";
    string op4 = "=";
    string op5 = "/";
    string op6 = ">";
    string op7 = "<";
    string op8 = "%";
    vector<string> ope;
  public:
    void addOperator(){
      ope.push_back(op1);
      ope.push_back(op2);
      ope.push_back(op3);
      ope.push_back(op4);
      ope.push_back(op5);
      ope.push_back(op6);
      ope.push_back(op7);
      ope.push_back(op8);
    }
    void getOperators(vector<string>& temp){
      for(int i = 0; i < ope.size(); i++){
        temp.push_back(ope.at(i));
      }
    }
};

vector<char> readFile(vector<char> input, string filename){
  fstream myFile;
  char in;
  string blank;
  myFile.open(filename);
  while(myFile.get(in)){
    if(in == '\n'){}
    else{
      input.push_back(in);
    }
  }
  myFile.close();
  return input;
}

vector<string> convert(vector<char> input){
  vector<string> newInput;
  string buffer;
  int count = 1;
  for(int i=0; i < input.size(); ++i){
    if(ispunct(input.at(i))){
      buffer.push_back(input.at(i));
      newInput.push_back(buffer);
      buffer.clear();
    }/*else if(isalpha(input.at(i))){
      while(isalpha(input.at(i)) || ispunct(input.at(i)) || isdigit(input.at(i))){
        buffer.push_back(input.at(i));
        if(i < input.size()){++i;}
      }
      newInput.push_back(buffer);
      buffer.clear();
    }*/else if(isdigit(input.at(i))){
      while(isdigit(input.at(i)) || input.at(i) == '.'){
        buffer.push_back(input.at(i));
        if(i < input.size()){++i;}
      }
      newInput.push_back(buffer);
      buffer.clear();
    }else if(isspace(input.at(i)));
  }
  return newInput;
}

int main(){
  string filename;
  Keywords key;
  Operators op;
  Separators sep;
  key.addKeyword();
  op.addOperator();
  sep.addSeparator();
  vector<char> input;
  vector<string> keyterms;
  vector<string> operators;
  vector<string> separators;
  int find = 0;
  cout << "Enter the filename: ";
  cin >> filename;
  cout << endl;
  input = readFile(input, filename);
  sep.getSeparators(separators);
  op.getOperators(operators);
  key.getKeys(keyterms);
  vector<string> newInput = convert(input);
  cout << "TOKENS" << setw(20) << "Lexemes" << endl;
  for(int i = 0; newInput.size();++i){
    
    for(int j = 0; j < keyterms.size();++j){
      if(keyterms.at(j).compare(newInput.at(i)) == 0){
        cout << "KEYWORD" << setw(6) << "=" << setw(10) << keyterms.at(j) << endl;
      }
    }
    for(int k = 0; k < operators.size();++k){
      if(operators.at(k).compare(newInput.at(i)) == 0){
        cout << "OPERATOR" << setw(5) << "=" << setw(10) << operators.at(k) << endl;
      }
    }
    for(int l = 0; l < separators.size(); ++l){
      if(separators.at(l).compare(newInput.at(i)) == 0){
        cout << "SEPARATOR" << setw(4) << "=" << setw(10) << separators.at(l) << endl;
      /*  if(newInput.at(i).compare("!") == 0){
          find = newInput.at(i+1).find("!", i+1);
          i = find;//Cesar Sepulveda
#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <cctype>
#include <iomanip>
using namespace std;

class Keywords{
  private:
    string key1 = "int";
    string key2 = "float";
    string key3 = "bool";
    string key4 = "if";
    string key5 = "else";
    string key6 = "then";
    string key7 = "endif";
    string key8 = "while";
    string key9 = "whileend";
    string key10 = "do";
    string key11 = "doend";
    string key12 = "for";
    string key13 = "forend";
    string key14 = "input";
    string key15 = "output";
    string key16 = "and";
    string key17 = "or";
    string key18 = "function";
    vector<string> key;
  public:
    void addKeyword(){
      key.push_back(key1);
      key.push_back(key2);
      key.push_back(key3);
      key.push_back(key4);
      key.push_back(key5);
      key.push_back(key6);
      key.push_back(key7);
      key.push_back(key8);
      key.push_back(key9);
      key.push_back(key10);
      key.push_back(key11);
      key.push_back(key12);
      key.push_back(key13);
      key.push_back(key14);
      key.push_back(key15);
      key.push_back(key16);
      key.push_back(key17);
      key.push_back(key18);
  }
  void getKeys(vector<string>& temp){
    for(int i = 0; i < key.size(); i++){
      temp.push_back(key.at(i));
    }
  }
};

class Separators{
  private:
    string sep1 = "'";
    string sep2 = "(";
    string sep3 = ")";
    string sep4 = "{";
    string sep5 = "}";
    string sep6 = "[";
    string sep7 = "]";
    string sep8 = ",";
    string sep9 = ".";
    string sep10 = ":";
    string sep11 = ";";
    string sep12 = "!";
    string sep13 = " ";
    vector<string> separator;
  public:
    void addSeparator(){
      separator.push_back(sep1);
      separator.push_back(sep2);
      separator.push_back(sep3);
      separator.push_back(sep4);
      separator.push_back(sep5);
      separator.push_back(sep6);
      separator.push_back(sep7);
      separator.push_back(sep8);
      separator.push_back(sep9);
      separator.push_back(sep10);
      separator.push_back(sep11);
      separator.push_back(sep12);
      separator.push_back(sep13);
    }
    void getSeparators(vector<string>& temp){
      for(int i =0; i < separator.size(); i++){
        temp.push_back(separator.at(i));
      }
    }
};

class Operators{
  private:
    string op1 = "*";
    string op2 = "+";
    string op3 = "-";
    string op4 = "=";
    string op5 = "/";
    string op6 = ">";
    string op7 = "<";
    string op8 = "%";
    vector<string> ope;
  public:
    void addOperator(){
      ope.push_back(op1);
      ope.push_back(op2);
      ope.push_back(op3);
      ope.push_back(op4);
      ope.push_back(op5);
      ope.push_back(op6);
      ope.push_back(op7);
      ope.push_back(op8);
    }
    void getOperators(vector<string>& temp){
      for(int i = 0; i < ope.size(); i++){
        temp.push_back(ope.at(i));
      }
    }
};

vector<char> readFile(vector<char> input, string filename){
  fstream myFile;
  char in;
  string blank;
  myFile.open(filename);
  while(myFile.get(in)){
    if(in == '\n'){}
    else{
      input.push_back(in);
    }
  }
  myFile.close();
  return input;
}

vector<string> convert(vector<char> input){
  vector<string> newInput;
  string buffer;
  int count = 1;
  for(int i=0; i < input.size(); ++i){
    if(ispunct(input.at(i))){
      buffer.push_back(input.at(i));
      newInput.push_back(buffer);
      buffer.clear();
    }/*else if(isalpha(input.at(i))){
      while(isalpha(input.at(i)) || ispunct(input.at(i)) || isdigit(input.at(i))){
        buffer.push_back(input.at(i));
        if(i < input.size()){++i;}
      }
      newInput.push_back(buffer);
      buffer.clear();
    }*/else if(isdigit(input.at(i))){
      while(isdigit(input.at(i)) || input.at(i) == '.'){
        buffer.push_back(input.at(i));
        if(i < input.size()){++i;}
      }
      newInput.push_back(buffer);
      buffer.clear();
    }else if(isspace(input.at(i)));
  }
  return newInput;
}

int main(){
  string filename;
  Keywords key;
  Operators op;
  Separators sep;
  key.addKeyword();
  op.addOperator();
  sep.addSeparator();
  vector<char> input;
  vector<string> keyterms;
  vector<string> operators;
  vector<string> separators;
  int find = 0;
  cout << "Enter the filename: ";
  cin >> filename;
  cout << endl;
  input = readFile(input, filename);
  sep.getSeparators(separators);
  op.getOperators(operators);
  key.getKeys(keyterms);
  vector<string> newInput = convert(input);
  cout << "TOKENS" << setw(20) << "Lexemes" << endl;
  for(int i = 0; newInput.size();++i){
    
    for(int j = 0; j < keyterms.size();++j){
      if(keyterms.at(j).compare(newInput.at(i)) == 0){
        cout << "KEYWORD" << setw(6) << "=" << setw(10) << keyterms.at(j) << endl;
      }
    }
    for(int k = 0; k < operators.size();++k){
      if(operators.at(k).compare(newInput.at(i)) == 0){
        cout << "OPERATOR" << setw(5) << "=" << setw(10) << operators.at(k) << endl;
      }
    }
    for(int l = 0; l < separators.size(); ++l){
      if(separators.at(l).compare(newInput.at(i)) == 0){
        cout << "SEPARATOR" << setw(4) << "=" << setw(10) << separators.at(l) << endl;
      /*  if(newInput.at(i).compare("!") == 0){
          find = newInput.at(i+1).find("!", i+1);
          i = find;
          cout << "SEPARATOR" << setw(4) << "=" << setw(10) << separators.at(l) << endl;
        }*/
      }
    }
  }
  return 0;
}
          cout << "SEPARATOR" << setw(4) << "=" << setw(10) << separators.at(l) << endl;
        }*/
      }
    }
  }
  return 0;
}
