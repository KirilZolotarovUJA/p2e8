/**
 * @file Professor.cpp
 * @author Kiril Zolotarov (kz000012@red.ujaen.es)
 * @author Roberto Menegassi (ramf0001@red.ujaen.es)
 * @brief Implementation of the Professor class methods,
 * including student management, spell teaching, and evaluation.
 * @version 0.1
 * @date 2026-03-09
 *
 * @copyright Copyright (c) 2026
 *
 */

#include "Professor.h"
#include <iostream>

Professor::Professor(std::string n, std::string s)
    : name(n), subject(s)
{
    std::cout << "Professor " << name << " is ready to teach " << subject << "!\n";
}

Professor::~Professor()
{
    std::cout << "Professor " << name << " has retired.\n";
}

void Professor::addStudent(WizardStudent *student)
{
    students.push_back(student);
    std::cout << student->getName() << " joined Professor " << name << "'s class.\n";
}

void Professor::teachSpell(const Spell &spell)
{
    std::cout << "Professor " << name << " is teaching " << spell.getName() << "!\n";
    for (auto student : students)
    {
        student->learnSpell(spell);
    }
}

void Professor::evaluateStudents() const
{
    std::cout << "\nProfessor " << name << " is evaluating students:\n";
    for (const auto student : students)
    {
        student->showSpells();
    }
}
