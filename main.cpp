#include <iostream>

#include "audio/AudioManager.h"
#include <SFML/Graphics.hpp>
#include <cmath>

using namespace FMOD;

int main2() {
    /*std::cout << "Hello World!\n";

    SaveManager saveManager;
    saveManager.newSave();

    saveManager.getCurrentSave().printSave();
    saveManager.save(2);

    saveManager.load(1);
    saveManager.getCurrentSave().printSave();
*/

    Studio::System *system;
    Studio::System::create(&system);

    system->initialize(512, FMOD_STUDIO_INIT_NORMAL, FMOD_INIT_NORMAL, nullptr);

    Studio::Bank *masterBank;
    //system->loadBankFile("../project/Build/Desktop/Master.bank", FMOD_STUDIO_LOAD_BANK_NORMAL, &masterBank);
    system->loadBankFile("./Master.bank", FMOD_STUDIO_LOAD_BANK_NORMAL, &masterBank);

    Studio::Bank *stringsBank;
    //system->loadBankFile("../project/Build/Desktop/Master.strings.bank", FMOD_STUDIO_LOAD_BANK_NORMAL, &stringsBank);
    system->loadBankFile("./Master.strings.bank", FMOD_STUDIO_LOAD_BANK_NORMAL, &stringsBank);

    sf::RenderWindow window(sf::VideoMode(800, 600), "Ouioui");

    Studio::EventDescription *events[10];
    masterBank->getEventList(events, 10, nullptr);

    for (auto &event: events) {
        if (event != nullptr) {

            char name[256];
            event->getPath(name, 256, nullptr);
            std::cout << name << std::endl;
        }
    }

    Studio::EventDescription *eventDescription;
    system->getEvent("event:/tension", &eventDescription);

    Studio::EventInstance *eventInstance;
    eventDescription->createInstance(&eventInstance);

    if (eventInstance->isValid()) {
        std::cout << "Event instance is valid" << std::endl;
    } else {
        std::cout << "Event instance is not valid" << std::endl;
    }

    while (window.isOpen()) {
        system->update();
        sf::Event event; // NOLINT(*-pro-type-member-init)

        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            } else if (event.type == sf::Event::KeyPressed) {
                if (event.key.code == sf::Keyboard::Escape) {
                    window.close();
                } else if (event.key.code == sf::Keyboard::Space) {
                    system->update();
                } else if (event.key.code == sf::Keyboard::A) {
                    std::cout << "A pressed" << std::endl;
                    eventInstance->start();
                    std::cout << "Event started" << std::endl;
                } else if (event.key.code == sf::Keyboard::P) {
                    std::cout << "P pressed" << std::endl;
                    bool paused;
                    !eventInstance->getPaused(&paused);
                    eventInstance->setPaused(!paused);
                } else if (event.key.code == sf::Keyboard::S) {
                    std::cout << "S pressed" << std::endl;
                    eventInstance->stop(FMOD_STUDIO_STOP_MODE::FMOD_STUDIO_STOP_ALLOWFADEOUT);
                    std::cout << "Event stopped" << std::endl;
                }
            } else if (event.type == sf::Event::MouseWheelScrolled) {
                float volume;
                eventInstance->getVolume(&volume);
                std::cout << "Volume: " << volume << std::endl;
                volume = fmin(1.0f, fmax(0.0f, volume + event.mouseWheelScroll.delta * 0.05f));
                eventInstance->setVolume(volume);
            }
        }

        window.clear();
        window.display();
    }


    eventDescription->releaseAllInstances();
    eventInstance->release();
    eventInstance = nullptr;
    eventDescription = nullptr;

    masterBank->unload();
    masterBank = nullptr;

    stringsBank->unload();
    stringsBank = nullptr;

    system->release();
    system = nullptr;

    return 0;
}

int main() {
    Audio::AudioManager audioManager;
    auto masterBank = audioManager.loadBank("./Master.bank");
    auto stringsBank = audioManager.loadBank("./Master.strings.bank");

    auto eventInstance = audioManager.getEventInstance("event:/tension");

    sf::RenderWindow window(sf::VideoMode(800, 600), "Ouioui");

    while (window.isOpen()) {
        audioManager.update();
        sf::Event event; // NOLINT(*-pro-type-member-init)

        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            } else if (event.type == sf::Event::KeyPressed) {
                if (event.key.code == sf::Keyboard::Escape) {
                    window.close();
                } else if (event.key.code == sf::Keyboard::Space) {
                    audioManager.update();
                } else if (event.key.code == sf::Keyboard::A) {
                    std::cout << "A pressed" << std::endl;
                    eventInstance.start();
                    std::cout << "Event started" << std::endl;
                } else if (event.key.code == sf::Keyboard::P) {
                    std::cout << "P pressed" << std::endl;
                    eventInstance.togglePaused();
                } else if (event.key.code == sf::Keyboard::S) {
                    std::cout << "S pressed" << std::endl;
                    eventInstance.stop(FMOD_STUDIO_STOP_MODE::FMOD_STUDIO_STOP_ALLOWFADEOUT);
                    std::cout << "Event stopped" << std::endl;
                }
            } else if (event.type == sf::Event::MouseWheelScrolled) {
                float volume = eventInstance.getVolume();
                volume = fmin(1.0f, fmax(0.0f, volume + event.mouseWheelScroll.delta * 0.05f));
                std::cout << "Volume: " << volume << std::endl;
                eventInstance.setVolume(volume);
            }
        }

        window.clear();
        window.display();
    }

    return 0;
}