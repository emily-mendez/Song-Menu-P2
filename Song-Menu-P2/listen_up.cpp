#include <sstream>
#include "Functions.h"
#include <stdexcept>

int main() {
    string userInput;
    vector<string> userInputVals;
    while(true) {
        cout << "Enter [song <songid> <artist> <duration> <title>" << endl;
        cout << "       " << "remove <title>" << endl;
        cout << "       " << "listen <title> <seconds>" << endl;
        cout << "       " << "favorite" << endl;
        cout << "       " << "show_listen_time" << endl;
        cout << "       " << "quit]" << endl;
        cout << ":"; 
        getline(cin, userInput);
        istringstream iss(userInput);

        string token;
        while(iss >> token) {
            if(token.front() == '"') {
                string quotedToken = token.substr(1);
                if (token.back() == '"') {
                    quotedToken.pop_back();
                    userInputVals.push_back(quotedToken);
                } else {
                    while (iss >> token) {
                        quotedToken += " " + token;
                        if (token.back() == '"') {
                            quotedToken.pop_back();
                            break;
                        }
                    }
                    userInputVals.push_back(quotedToken);
                }
            } else {
                userInputVals.push_back(token);
            }
        }

        string command = userInputVals.at(0);

        if(command=="song") {
            if(userInputVals.size() < 5) {
                throw invalid_argument("Missing arguments for song command.");
            }
            handleSong(userInputVals);
        }
        else if(command=="remove") {
            if(userInputVals.size() < 2) {
                throw invalid_argument("Missing arguments for remove command.");
            }
            handleRemove(userInputVals);
        }
        else if(command=="listen") {
            if(userInputVals.size() < 3) {
                throw invalid_argument("Missing arguments for listen command.");
            }
            handleListen(userInputVals);
        }
        else if(command=="favorite") {
            if(userInputVals.size() > 1) {
                throw invalid_argument("Favorite does not take any arguments.");
            }
            handleFavorite();
        }
        else if(command=="show_listen_time") {
            if(userInputVals.size() > 1) {
                throw invalid_argument("Show_listen_time does not take any arguments.");
            }
            handleShow();
        }
        else if(command=="test") {
            handleTest();
        }
        else if(command=="quit") {
            break;
        }
        else {
            cout << "Command not recognized, please try again." << endl;
        }

        userInputVals.clear();
    }
}
