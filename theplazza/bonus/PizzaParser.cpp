/*
** EPITECH PROJECT, 2022
** TEK
** File description:
** PizzaParser
*/

#include "hpp/PizzaParser.hpp"

PizzaParser::PizzaParser()
{

}

PizzaParser::~PizzaParser()
{
}

std::vector<std::string> PizzaParser::str_to_str_array(std::string str){
    std::vector<std::string> words;
    if (str == "status" || str == "Status") {
        printf("Pizza history:\n");
        for (int i = 0; i < this->_pizza_queue.size(); i++) {
            printf("%s %s\n", this->_pizza_queue[i].get_type().c_str(), this->_pizza_queue[i].get_size().c_str());
        }
    }
    std::string word = "";
    int i = 0;
    for (auto x : str)
    {
        if (x == ' ')
        {
            words.push_back(word);
            word = "";
        }
        else {
            word = word + x;
        }
        if (words.size() == 2) {
            i++;
            break;
        }
        i++;
    }
    words.push_back(str.substr(i));
    return (words);
}
int PizzaParser::isNumber(std::string str)
{
    for (auto x : str)
    {
        if (x < '0' || x > '9')
            return (0);
    }
    return (1);
}

int PizzaParser::check_content(std::vector<std::string> str_array)
{
    if (str_array.size() != 3)
        return (84);
    if (str_array[0] != "Regina" && str_array[0] != "Margarita" && str_array[0] != "Americana" && str_array[0] != "Fantasia")
        return (84);
    if (str_array[1] != "S" && str_array[1] != "M" && str_array[1] != "L" && str_array[1] != "XL" && str_array[1] != "XXL")
        return (84);
    if (str_array[2][0] != 'x' || isNumber(str_array[2].substr(1)) == 0 || stoi(str_array[2].substr(1)) <= 0)
        return (84);
    for (int i = 0; i < stoi(str_array[2].substr(1)); i++)
        this->_pizza_queue.push_back(Pizza(str_array[0], str_array[1]));
    // printf("Pizza queue:\n");
    // for (int i = 0; i < this->_pizza_queue.size(); i++) {
    //     printf("%s %s\n", this->_pizza_queue[i].get_type().c_str(), this->_pizza_queue[i].get_size().c_str());
    // }
    return (0);
}