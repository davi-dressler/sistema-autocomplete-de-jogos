#ifndef TRIE_HPP
#define TRIE_HPP

#include "Game.hpp"
#include <vector>
#include <string>

const int ALPHABET_SIZE = 36;


class TrieNode {

public:

    TrieNode* children[ALPHABET_SIZE];
    bool isEndOfTitle;
    Game* game;

    TrieNode();
    ~TrieNode();
};


class Trie {

private:

    TrieNode* root;
    std::vector<Game*> merge(std::vector<Game*> game1, std::vector<Game*> game2);
    std::vector<Game*> mergeSort(std::vector<Game*> games);

public:

    Trie();
    ~Trie();

    bool insert(Game* game);
    bool contains(std::string title);

    std::vector<Game*> autocomplete(std::string prefix, int k);

    std::string toSearchKey(std::string text);
    void sortResults(std::vector<Game*>& games);

    // Outros métodos auxiliares, se necessário
};

#endif
