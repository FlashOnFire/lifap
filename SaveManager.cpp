#include "SaveManager.h"
#include <fstream>

#include <iostream>

void SaveManager::save(int saveNumber) const {
    std::string path = SAVE_PATH + std::string("save") + std::to_string(saveNumber) + ".dat";

    std::ofstream outfile;
    outfile.open(path, std::ios::out);

    outfile << "currentArea=" << _currentSave.getCurrentArea() << std::endl;
    outfile << "currentRoom=" << _currentSave.getCurrentRoom() << std::endl;
    outfile << "x=" << _currentSave.getX() << std::endl;
    outfile << "y=" << _currentSave.getY() << std::endl;
    outfile << "health=" << _currentSave.getHealth() << std::endl;
    outfile << "bosses=" << _currentSave.getBosses() << std::endl;
    outfile << "weapons=" << _currentSave.getWeapons() << std::endl;
    outfile << "abilities=" << _currentSave.getAbilities() << std::endl;
    outfile << "doors=" << _currentSave.getDoors() << std::endl;
    outfile << "cinematics=" << _currentSave.getCinematics() << std::endl;
    outfile << "chests=" << _currentSave.getChests() << std::endl;
    outfile << "secrets=" << _currentSave.getSecrets() << std::endl;
    outfile << "dialogs=" << _currentSave.getDialogs() << std::endl;
    outfile << "events=" << _currentSave.getEvents() << std::endl;

    outfile.flush();
    outfile.close();
}

void SaveManager::load(int saveNumber) {
    std::string path = SAVE_PATH + std::string("save") + std::to_string(saveNumber) + ".dat";

    std::ifstream infile;
    infile.open(path, std::ios::in);

    Save save;

    while (!infile.eof()) {
        std::string line;
        std::getline(infile, line);

        if (line.find('=') != std::string::npos) {
            std::string key = line.substr(0, line.find('='));
            if (key == "currentArea") {
                save.setCurrentArea(std::stoi(line.substr(line.find('=') + 1)));
            } else if (key == "currentRoom") {
                save.setCurrentRoom(std::stoi(line.substr(line.find('=') + 1)));
            } else if (key == "x") {
                save.setX(std::stof(line.substr(line.find('=') + 1)));
            } else if (key == "y") {
                save.setY(std::stof(line.substr(line.find('=') + 1)));
            } else if (key == "health") {
                save.setHealth(std::stof(line.substr(line.find('=') + 1)));
            } else if (key == "bosses") {
                save.setBosses(std::stoi(line.substr(line.find('=') + 1)));
            } else if (key == "weapons") {
                save.setWeapons(std::stoi(line.substr(line.find('=') + 1)));
            } else if (key == "abilities") {
                save.setAbilities(std::stoi(line.substr(line.find('=') + 1)));
            } else if (key == "doors") {
                save.setDoors(std::stoi(line.substr(line.find('=') + 1)));
            } else if (key == "cinematics") {
                save.setCinematics(std::stoi(line.substr(line.find('=') + 1)));
            } else if (key == "chests") {
                save.setChests(std::stoi(line.substr(line.find('=') + 1)));
            } else if (key == "secrets") {
                save.setSecrets(std::stoi(line.substr(line.find('=') + 1)));
            } else if (key == "dialogs") {
                save.setDialogs(std::stoi(line.substr(line.find('=') + 1)));
            } else if (key == "events") {
                save.setEvents(std::stoi(line.substr(line.find('=') + 1)));
            }

            _currentSave = save;
        }
    }
}

void SaveManager::newSave() {
    _currentSave = Save();
}

Save SaveManager::getCurrentSave() const {
    return _currentSave;
}
