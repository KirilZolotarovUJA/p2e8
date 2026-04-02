/**
 * @file core_logic.cpp
 * @author Kiril Zolotarov (kz000012@red.ujaen.es)
 * @author Roberto Menegassi (ramf0001@red.ujaen.es)
 * @brief Implements the main wizarding school simulation logic and menu-driven
 * user interaction.
 * @version 0.1
 * @date 2026-03-09
 *
 * @copyright Copyright (c) 2026
 *
 */

#include "core_logic.h"
#include "Spell.h"
#include "WizardStudent.h"
#include "Professor.h"
#include <iostream>

void displayMenu()
{
    std::cout << "\n=== Wizarding School Menu ===\n";
    std::cout << "1. Create new student\n";
    std::cout << "2. Teach new spell\n";
    std::cout << "3. Practice spells\n";
    std::cout << "4. Exit\n";
    std::cout << "Enter your choice: ";
}

void run_simulation()
{
    Professor mcgonagall("McGonagall", "Transfiguration");
    std::vector<WizardStudent *> allStudents;

    int choice;
    bool running = true;

    while (running)
    {
        displayMenu();
        std::cin >> choice;

        switch (choice)
        {
        case 1:
        {
            std::string name, house;
            std::cout << "Enter student name: ";
            std::cin >> name;
            std::cout << "Enter house name: ";
            std::cin >> house;

            WizardStudent *student = new WizardStudent(name, house, 1);
            allStudents.push_back(student);
            mcgonagall.addStudent(student);
            break;
        }
        case 2:
        {
            if (allStudents.empty())
            {
                std::cout << "No students to teach!\n";
                break;
            }

            Spell spell("Wingardium Leviosa", "Levitation", 1);
            mcgonagall.teachSpell(spell);
            break;
        }
        case 3:
        {
            if (allStudents.empty())
            {
                std::cout << "No students to practice!\n";
                break;
            }

            for (auto student : allStudents)
            {
                student->practiceSpells();
            }
            mcgonagall.evaluateStudents();
            break;
        }
        case 4:
        {
            running = false;
            break;
        }
        default:
        {
            std::cout << "Invalid option!\n";
        }
        }
    }

    // Cleanup
    for (auto student : allStudents)
    {
        delete student;
    }
}
