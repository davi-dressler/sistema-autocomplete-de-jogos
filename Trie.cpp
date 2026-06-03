#include <iostream>
#include "Trie.hpp"

using namespace std;

TrieNode::TrieNode(){
    for(int i = 0; i < ALPHABET_SIZE; i++){
        this->children[i] = nullptr;
    }

    this->isEndOfTitle = false;
    this->game = nullptr;
}

TrieNode::~TrieNode(){
    for(int i = 0; i < ALPHABET_SIZE; i++){
        if(this->children[i] != nullptr){
            delete this->children[i];
        }
    }
}

Trie::Trie(){
    this->root = new TrieNode();
}

Trie::~Trie(){
    delete this->root;
}

std::string Trie::toSearchKey(std::string text) {
    std::string key = "";

    for(char ch : text){

        if (ch != ' '){
            key += tolower(ch);
        }

    }
    return key;
}

bool Trie::insert(Game* game){
    //A função ira operar usando o index do array chlidren do TrieNode
    //onde "a" tem índice 0 e "9" tem índice 35
    if(game == nullptr){
        return false;
    }

    TrieNode* current_node = this->root;

    std::string key = toSearchKey(game->title);
    
    for(char ch : key){
        int idx = 0;

        if(ch >= 'a' && ch <= 'z'){
            idx = ch - 'a';
        }
        else if(ch >= '0' && ch <= '9'){
            idx = ch - '0' + 26;
        }
        else{
            continue;
        }
        
        if(current_node->children[idx] == nullptr){
            current_node->children[idx] = new TrieNode();
        }

        current_node = current_node->children[idx];
    }

    current_node->isEndOfTitle = true;
    current_node->game = game;

    return true;
}

bool Trie::contains(std:: string title){
    std::string key = toSearchKey(title);

    TrieNode* current_node = this->root;

    for(char ch : key){
        int idx = 0;

        if(ch >= 'a' && ch <= 'z'){
            idx = ch - 'a';
        }
        else if(ch >= '0' && ch <= '9'){
            idx = ch - '0' + 26;
        }
        else{
            continue;
        }
        
        if(current_node->children[idx] == nullptr){
            return false;
        }

        current_node = current_node->children[idx];
    }

    if(current_node->isEndOfTitle == true){
        return true;
    }
    else{
        return false;
    }
}

void Trie::sortResults(std::vector<Game*>& games){

}

std::vector<Game*> Trie::autocomplete(std::string prefix, int k){

}