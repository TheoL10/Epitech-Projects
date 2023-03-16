/*
** EPITECH PROJECT, 2022
** TEK
** File description:
** process
*/

#include "../hpp/process.hpp"


Process::Process(std::map<std::string, Model>& models, std::map<std::string, ModelAnimation*>& anims)
{
    _models = models;
    _anims = anims;
    _one_time = 0;
}

Process::~Process()
{
}

void  Process::generate_arcade_map()
{
    srand(time(NULL));
    for (int i = 0; i < 12; i++) {
        for (int j = 0; j < 12; j++) {
            if (i > 0 && i < 9 && j > 0 && j < 9 && this->_intMap[i - 1][j] != 2 && this->_intMap[i + 1][j] != 2 && this->_intMap[i][j - 1] != 2 && this->_intMap[i][j + 1] != 2 && this->_intMap[i + 1][j + 1] != 2 && this->_intMap[i - 1][j - 1] != 2 && this->_intMap[i - 1][j + 1] != 2 && this->_intMap[i + 1][j - 1] != 2) {
                this->_intMap[i][j] = rand() % 3;
            } else {
                this->_intMap[i][j] = rand() % 2;
            }
        }
    }
    this->_intMap[1][1] = 5;
    this->_intMap[1][2] = 0;
    this->_intMap[2][1] = 0;

    this->_intMap[1][10] = 5;
    this->_intMap[1][9] = 0;
    this->_intMap[2][10] = 0;

    this->_intMap[10][1] = 5;
    this->_intMap[9][1] = 0;
    this->_intMap[10][2] = 0;

    this->_intMap[10][10] = 5;
    this->_intMap[10][9] = 0;
    this->_intMap[9][10] = 0;

    std::fill(this->_intMap[0].begin(), this->_intMap[0].end(), 2);
    std::fill(this->_intMap[11].begin(), this->_intMap[11].end(), 2);
    for (int i = 0; i < 12; i++) {
        this->_intMap[i][0] = 2;
        this->_intMap[i][11] = 2;
    }
}

void Process::get_story_map(int lvl)
{
    std::string filename = ASSETS_PATH"map" + std::to_string(lvl) + ".txt";

    FILE* input_file = fopen(filename.c_str(), "r");
    if (input_file == NULL) {
        printf("Error opening file\n");
        return;
    }

    unsigned char character = 0;
    int i = 0;
    int j = 0;
    while (!feof(input_file)) {
        if (i == 12) {
            character = getc(input_file);
            i = 0;
            j++;
        }
        if (j == 12)
            break;
        this->_intMap[j][i] = getc(input_file) - 48;
        i++;
    }
    fclose(input_file);
}

void Process::setup_map(std::vector<int> listSkins)
{
    int player_count = 0;
    for (int i = 0; i < 12; i++) {
        for (int j = 0; j < 12; j++) {
            if (this->_intMap[i][j] == 1) {
                this->_finaleMap.emplace_back(new Block3D (_models["box"], (float)i * 1.6, (float)j * 1.6, 0.4f, "box:" + std::to_string(i) + ";" + std::to_string(j)));
            } else if (this->_intMap[i][j] == 2) {
                this->_finaleMap.emplace_back(new Block3D (_models["wall"], (float)i * 1.6, (float)j * 1.6, 0.5f, "wall:" + std::to_string(i) + ";" + std::to_string(j)));
            } else if (this->_intMap[i][j] == 5) {
                std::string pName = "player" + std::to_string(listSkins[player_count]);
                std::string id = "player" + std::to_string(player_count);
                this->_finaleMap.emplace_back(new Character (_models[pName], _anims[pName], (float)i * 1.6, (float)j * 1.6, 0.5f, id));
                player_count++;
            }
        }
    }
    for (int i = -6; i < 18; i++)
        for (int j = -6; j < 18; j++)
            this->_finaleMap.emplace_back(new Block3D (_models["grass"], (float)i * 1.6, (float)j * 1.6, 0.5f, "grass"));
}

std::vector<std::unique_ptr<Entity>>& Process::getMap(int id, std::vector<int> listSkins)
{
    if (id == -1)
        generate_arcade_map();
    else
        get_story_map(id);
    setup_map(listSkins);

    return this->_finaleMap;
}