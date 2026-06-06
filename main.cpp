#include <iostream>
#include "Game.hpp"
#include "Trie.hpp"
#include "GamesDatabase.hpp"

using namespace std;

int main(int argc, char* argv[]) {
    if (argc != 3) {
        cout << "Usage: ./app k prefix" << endl;
        return 1;
    }

    int numGamesToRead = atoi(argv[1]);
    string prefix = argv[2];

    numGamesToRead = max(numGamesToRead, 0);
    numGamesToRead = min(numGamesToRead, numberOfGames);

    Trie trie;

    std::vector<Game*> gamesVector(numberOfGames); 
    for(int i = 0; i < numberOfGames; i++){
      trie.insert(&games[i]);

      gamesVector[i] = &games[i];
    }

    vector<Game*> result = trie.autocomplete(prefix, numGamesToRead);
    for(Game* game : result){
      cout << "[" << game->getTitle() << " | ";
      cout << game->getShortDescription() << " | ";
      cout << game->getPopularity() << "]" << endl;
    }
    
    return 0;
}
