#pragma once

class Save {
private:
    int _currentArea = 0;
    int _currentRoom = 0;
    float _x = 0.0;
    float _y = 0.0;
    float _health = 100.0;
    int _bosses = 0;
    int _weapons = 0;
    int _abilities = 0;
    int _doors = 0;
    int _cinematics = 0;
    int _chests = 0;
    int _secrets = 0;
    int _dialogs = 0;
    int _events = 0;
public:
    Save() = default;
    Save(int currentArea, int currentRoom, float health, int bosses, int weapons, int abilities, int doors,
         int cinematics, int chests, int secrets, int dialogs, int events);

    [[nodiscard]] int getCurrentArea() const;

    void setCurrentArea(int currentArea);

    [[nodiscard]] int getCurrentRoom() const;

    void setCurrentRoom(int currentRoom);

    [[nodiscard]] float getX() const;

    void setX(float x);

    [[nodiscard]] float getY() const;

    void setY(float y);

    [[nodiscard]] float getHealth() const;

    void setHealth(float health);

    [[nodiscard]] int getBosses() const;

    void setBosses(int bosses);

    [[nodiscard]] int getWeapons() const;

    void setWeapons(int weapons);

    [[nodiscard]] int getAbilities() const;

    void setAbilities(int abilities);

    [[nodiscard]] int getDoors() const;

    void setDoors(int doors);

    [[nodiscard]] int getCinematics() const;

    void setCinematics(int cinematics);

    [[nodiscard]] int getChests() const;

    void setChests(int chests);

    [[nodiscard]] int getSecrets() const;

    void setSecrets(int secrets);

    [[nodiscard]] int getDialogs() const;

    void setDialogs(int dialogs);

    [[nodiscard]] int getEvents() const;

    void setEvents(int events);

    void printSave() const;
};
