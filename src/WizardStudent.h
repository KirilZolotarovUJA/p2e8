/**
 * @file WizardStudent.h
 * @author Kiril Zolotarov (kz000012@red.ujaen.es)
 * @author Roberto Menegassi (ramf0001@red.ujaen.es)
 * @brief Defines the WizardStudent class representing a student
 * who can learn, practice, and display magical spells.
 * @version 0.1
 * @date 2026-03-09
 *
 * @copyright Copyright (c) 2026
 *
 */

#ifndef WIZARD_STUDENT_H
#define WIZARD_STUDENT_H

#include <string>
#include <vector>
#include "Spell.h"

/**
 * @brief Represents a wizard student enrolled in the school.
 *
 * A WizardStudent has a name, belongs to a house, and has a school year.
 * Students can learn spells, practice them, and display the spells
 * they currently know.
 */
class WizardStudent
{
private:
    std::string name;          ///< Name of the student.
    std::string house;         ///< House to which the student belongs (e.g., Gryffindor).
    int year;                  ///< Academic year of the student in the wizarding school.
    std::vector<Spell> spells; ///< Collection of spells that the student has learned.

public:
    /**
     * @brief Construct a new Wizard Student object
     *
     * @param n Name of the student.
     * @param h House to which the student belongs.
     * @param y Academic year of the student.
     */
    WizardStudent(std::string n, std::string h, int y);

    /**
     * @brief Destroy the Wizard Student object
     *
     */
    ~WizardStudent();

    /**
     * @brief Allows the student to learn a new spell.
     *
     * The spell is added to the student's list of known spells.
     *
     * @param spell Reference to the spell that will be learned.
     */
    void learnSpell(const Spell &spell);

    /**
     * @brief Practices all spells known by the student.
     *
     * Each spell increases its power level when practiced.
     */
    void practiceSpells();

    /**
     * @brief Displays all spells known by the student
     * along with their current power levels.
     */
    void showSpells() const;

    /**
     * @brief Returns the name of the wizard student.
     *
     * @return std::string Name of the student.
     */
    std::string getName() const;
};

#endif
