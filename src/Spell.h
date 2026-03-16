/**
 * @file Spell.h
 * @author Kiril Zolotarov (kz000012@red.ujaen.es)
 * @author Roberto Menegassi (ramf0001@red.ujaen.es)
 * @brief Defines the Spell class representing a magical spell
 * with a name, effect, and power level.
 * @version 0.1
 * @date 2026-03-09
 *
 * @copyright Copyright (c) 2026
 *
 */

#ifndef SPELL_H
#define SPELL_H

#include <string>

/**
 * @brief Represents a magical spell that can be learned and practiced.
 *
 * Each spell has a name, an effect that describes what it does,
 * and a power level that increases when the spell is practiced.
 */
class Spell
{
private:
    std::string name;   ///< Name of the spell.
    std::string effect; ///< Description of the spell's magical effect.
    int powerLevel;     ///< Numerical value representing the strength of the spell.

public:
    /**
     * @brief Construct a new Spell object
     *
     * @param n Name of the spell.
     * @param e Description of the spell's magical effect.
     * @param p Initial power level of the spell.
     */
    Spell(std::string n, std::string e, int p);

    /**
     * @brief Destroy the Spell object
     *
     */
    ~Spell();

    /**
     * @brief Returns the name of the spell.
     *
     * @return std::string Name of the spell.
     */
    std::string getName() const;

    /**
     * @brief Returns the effect produced by the spell.
     *
     * @return std::string Description of the spell's effect.
     */
    std::string getEffect() const;

    /**
     * @brief Returns the current power level of the spell.
     *
     * @return int Current power level.
     */
    int getPowerLevel() const;

    /**
     * @brief Practices the spell, increasing its power level by one.
     *
     * This simulates a student training the spell to improve its effectiveness.
     */
    void practice();
};

#endif