#include <iostream>
#include <fstream>
#include <string>
#include <sstream> 

using namespace std;

int main ()
{
  // Opening the file and declaring a string variable for lines
  ifstream file("oxford.txt");
  string line;
  
  // String to display if searched word is not found
  string notFoundMsg{}, firstMsg{"Sorry, "}, lastMsg{" not found!"};
  
  // Getting search keyword from the user
  cout<<"Enter a word to search :: ";
  string key{};
  getline(cin,key);
  
  // Converting the keyword into titlecase if it's not
  if(key[0]>=97 && key[0]<=122) key[0] -= 32;
  
  // Searching the keyword given from user in the file line-by-line
  while (getline(file, line)) {
  	
  	// storing first word of line in firstWord variable
  	stringstream ss { line };
  	string firstWord;
  	ss >> firstWord; 
  
	if(firstWord == key){
  		cout << line << endl;
  		notFoundMsg = " ";
  		break;
	}else{
		 notFoundMsg = firstMsg+" '"+key+"' "+lastMsg;
	}
  }
  
  // if word is found this will be an empty string
  cout<<notFoundMsg<<endl;

  return 0;
}
