#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

using namespace std;

int main()
{
  // Opening the file and declaring a string variable for lines
  ifstream file("oxford.txt");
  string line;

  // String to display if searched word is not found
  string notFoundMsg{}, firstMsg{"Sorry, "}, lastMsg{" not found!"};

  // Getting search keyword from the user
  cout << "Enter a word to search :: ";
  string key{};
  getline(cin, key);

  // Converting the keyword into titlecase if it's not
  if (key[0] >= 97 && key[0] <= 122)
    key[0] -= 32;

  // Searching the keyword given from user in the file line-by-line
  while (getline(file, line))
  {

    // storing first word of line in firstWord variable
    stringstream ss{line};
    string firstWord;
    ss >> firstWord;

    if (firstWord == key)
    {
      cout << line << endl;

      cout << "\n Add to favorites? : (y/n): ";
      string addFav{};
      cin >> addFav;

      // Writing into history file
      ofstream historyfile;
      historyfile.open("history.txt", ios::app); //ios::app => append mode
      historyfile << line + "\n\n";
      historyfile.close();

      // Writing into fav file
      if (addFav == "y" || addFav == "Y")
      {
        ofstream favFile;
        favFile.open("fav.txt", ios::app);
        favFile << line + "\n\n";
        favFile.close();
      }

      notFoundMsg = "found";
      break;
    }
  }

  // if word is not found
  if (notFoundMsg != "found")
  {
    notFoundMsg = firstMsg + "'" + key + "'" + lastMsg;
    cout << notFoundMsg << endl;

    ofstream historyfile;
    historyfile.open("history.txt", ios::app);
    historyfile << key + "\n\n";
    historyfile.close();
  }

  return 0;
}
