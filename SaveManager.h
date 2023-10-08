#pragma once

#include <string>
#include "Save.h"

#define SAVE_PATH "saves/"

class SaveManager {
    public:
        void save(int saveNumber) const;
        void load(int saveNumber);
        void newSave();

    [[nodiscard]] Save getCurrentSave() const;

private:
        Save _currentSave;
};
