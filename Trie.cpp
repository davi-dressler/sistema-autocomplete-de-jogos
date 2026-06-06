#include <algorithm>
#include <iostream>
#include <vector>
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

        // std::cout << "teste 2" << std::endl;
    }

    // std::cout << "teste 3" << std::endl;
    current_node->isEndOfTitle = true;
    current_node->game = game;
    // std::cout << "teste 4" << std::endl;

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

std::vector<Game*> Trie::merge(std::vector<Game*> game1, std::vector<Game*> game2){
   int n = game1.size();
   int m = game2.size();
   int i = 0;
   int j = 0;
   std::vector<Game*> merged(m + n);
   // falta o desempate
   while(i < n && j < m){
       if(game1[i]->popularity >= game2[j]->popularity){
           merged[i + j] = game1[i];
           i++;
       } else {
           merged[i + j] = game2[j];
           j++;
       }
   }
   while (i < n) {
       merged[i + j] = game1[i];
       i++;
   }

   while (j < m) {
       merged[i + j] = game2[j];
       j++;
   }
   return merged;
}
std::vector<Game*> Trie::mergeSort(std::vector<Game*> games){
    if(games.size() <= 1){
        return games;
    }
    int size = games.size();
    int mid = size/2;
    std::vector<Game*> left(games.begin(), games.begin() + mid);
    std::vector<Game*> right(games.begin() + mid, games.end());
    left = mergeSort(left);
    right = mergeSort(right);

    
    return merge(left, right);
}

void Trie::sortResults(std::vector<Game*>& games){    
    games = mergeSort(games);
}


void Trie::dfs(TrieNode* node, std::vector<Game*>& games){
    if(node == nullptr){
        return;
    }
    if(!node->isEndOfTitle){
        for(int i = 0; i < ALPHABET_SIZE; i++){
            if(node->children[i] == nullptr){
                continue;
            }

            dfs(node->children[i], games);
        }
    }else{
        games.push_back(node->game);
    }
}

std::vector<Game*> Trie::autocomplete(std::string prefix, int k){
    std::vector<Game*> games;
    if(k <= 0){
        return games;
    }
    TrieNode* dfsStart = nullptr;
    TrieNode* current_node = this->root;
    for(char ch : prefix){
        int childIdx;
        if(ch >= 'a' && ch <= 'z'){
            childIdx = ch - 'a';
        }
        else if(ch >= '0' && ch <= '9'){
            childIdx = ch - '0' + 26;
        }else {
            continue;
        }
        dfsStart = current_node->children[childIdx];
        current_node = current_node->children[childIdx];
    }
    
    dfs(dfsStart, games);
    sortResults(games);
    int outSize = std::min(k, int(games.size()));
    std::vector result(games.begin(), games.begin() + outSize);
    
    return result;
}
