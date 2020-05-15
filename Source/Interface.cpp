#include <iostream>
#include <fstream>
#include <cstdlib>
#include <map>
#include <vector>
#include <ctime>
#include <chrono>
#include <thread>
#include <ctime>
using namespace std;

int main() {
    std::srand(time(NULL));
    std::system("clear");
    cout << "SENGEN\nCreated by CWY1013HK 2020\nInterface Version : 2.3\n\n";
    int SetUp;
    cout << "SetUp [1/0] : ";
    cin >> SetUp;
    if (SetUp == 1) {
    string wpk;
    cout << "Wordpack : ";
    cin >> wpk;
    ofstream wout ("Documents/SenGen/Preference.txt", std::ios_base::trunc);
    if (wout.is_open())
  {
    wout << wpk << " wpk" << "\n";
  }
  wout.close();
    }
    long attempts;
    cout << "\nAttempts : ";
    cin >> attempts;
    std::system("clear");
    while (attempts != 0) {
      long looper = 1;
      while (looper <= attempts) {
        cout << "Attempt " << looper << "\n";
        std::system("\"./Documents/SenGen/generator\"");
        std::this_thread::sleep_for(std::chrono::milliseconds(rand() % 1000 + 1000));
        std::system("clear");
        ++looper;
      }
      cout << "~DONE~\n\n";
      cout << "Attempts : ";
      cin >> attempts;
      std::system("clear");
    }
    cout << "~END~\n\n";
}
