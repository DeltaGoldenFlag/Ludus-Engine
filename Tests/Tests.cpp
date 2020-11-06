/* ========================================================================= */
/**
 * @author          David Wong Cascante
 * @file            Tests.cpp
 * @par             Ludus Engine
 * @date            11/05/2020
 * 
 * @brief
 * Runs all the tests for the entire engine???
 * We'll see if we split this up.
 **/
/* ========================================================================= */

/* ========================================================================= */
/* Includes */
/* ========================================================================= */
#include <memory>
#include "Ludus/Precompile.hpp"
#define CATCH_CONFIG_MAIN
#include "catch2.hpp"

#include "Ludus/System/Node.hpp"

TEST_CASE("Testing simple parent-child relationships", "[Node]")
{
    using Ludus::Node;
    std::unique_ptr<Node> node = std::make_unique<Node>("Parent");
    std::unique_ptr<Node>child = std::make_unique<Node>("Child");
    node->AddChild(child);
}