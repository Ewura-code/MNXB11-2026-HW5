#pragma once

#include <string>
#include <iostream>
#include <random>
#include <memory>
#include <sstream>

namespace homework {

  // Random number generator setup
  inline std::random_device rd;
  inline std::mt19937 gen(rd()); 
  inline std::uniform_real_distribution<double> dist(0.0, 1.0);
  // to generate a random number between 0 and 1, use auto random_number = dist(gen);

  // Base class for entities
  // Has a implemented method getName()
  // Has a pure virtual method attack()
  // Has a pure virtual method clone() to support polymorphic copying
  // TO DO: Nothing, everything is implemented for you
  struct Entity {
      explicit Entity(const std::string name) : name{std::move(name)} {}
      virtual ~Entity() = default;
      virtual void attack() const = 0;
      std::string getName() const {
        return name;
      }

      virtual std::unique_ptr<Entity> clone() const = 0;
    protected:
      std::string name;
  };
  
  ///////// EXERCISES BEGIN BELOW /////////




  // as 2.1
  // Derived class Knight
  class Knight : public Entity {
  public:
      explicit Knight(const std::string name, std::string weapon = "sword");
      void attack() const override;
      std::unique_ptr<Entity> clone() const override;
      void setWeapon(const std::string& new_weapon);
  private:
      std::string weapon;
  };

  // as 2.2
  // Derived class Sorcerer
  class Sorcerer : public Entity {
  public:
      explicit Sorcerer(const std::string name, std::string ability = "magic");
      void attack() const override;
      std::unique_ptr<Entity> clone() const override;
      void setAbility(const std::string& new_ability);
  private:
      std::string ability;
  };


  /////////


  // NOT MANDATORY (Stretch goal): as 2.3. You can pass assignment without doing this one. 
  // If you want to see how templates work, you can implement this one.
  // Duel class template
  // TO DO: create a struct/class called Duel that is templated by two types (T1 and T2)
  // The constructor should take two pointers (T1* and T2*)
  // The fight() method should:
  // - call attack() on both entities
  // - randomly select one of the two entities as the winner (use the random number generator above)
  // - print to std::cout "<name> wins the duel!\n"
  // - return a std::unique_ptr<Entity> to the winner (use clone() to copy the object)

} // namespace homework

