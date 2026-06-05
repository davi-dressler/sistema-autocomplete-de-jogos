#include <iostream>
#include "Trie.hpp"
#include "GamesDatabase.hpp"

using namespace std;

int main(int argc, char* argv[]) {
    // if (argc != 2) {
    //     cout << "Usage: ./app k prefix" << endl;
    //     return 1;
    // }

    // int numGamesToRead = atoi(argv[1]);

    // numGamesToRead = max(numGamesToRead, 0);
    // numGamesToRead = min(numGamesToRead, numberOfGames);

    // std::cout << "Reading " << numGamesToRead << " games:\n\n";

    Trie trie;

    std::vector<Game*> gamesVector(numberOfGames); 
    for(int i = 0; i < numberOfGames; i++){
      trie.insert(&games[i]);

      gamesVector[i] = &games[i];
    }

    
    return 0;
}
