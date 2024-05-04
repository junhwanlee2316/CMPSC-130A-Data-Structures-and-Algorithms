/*
* Name: Junhwan Lee
* Date: 11/09/2022
* Project: UCSB CS130A Project 2 Kattis: Babelfish
* Description: Created a container of array of lists.
* Hash table inserts word and translate to the index position.
* If collision appears, the pair gets inserted at the end of the list.
*/

// library
#include <iostream>
#include <vector>
#include <string>
#include <ctime>
#include <sstream>
#include <list>

using namespace std;

// Declare the size of the vector
static int SIZE = 200000;
// Container hash table
vector<list<pair<string,string>>> dict(SIZE);

// begin main
int main(){

    // line string
    string line;
    // hash function
    hash<string> hash1;

    // read word and translate -> insert to hash table
    while (getline(cin, line) && line != ""){
        
        // declare word and translate
        string word, foregin;

        // divide string line into word and translate
        int index = line.find(' ');
        word = line.substr(0,index);
        foregin = line.substr(index+1, line.size()-1);

        // create index: key
        int key = hash1(foregin) % SIZE;
        // insert pair at key position
        dict[key].push_back(make_pair(word,foregin));        
    }

    // read translate
    while(getline(cin, line) && line != ""){

        // f = translate
        string f = line;

        // get key 
        int key = hash1(f) % SIZE;

        // iterator through the list of pairs
        list<pair<string,string>>::iterator it;

        // declare boolean variable to indicate if the word exists
        bool found = false;
        string word;

        // iterate through the list of pairs at particular key index of dictionary
        for(it = dict[key].begin(); it != dict[key].end(); it++){

            // if translate exists
            if(it->second == line){ 
                // mark found
                found = true;
                word = it->first;
            }
        }

        // print result
        if(found) cout<<word<<endl;
        else cout<<"eh"<<endl;
    }

    return 0;
}
// end of program