#include "as2.hpp"
#include <iostream>
namespace homework {
    // --- Exercise 2.1: Knight Implementation ---
    Knight::Knight(const std::string name, std::string weapon)
        : Entity(std::move(name)), weapon(std::move(weapon)) {}

    void Knight::attack() const {
        std::cout << name << " swings a " << weapon << "\n";
    }

    std::unique_ptr<Entity> Knight::clone() const {
        return std::make_unique<Knight>(*this);
    }

    void Knight::setWeapon(const std::string& new_weapon) {
        weapon = new_weapon;
    }


    // --- Exercise 2.2: Sorcerer Implementation ---
    Sorcerer::Sorcerer(const std::string name, std::string ability)
        : Entity(std::move(name)), ability(std::move(ability)) {}

    void Sorcerer::attack() const {
        std::cout << name << " casts " << ability << "\n";
    }

    std::unique_ptr<Entity> Sorcerer::clone() const {
        return std::make_unique<Sorcerer>(*this);
    }

    void Sorcerer::setAbility(const std::string& new_ability) {
        ability = new_ability;
    }

} // namespace homework

