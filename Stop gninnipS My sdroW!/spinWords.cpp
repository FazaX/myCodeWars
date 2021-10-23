#include <string>
#include <iostream>
#include <vector>
#include <algorithm>

constexpr size_t WORDSLENGTHTOREVERSE = 5;

std::string reverse(const std::string& word){
    std::string result = "";
    if (word.size() >= WORDSLENGTHTOREVERSE){
        std::for_each(
            rbegin(word),
            rend(word),
            [&](auto ch){return result += ch;}
        );
        return result;
    }
    return word;
}

std::vector<std::string> split(std::string str){

    std::string delimiter = " ";
    std::vector<std::string> result{};

    size_t pos = 0;
    while((pos = str.find(delimiter)) != std::string::npos){
        result.push_back(reverse(str.substr(0, pos)) + " ");
        str.erase(0, pos + delimiter.length());
    }
    result.push_back(reverse(str));
    return result;
}

std::string spinWords(const std::string &str)
{
    std::string result = "";
    for (auto word : split(str))
        result += word;
    return result;
}

int main() {

    std::string str = "Welcome my dear friend";
    std::cout << spinWords(str) << std::endl;

}