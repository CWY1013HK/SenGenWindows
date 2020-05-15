#include <iostream>
#include <fstream>
#include <cstdlib>
#include <map>
#include <vector>
#include <ctime>
using namespace std;

/* Sample
string (int hpf, map<string, vector<string> > uwb) {
  string res;
  
  int randomiser = rand() %
  switch(randomiser){
    case 
  }
  return res;
}
*/

string GetPreNoun(bool single, map<string, vector<string> > uwb) {
  string res;
  int randomiser = rand() % 7;
  switch(randomiser){
    case 0:
    res = res + "";
    break;
    case 1:
    res = res + " the";
    break;
    case 2:
    res = res + " a";
    break;
    case 3:
    res = res + " my";
    break;
    case 4:
    res = res + " your";
    break;
    case 5:
    res = res + " their";
    break;
    case 6:
    res = res + " our";
    break;
  }
  for (auto const vtype : uwb) { 
    if (vtype.first == "adj") {
      vector<string> temp = vtype.second;
      randomiser = rand() % temp.size();
      int x = randomiser;
      string y = temp[x];
      string z = y;
      z.erase(0, 1);
      if (y != "#") {
        if (res != " a") {
          if (y[0] == '*' || '^') {
          res = res + " ";
          res = res + z;
          } else {
            res = res + " ";
            res = res + y;
          }
        } else {
          if (y[0] == '*') {
            res = res + "n";
            res = res + " ";
            res = res + z;
          } else if (y[0] == '^') {
            res = res + " ";
            res = res + z;
          } else {
            res = res + " ";
            res = res + y;
          }
        }
      }
    }
  } 
  return res;
}

string GetWord(string type, string prenoun, map<string, vector<string> > uwb) {
  string res;
  for (auto const vtype : uwb) { 
    if (vtype.first == type) {
      vector<string> temp = vtype.second;
      
      int randomiser = rand() % temp.size();
      int x = randomiser;
      string y = temp[x];
      string z = y;
      z.erase(0, 1);
      if (y != "#") {
        if (prenoun != " a") {
          if (y[0] == '*' || y[0] == '^') {
          res = res + " ";
          res = res + z;
          } else {
            res = res + " ";
            res = res + y;
          }
        } else {
          if (y[0] == '*') {
            res = res + "n";
            res = res + " ";
            res = res + z;
          } else if (y[0] == '^') {
            res = res + " ";
            res = res + z;
          } else {
            res = res + " ";
            res = res + y;
          }
        }
      }
    }
  } 
  return res;
}

string RegStart(int hpf, map<string, vector<string> > uwb) {
  string res;
  string buffer;
  switch(hpf) {
    case 0: {
      
  int randomiser = rand() % 5;
  switch(randomiser){
    case 0: {
    string prenoun = GetPreNoun(true, uwb);
    res = res + prenoun;
    res = res + GetWord("snoun", prenoun, uwb);
    res = res + GetWord("adv", "#", uwb);
    res = res + GetWord("hsverb", "#", uwb);
    break;
    }
    case 1: {
      randomiser = rand() % 2;
      if (randomiser == 1) {
      res = res + " the";}
    res = res + GetWord("adj", "#", uwb);
    res = res + GetWord("pnoun", "#", uwb);
    res = res + GetWord("adv", "#", uwb);
    res = res + GetWord("hpverb", "#", uwb);
    break;
    }
    case 2: {
    res = res + " I";
    res = res + GetWord("adv", "#", uwb);
    res = res + GetWord("hiverb", "#", uwb);
    break;
    }
    case 3: {
    res = res + GetWord("ssubpronoun", "#", uwb);
    res = res + GetWord("adv", "#", uwb);
    res = res + GetWord("hsverb", "#", uwb);
    break;
    }
    case 4: {
    res = res + GetWord("psubpronoun", "#", uwb);
    res = res + GetWord("adv", "#", uwb);
    res = res + GetWord("hpverb", "#", uwb);
    break;
    }
  }
  break;
  }
  case 1: {
    
  int randomiser = rand() % 5;
  switch(randomiser){
    case 0: {
    string prenoun = GetPreNoun(true, uwb);
    res = res + prenoun;
    res = res + GetWord("snoun", prenoun, uwb);
    
    randomiser = rand() % 2;
    if (randomiser == 1) {
      buffer = GetWord("hpreposition", "#", uwb);
      if (buffer == " do"){
        res = res + " does";
      }else {
        res = res + buffer;
        }
    } else {
      buffer = GetWord("nhpreposition", "#", uwb);
      if (buffer == " do not"){
        res = res + " does not";
      }else {
        res = res + buffer;
        }
    }
    res = res + GetWord("adv", "#", uwb);
    if (buffer == "") {
    res = res + GetWord("psverb", "#", uwb);}
    else {
    res = res + GetWord("ppverb", "#", uwb);  
    }
    break;
    }
    case 1: {
    randomiser = rand() % 2;
      if (randomiser == 1) {
      res = res + " the";}
    res = res + GetWord("adj", "#", uwb);
    res = res + GetWord("pnoun", "#", uwb);
    if (randomiser == 1) {
      res = res + GetWord("hpreposition", "#", uwb);
    } else {
      res = res + GetWord("nhpreposition", "#", uwb);
    }
    res = res + GetWord("adv", "#", uwb);
    res = res + GetWord("ppverb", "#", uwb);
    break;
    }
    case 2: {
    res = res + " I";
    if (randomiser == 1) {
      res = res + GetWord("hpreposition", "#", uwb);
    } else {
      res = res + GetWord("nhpreposition", "#", uwb);
    }
    res = res + GetWord("adv", "#", uwb);
    res = res + GetWord("piverb", "#", uwb);
    break;
    }
    case 3: {
    res = res + GetWord("ssubpronoun", "#", uwb);
    if (randomiser == 1) {
      buffer = GetWord("hpreposition", "#", uwb);
      if (buffer == " do"){
        res = res + " does";
      }else {
        res = res + buffer;
        }
    } else {
      buffer = GetWord("nhpreposition", "#", uwb);
      if (buffer == " do not"){
        res = res + " does not";
      }else {
        res = res + buffer;
        }
    }
    res = res + GetWord("adv", "#", uwb);
    if (buffer == "") {
    res = res + GetWord("psverb", "#", uwb);}
    else {
    res = res + GetWord("ppverb", "#", uwb);  
    }
    break;
    }
    case 4: {
    res = res + GetWord("psubpronoun", "#", uwb);
    if (randomiser == 1) {
      res = res + GetWord("hpreposition", "#", uwb);
    } else {
      res = res + GetWord("nhpreposition", "#", uwb);
    }
    res = res + GetWord("adv", "#", uwb);
    res = res + GetWord("ppverb", "#", uwb);
    break;
    }
  }
  break;
  }
  case 2: {
    
  int randomiser = rand() % 5;
  switch(randomiser){
    case 0: {
    string prenoun = GetPreNoun(true, uwb);
    res = res + prenoun;
    res = res + GetWord("snoun", prenoun, uwb);
    if (randomiser == 1) {
      buffer = GetWord("ppreposition", "#", uwb);
      if (buffer == " do"){
        res = res + " does";
      }else {
        res = res + buffer;
        }
    } else {
      buffer = GetWord("nppreposition", "#", uwb);
      if (buffer == " do not"){
        res = res + " does not";
      }else {
        res = res + buffer;
        }
    }
    res = res + GetWord("adv", "#", uwb);
    if (buffer == "") {
    res = res + GetWord("psverb", "#", uwb);}
    else {
    res = res + GetWord("ppverb", "#", uwb);  
    }
    break;
    }
    case 1: {
    randomiser = rand() % 2;
      if (randomiser == 1) {
      res = res + " the";}
    res = res + GetWord("adj", "#", uwb);
    res = res + GetWord("pnoun", "#", uwb);
    if (randomiser == 1) {
      res = res + GetWord("ppreposition", "#", uwb);
    } else {
      res = res + GetWord("nppreposition", "#", uwb);
    }
    res = res + GetWord("adv", "#", uwb);
    res = res + GetWord("ppverb", "#", uwb);
    break;
    }
    case 2: {
    res = res + " I";
    if (randomiser == 1) {
      res = res + GetWord("ppreposition", "#", uwb);
    } else {
      res = res + GetWord("nppreposition", "#", uwb);
    }
    res = res + GetWord("adv", "#", uwb);
    res = res + GetWord("piverb", "#", uwb);
    break;
    }
    case 3: {
    res = res + GetWord("ssubpronoun", "#", uwb);
    if (randomiser == 1) {
      buffer = GetWord("ppreposition", "#", uwb);
      if (buffer == " do"){
        res = res + " does";
      }else {
        res = res + buffer;
        }
    } else {
      buffer = GetWord("ppreposition", "#", uwb);
      if (buffer == " do not"){
        res = res + " does not";
      }else {
        res = res + buffer;
        }
    }
    res = res + GetWord("adv", "#", uwb);
    if (buffer == "") {
    res = res + GetWord("psverb", "#", uwb);}
    else {
    res = res + GetWord("ppverb", "#", uwb);  
    }
    break;
    }
    case 4: {
    res = res + GetWord("psubpronoun", "#", uwb);
    if (randomiser == 1) {
      res = res + GetWord("ppreposition", "#", uwb);
    } else {
      res = res + GetWord("nppreposition", "#", uwb);
    }
    res = res + GetWord("adv", "#", uwb);
    res = res + GetWord("ppverb", "#", uwb);
    break;
    }
  }
  break;
  }
  }
  
  int randomiser = rand() % 5;
  switch(randomiser){
    case 0: {
    string prenoun = GetPreNoun(true, uwb);
    res = res + prenoun;
    res = res + GetWord("snoun", prenoun, uwb);
    break;
    }
    case 1: {
    randomiser = rand() % 2;
      if (randomiser == 1) {
      res = res + " the";}
    res = res + GetWord("adj", "#", uwb);
    res = res + GetWord("pnoun", "#", uwb);
    break;
    }
    case 2: {
    res = res + " me";
    break;
    }
    case 3: {
    res = res + GetWord("sobjpronoun", "#", uwb);
    break;
    }
    case 4: {
    res = res + GetWord("pobjpronoun", "#", uwb);
    break;
    }
  }
  return res;
}

string ComStart(map<string, vector<string> > uwb) {
  string res;
  
  int randomiser = rand() % 5;
  switch(randomiser){
    case 0: {
    res = res + GetWord("adv", "#", uwb);
    string buffer = GetWord("ppverb", "#", uwb);
    while (buffer == " are") {
      buffer = GetWord("ppverb", "#", uwb);
    }
    res = res + buffer;
    string prenoun = GetPreNoun(true, uwb);
    res = res + prenoun;
    res = res + GetWord("snoun", prenoun, uwb);
    break;
    }
    case 1: {
    res = res + GetWord("adv", "#", uwb);
    string buffer = GetWord("ppverb", "#", uwb);
    while (buffer == " are") {
      buffer = GetWord("ppverb", "#", uwb);
    }
    res = res + buffer;
    randomiser = rand() % 2;
      if (randomiser == 1) {
      res = res + " the";}
    res = res + GetWord("adj", "#", uwb);
    res = res + GetWord("pnoun", "#", uwb);
    break;
    }
    case 2: {
    res = res + GetWord("adv", "#", uwb);
    string buffer = GetWord("ppverb", "#", uwb);
    while (buffer == " are") {
      buffer = GetWord("ppverb", "#", uwb);
    }
    res = res + buffer;
    res = res + " me";
    break;
    }
    case 3: {
    res = res + GetWord("adv", "#", uwb);
    string buffer = GetWord("ppverb", "#", uwb);
    while (buffer == " are") {
      buffer = GetWord("ppverb", "#", uwb);
    }
    res = res + buffer;
    res = res + GetWord("sobjpronoun", "#", uwb);
    break;
    }
    case 4: {
    res = res + GetWord("adv", "#", uwb);
    string buffer = GetWord("ppverb", "#", uwb);
    while (buffer == " are") {
      buffer = GetWord("ppverb", "#", uwb);
    }
    res = res + buffer;
    res = res + GetWord("pobjpronoun", "#", uwb);
    break;
    }
  }
  return res;
}

string CmpStart(int hpf, map<string, vector<string> > uwb) {
  string res;
  
  int randomiser = rand() % 2;
  switch(randomiser){
    case 0: {
      res = res + " if";
      res = res + RegStart(hpf, uwb);
      res = res + ",";
      
      int randomiser = rand() % 2;
      switch(randomiser){
        
        case 0: res = res + RegStart(rand() % 2 + 1, uwb) + "."; break;
        case 1: res = res + ComStart(uwb) + "."; break;
      }
      break;
    }
    case 1: {
      res = res + " when";
      res = res + RegStart(hpf, uwb);
      res = res + ",";
      
      int randomiser = rand() % 2;
      switch(randomiser){
        case 0: res = res + RegStart(rand() % 2 + 1, uwb) + "."; break;
        case 1: res = res + ComStart(uwb) + "."; break;
      }
      break;
    }
  }
  return res;
}

string SenStart(int sen, int hpf, map<string, vector<string> > uwb) {
  string res;
  switch(sen){
    case 0: res = RegStart(hpf, uwb) + ".";
    break;
    case 1: res = ComStart(uwb) + ".";
    break;
    case 2: res = CmpStart(hpf, uwb);
    break;
    /*case 3: res = QueStart(hpf, uwb) + "?";
    break;*/
  }
  res[1] = toupper(res[1]);
  return res;
}













int main() {
    std::srand(time(NULL));
    std::system("clear");
    

    map<string, vector<string> > uwb;

    vector<string> snoun;
    uwb["snoun"] = snoun;
    vector<string> pnoun;
    uwb["pnoun"] = pnoun;

    //string isubpronoun = "I";
    vector<string> ssubpronoun;
    ssubpronoun.push_back("he");
    ssubpronoun.push_back("she");
    ssubpronoun.push_back("it");
    uwb["ssubpronoun"] = ssubpronoun;

    //string iobjpronoun = "me";
    vector<string> sobjpronoun;
    sobjpronoun.push_back("him");
    sobjpronoun.push_back("her");
    sobjpronoun.push_back("it");
    uwb["sobjpronoun"] = sobjpronoun;

    vector<string> psubpronoun;
    psubpronoun.push_back("we");
    psubpronoun.push_back("they");
    uwb["psubpronoun"] = psubpronoun;

    vector<string> pobjpronoun;
    pobjpronoun.push_back("us");
    ssubpronoun.push_back("them");
    uwb["pobjpronoun"] = pobjpronoun;
    
    //Present
    vector<string> psverb;
    psverb.push_back("be");
    //psverb.push_back("is");
    uwb["psverb"] = psverb;
    vector<string> ppverb;
    ppverb.push_back("be");
    //ppverb.push_back("are");
    uwb["ppverb"] = ppverb;
    vector<string> piverb;
    piverb.push_back("be");
    //piverb.push_back("am");
    uwb["piverb"] = piverb;
    //Past
    vector<string> hsverb;
    hsverb.push_back("was");
    uwb["hsverb"] = hsverb;
    vector<string> hpverb;
    hsverb.push_back("were");
    uwb["hpverb"] = hpverb;
    vector<string> hiverb;
    hiverb.push_back("was");
    hiverb.push_back("were");
    uwb["hiverb"] = hiverb;

    vector<string> adj;
    adj.push_back("#");
    uwb["adj"] = adj;
    vector<string> adv;
    adv.push_back("#");
    uwb["adv"] = adv;

    vector<string> fpreposition;
    fpreposition.push_back("will");
    fpreposition.push_back("shall");
    fpreposition.push_back("ought to");
    fpreposition.push_back("may");
    fpreposition.push_back("can");
    fpreposition.push_back("do");
    uwb["fpreposition"] = fpreposition;

    vector<string> nfpreposition;
    nfpreposition.push_back("will not");
    nfpreposition.push_back("shall not");
    nfpreposition.push_back("ought not to");
    nfpreposition.push_back("may not");
    nfpreposition.push_back("can not");
    nfpreposition.push_back("do not");
    uwb["nfpreposition"] = nfpreposition;

    vector<string> hpreposition;
    hpreposition.push_back("#");
    hpreposition.push_back("would");
    hpreposition.push_back("should");
    hpreposition.push_back("ought to");
    hpreposition.push_back("might");
    hpreposition.push_back("could");
    hpreposition.push_back("did");
    uwb["hpreposition"] = hpreposition;

    vector<string> nhpreposition;
    nhpreposition.push_back("#");
    nhpreposition.push_back("would not");
    nhpreposition.push_back("should not");
    nhpreposition.push_back("ought not to");
    nhpreposition.push_back("might not");
    nhpreposition.push_back("could not");
    hpreposition.push_back("didn not");
    uwb["nhpreposition"] = nhpreposition;

    vector<string> qstart;
    qstart.push_back("what");
    qstart.push_back("when");
    qstart.push_back("where");
    qstart.push_back("who");
    qstart.push_back("why");
    qstart.push_back("which one");
    qstart.push_back("how");
    qstart.push_back("did");
    uwb["qstart"] = qstart;
    
    string wpk;

    ifstream rpf ("Documents/SenGen/Preference.txt");
    if (rpf.is_open())
  {
        string pref;
        string ptype;
        while (rpf >> pref >> ptype) {
          std::cout << ptype << " " << pref << "\n";
        if (ptype == "wpk") {
            wpk = pref;
          }
        }
    }
    rpf.close();
    
    string loc = "Documents/SenGen/Wordpacks/";
    loc = loc + wpk;

    ifstream tst (loc + "/wordbase.txt");
    if (tst.is_open()) tst.close(); else  {cout << "~FOUL WORKPACK LOCATION; TO DEFAULT~"; loc = "Documents/SenGen/Wordpacks/Default";}

    ifstream rwb (loc + "/wordbase.txt");
    if (rwb.is_open())
  {
        string word;
        string wtype;
        while (rwb >> word >> wtype) {
          std::cout << wtype << " " << word << "\n";
        for (auto const vtype : uwb) {
          if (vtype.first == wtype) {
            vector<string> temp = vtype.second;
            temp.push_back(word);
            uwb[wtype] = temp; 
          }
        }
        if (wtype == "ppverb") {
            vector<string> temp = uwb.at("piverb");
            temp.push_back(word);
            uwb["piverb"] = temp;
          }
          if (wtype == "hsverb") {
            vector<string> temp = uwb.at("hiverb");
            temp.push_back(word);
            uwb["hiverb"] = temp;
          }
        }
    }
    rwb.close();
    ifstream rwbd (loc + "/wordbase-double.txt");
    if (rwbd.is_open())
  {
        string wordst;
        string wordnd;
        string word;
        string wtype;
        while (rwbd >> wordst >> wordnd >> wtype) {
          word = wordst + " " + wordnd;
          std::cout << wtype << " " << word << "\n";
        for (auto const vtype : uwb) {
          if (vtype.first == wtype) {
            vector<string> temp = vtype.second;
            temp.push_back(word);
            uwb[wtype] = temp;
          }
        }
        if (wtype == "ppverb") {
            vector<string> temp = uwb.at("piverb");
            temp.push_back(word);
            uwb["piverb"] = temp;
          }
          if (wtype == "hsverb") {
            vector<string> temp = uwb.at("hiverb");
            temp.push_back(word);
            uwb["hiverb"] = temp;
          }
        }
    }
    rwbd.close();
    
    ifstream rwbt (loc + "/wordbase-triple.txt");
    if (rwbt.is_open())
  {
        string wordst;
        string wordnd;
        string wordrd;
        string word;
        string wtype;
        while (rwbt >> wordst >> wordnd >> wordrd >> wtype) {
          word = wordst + " " + wordnd + " " + wordrd;
          std::cout << wtype << " " << word << "\n";
        for (auto const vtype : uwb) {
          if (vtype.first == wtype) {
            vector<string> temp = vtype.second;
            temp.push_back(word);
            uwb[wtype] = temp;
          }
        }
        if (wtype == "ppverb") {
            vector<string> temp = uwb.at("piverb");
            temp.push_back(word);
            uwb["piverb"] = temp;
          }
          if (wtype == "hsverb") {
            vector<string> temp = uwb.at("hiverb");
            temp.push_back(word);
            uwb["hiverb"] = temp;
          }
        }
    }
    rwbt.close();

    std::system("clear");
    for (auto const vtype : uwb) {
      vector<string> temp = vtype.second;
      for (auto const x : temp) {
        std:cout << vtype.first << " " << x << "\n";
      }
    }
    std::system("clear");
    std::system("clear");

    //std::system("cd \"desktop/tools/visual studio codes/C++/Sentence Generator\"");
      
    int sen = rand() % 3;
    //sen 0 = regular, 1 = command, 2 = compound, 3 = question;
    
    int hpf = rand() % 3;
    // hpf 0 = h, 1 = p, 2 = f;
    string sentence = SenStart(sen, hpf, uwb);
    std::cout << sentence << "\n";
    string t2s = "say " + sentence;
    std::system(t2s.c_str());
    ofstream wout ("Documents/SenGen/output.txt", std::ios_base::app);
    if (wout.is_open())
  {
    wout << sentence << "\n\n";
  }
  wout.close();
    std::cout << "\n~END~\n\n";
}
