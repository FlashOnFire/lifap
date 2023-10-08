#include <iostream>
#include "SaveManager.h"

#include "BossEnum.h"

int main() {
    std::cout << "Hello World!\n";

    SaveManager saveManager;
    saveManager.newSave();

    saveManager.getCurrentSave().printSave();
    saveManager.save(2);

    saveManager.load(1);
    saveManager.getCurrentSave().printSave();

    return 0;
}