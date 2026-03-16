/**
 * @file Professor.h
 * @author Kiril Zolotarov (kz000012@red.ujaen.es)
 * @author Roberto Menegassi (ramf0001@red.ujaen.es)
 * @brief Defines the Professor class responsible for managing
 * wizard students and teaching spells in a specific subject.
 * @version 0.1
 * @date 2026-03-09
 *
 * @copyright Copyright (c) 2026
 *
 */

#ifndef PROFESSOR_H
#define PROFESSOR_H

#include <string>
#include <vector>
#include "WizardStudent.h"

/**
 * @brief Represents a professor in the wizarding school.
 *
 * A Professor teaches a specific subject and manages a list
 * of WizardStudent objects enrolled in their class. The professor
 * can add students, teach spells to them, and evaluate their progress.
 */
class Professor
{
private:
    std::string name;                      ///< Name of the professor.
    std::string subject;                   ///< Subject that the professor teaches.
    std::vector<WizardStudent *> students; ///< List of students taught by the professor.

public:
    /**
     * @brief Construct a new Professor object
     *
     * @param n Name of the professor.
     * @param s Subject taught by the professor.
     */
    Professor(std::string n, std::string s);

    /**
     * @brief Destroy the Professor object
     *
     */
    ~Professor();

    /**
     * @brief Adds a student to the professor's class.
     *
     * @param student Pointer to the WizardStudent that will be added.
     */
    void addStudent(WizardStudent *student);

    /**
     * @brief Teaches a spell to all students in the class.
     *
     * The professor demonstrates a spell and every student learns it.
     *
     * @param spell Reference to the Spell object that will be taught.
     */
    void teachSpell(const Spell &spell);

    /**
     * @brief Evaluates all students by displaying the spells they know
     * and their current power levels.
     */
    void evaluateStudents() const;
};

#endif
