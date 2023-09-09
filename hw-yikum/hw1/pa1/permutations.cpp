#include <iostream>
#include <vector>


using namespace std;

//Function that counts the length of a string
int length(std::string out)
{
    int count = 0;

    int index = 0;

    while (out[index] != '\0') {
        count++;
        index++;
    }

    return count;

}

//Function to check whether a string has repeating characters
bool isRepeated(const std::string& word) {
    int len = length(word);

    for (int i = 0; i < len; ++i) {
        for (int j = i + 1; j < len; ++j) {
            if (word[i] == word[j])  return true;
        }
    }
    return false;
}

//Function to check if letter within specific location equals given letter
bool repetition(char letter, const std::string& word) {
    int len = length(word);
    for (int i = 0; i < len; ++i) {
        if (word[i] == letter) {
            return true;
        } 
    }
    return false;
}

//Function that inserts a letter at specific index 
void insertCharacter(std::string& word, char letter, int iter) {
    int len = length(word);
    word = word + letter;

    //Shift letters one position to the right
    for (int i = len; i > iter; --i) {
        word[i] = word[i - 1];
    }

    //Set letter at empty spot
    word[iter] = letter;
}

//Function responsible for permutation of words with nonrepeating letters 
void helper1(std::string word, std::string prefix, int iter, vector<std::string>& strings) {
    
    //Base case
    int len = length(word);

    if (iter == len) {
        strings.push_back(prefix);
        return;
    }
    
    //Recursive case
    for (int i = 0; i < len; ++i) {
        if ((repetition(word[i], prefix) == false)) {
            helper1(word, prefix + word[i], iter + 1, strings);
        }
    }

}

//Function responsible for permutation of words with repeating letters
void helper2(std::string word, std::string prefix, int iter, vector<std::string>& strings) {

    //Base case
    int len = length(word);
    int startingLength = length(prefix);

    if (iter == len) {
        strings.push_back(prefix);
        return;
    }

    //Recursive case
    for (int i = 0; i < startingLength + 1; ++i) {
        //Create a new string to store updated string
        std::string newPrefix = prefix;
        insertCharacter(newPrefix, word[iter], i);
        helper2(word, newPrefix, iter + 1, strings);
    }

}

void permutations(std::string in) {

    vector<std::string> result;

    //Check if string has repeating characters
    if (!(isRepeated(in))) {

        helper1(in, "", 0, result);
        int size1 = result.size();

        for (int i = 0; i < size1; ++i) {
            std::cout << result[i] << std::endl;
        }
    }

    else {
        helper2(in, "", 0, result);
        int size2 = result.size();
        
        for (int i = 0; i < size2; ++i) {
            std::cout << result[i] << std::endl;
        }
    }

}
    


