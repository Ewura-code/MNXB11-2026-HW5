#define CATCH_CONFIG_MAIN
#include <catch2/catch_test_macros.hpp>
#include <sstream>
#include "as2.hpp"


TEST_CASE("Knight attack and clone", "[Knight]") {
    homework::Knight knight("Janx");
    knight.setWeapon("sword");
    std::ostringstream oss;
    std::streambuf* oldCoutStreamBuf = std::cout.rdbuf();
    std::cout.rdbuf(oss.rdbuf());
    knight.attack();
    std::cout.rdbuf(oldCoutStreamBuf);
    REQUIRE(oss.str() == "Janx swings a sword\n");
    auto knightClone = knight.clone();
    REQUIRE(knightClone->getName() == "Janx");
}

TEST_CASE("Sorcerer attack and clone", "[Sorcerer]") {
    homework::Sorcerer sorcerer("Jinx");
    sorcerer.setAbility("fireball");
    std::ostringstream oss;
    std::streambuf* oldCoutStreamBuf = std::cout.rdbuf();
    std::cout.rdbuf(oss.rdbuf());
    sorcerer.attack();
    std::cout.rdbuf(oldCoutStreamBuf);
    REQUIRE(oss.str() == "Jinx casts a fireball\n");
    auto sorcClone = sorcerer.clone();
    REQUIRE(sorcClone->getName() == "Jinx");
}

// TEST_CASE("DUEL") {
//   homework::Knight k("JWAZ");
//   k.setWeapon("ZAZ");
//   homework::Sorcerer s("XAXA");
//   s.setAbility("XIXI");
// 
//   homework::Duel<homework::Knight, homework::Sorcerer> d(&k, &s);
//   auto t = d.fight();
//   REQUIRE((t->getName() == "JWAZ" || t->getName() == "XAXA"));
// }


