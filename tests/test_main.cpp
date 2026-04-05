/**
 * @file test_main.h
 * @author Kiril Zolotarov (kz000012@red.ujaen.es)
 * @author Roberto Menegassi (ramf0001@red.ujaen.es)
 * @brief Unit tests for validating the run_simulation function's behavior
 * including standard logic, edge cases, and error handling.
 * @version 0.1
 * @date 2026-03-09
 *
 * @copyright Copyright (c) 2026
 *
 */

#include <gtest/gtest.h>
#include "../src/core_logic.h"

#include <iostream>
#include <sstream>
#include <string>

/**
 * @brief Test fixture for testing the interactive run_simulation functionality.
 *
 * This test suite redirects the standard input and standard output streams
 * (std::cin and std::cout) to internal string buffers. This allows the testing
 * framework to programmatically inject CLI inputs and validate console outputs.
 */
class SimulationTest : public ::testing::Test
{
protected:
    std::stringstream test_in;  ///< Stringstream to simulate standard input.
    std::stringstream test_out; ///< Stringstream to capture standard output.
    std::streambuf *orig_in;    ///< Pointer to the original standard input buffer.
    std::streambuf *orig_out;   ///< Pointer to the original standard output buffer.

    /**
     * @brief Prepares the test environment before each test case runs.
     *
     * Saves the original std::cin and std::cout underlying buffer pointers and
     * redirects the standard streams to point to the local stringstream buffers.
     */
    void SetUp() override
    {
        // Save the original buffer streams
        orig_in = std::cin.rdbuf();
        orig_out = std::cout.rdbuf();

        // Redirect standard input and standard output to stringstreams
        std::cin.rdbuf(test_in.rdbuf());
        std::cout.rdbuf(test_out.rdbuf());
    }

    /**
     * @brief Cleans up the test environment after each test case completes.
     *
     * Restores the standard I/O streams back to their original state to prevent
     * console redirection side effects on subsequent tests or framework outputs.
     */
    void TearDown() override
    {
        // Restore the original buffer streams to avoid breaking other tests
        std::cin.rdbuf(orig_in);
        std::cout.rdbuf(orig_out);
    }
};

/**
 * @brief Tests the standard execution flow of the simulation (Happy Path).
 *
 * Validates that the system correctly processes a standard sequence: adding a
 * new student, teaching them a spell, making them practice, and evaluating
 * them, all without encountering any empty list logic warnings or crashes.
 */
TEST_F(SimulationTest, NormalExecutionAddsStudentAndTeaches)
{
    // Simulate inputs:
    // 1 -> Add student
    // Harry -> Name
    // Gryffindor -> House
    // 2 -> Teach spell
    // 3 -> Practice & Evaluate
    // 4 -> Exit
    test_in << "1\nHarry\nGryffindor\n2\n3\n4\n";

    run_simulation();

    std::string output = test_out.str();

    // Validate the prompts for adding a student appeared
    EXPECT_NE(output.find("Enter student name: "), std::string::npos);
    EXPECT_NE(output.find("Enter house name: "), std::string::npos);

    // Validate the system didn't trigger the "empty list" error warnings
    EXPECT_EQ(output.find("No students to teach!\n"), std::string::npos);
    EXPECT_EQ(output.find("No students to practice!\n"), std::string::npos);
}

/**
 * @brief Tests the edge case of encountering an End-Of-File (EOF) or closed
 * stream input.
 *
 * Validates that an empty input stream triggers safe_read to fail gracefully,
 * effectively preventing infinite loops during standard input reads and forcing
 * the simulation function to clean up and exit.
 */
TEST_F(SimulationTest, EdgeCaseEofExitsGracefully)
{
    // Sending an empty input stream. safe_read should fail and return false,
    // preventing an infinite loop and immediately exiting without crashing.
    test_in.str("");

    run_simulation();

    std::string output = test_out.str();

    // Validate that no actions were taken inside the loop
    EXPECT_EQ(output.find("Enter student name: "), std::string::npos);
    EXPECT_EQ(output.find("Invalid option!\n"), std::string::npos);
}

/**
 * @brief Tests the error handling mechanisms for invalid options and empty list
 * states.
 *
 * Validates that the system correctly displays an "Invalid option!" message for
 * unrecognized menu inputs. Also verifies that trying to execute teaching or
 * practicing actions while the student list is empty produces correct warnings.
 */
TEST_F(SimulationTest, ErrorCaseInvalidOptionsAndEmptyOperations)
{
    // Simulate inputs:
    // 99 -> Invalid option
    // 2 -> Teach spell (but list is empty)
    // 3 -> Practice & Evaluate (but list is empty)
    // 4 -> Exit
    test_in << "99\n2\n3\n4\n";

    run_simulation();

    std::string output = test_out.str();

    // Validate that the invalid option was caught by the default case
    EXPECT_NE(output.find("Invalid option!\n"), std::string::npos);

    // Validate that edge cases inside cases 2 and 3 properly guard empty vectors
    EXPECT_NE(output.find("No students to teach!\n"), std::string::npos);
    EXPECT_NE(output.find("No students to practice!\n"), std::string::npos);
}