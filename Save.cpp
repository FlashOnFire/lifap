#include "Save.h"

#include <iostream>

Save::Save(int currentArea, int currentRoom, float health, int bosses, int weapons, int abilities, int doors,
           int cinematics, int chests, int secrets, int dialogs, int events) {
    _currentArea = currentArea;
    _currentRoom = currentRoom;
    _health = health;
    _bosses = bosses;
    _weapons = weapons;
    _abilities = abilities;
    _doors = doors;
    _cinematics = cinematics;
    _chests = chests;
    _secrets = secrets;
    _dialogs = dialogs;
    _events = events;
}

int Save::getCurrentArea() const {
    return _currentArea;
}

void Save::setCurrentArea(int currentArea) {
    _currentArea = currentArea;
}

int Save::getCurrentRoom() const {
    return _currentRoom;
}

void Save::setCurrentRoom(int currentRoom) {
    _currentRoom = currentRoom;
}

float Save::getX() const {
    return _x;
}

void Save::setX(float x) {
    _x = x;
}

float Save::getY() const {
    return _y;
}

void Save::setY(float y) {
    _y = y;
}

float Save::getHealth() const {
    return _health;
}

void Save::setHealth(float health) {
    _health = health;
}

int Save::getBosses() const {
    return _bosses;
}

void Save::setBosses(int bosses) {
    _bosses = bosses;
}

int Save::getWeapons() const {
    return _weapons;
}

void Save::setWeapons(int weapons) {
    _weapons = weapons;
}

int Save::getAbilities() const {
    return _abilities;
}

void Save::setAbilities(int abilities) {
    _abilities = abilities;
}

int Save::getDoors() const {
    return _doors;
}

void Save::setDoors(int doors) {
    _doors = doors;
}

int Save::getCinematics() const {
    return _cinematics;
}

void Save::setCinematics(int cinematics) {
    _cinematics = cinematics;
}

int Save::getChests() const {
    return _chests;
}

void Save::setChests(int chests) {
    _chests = chests;
}

int Save::getSecrets() const {
    return _secrets;
}

void Save::setSecrets(int secrets) {
    _secrets = secrets;
}

int Save::getDialogs() const {
    return _dialogs;
}

void Save::setDialogs(int dialogs) {
    _dialogs = dialogs;
}

int Save::getEvents() const {
    return _events;
}

void Save::setEvents(int events) {
    _events = events;
};

void Save::printSave() const {
    std::cout << "currentArea=" << _currentArea << std::endl;
    std::cout << "currentRoom=" << _currentRoom << std::endl;
    std::cout << "x=" << _x << std::endl;
    std::cout << "y=" << _y << std::endl;
    std::cout << "health=" << _health << std::endl;
    std::cout << "bosses=" << _bosses << std::endl;
    std::cout << "weapons=" << _weapons << std::endl;
    std::cout << "abilities=" << _abilities << std::endl;
    std::cout << "doors=" << _doors << std::endl;
    std::cout << "cinematics=" << _cinematics << std::endl;
    std::cout << "chests=" << _chests << std::endl;
    std::cout << "secrets=" << _secrets << std::endl;
    std::cout << "dialogs=" << _dialogs << std::endl;
    std::cout << "events=" << _events << std::endl;
}
