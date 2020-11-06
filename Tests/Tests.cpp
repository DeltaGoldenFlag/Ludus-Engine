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

#include "Ludus/Precompile.hpp"
#include "Ludus/System/Node.hpp"
#include <memory>

#define CATCH_CONFIG_MAIN
#include "catch2.hpp"

TEST_CASE("Tests the name setting", "[Node]")
{
    using Ludus::Node;
    Node node("Parent");
    Node child("Child");
    REQUIRE(node.GetName() == "Parent");
    REQUIRE(child.GetName() == "Child");
}

TEST_CASE("Testing the parent child relationships")
{
    using Ludus::Node;
    SECTION("The simplest test")
    {
        Node parent("Parent");
        Node child("Child");
        
        parent.AddChild(child);
        REQUIRE(child.GetParent().GetName() == parent.GetName());
    }

    SECTION("Doing more tree traversal")
    {
        Node parent("Parent");
        for(int i = 0; i < 3; ++i)
        {
            Node child("Child-" + std::to_string(i));
            for(int j = 0; j < 3; ++j)
            {
                Node grandChild(("Grand-Child-" + std::to_string(i)));
                child.AddChild(grandChild);
                REQUIRE(grandChild.GetParent().GetName() == child.GetName());
            }
            parent.AddChild(child);
            REQUIRE(child.GetParent().GetName() == parent.GetName());
        }
    }
}

TEST_CASE("Traversing using an index.")
{
    using Ludus::Node;
    SECTION("Traversing the node using indices")
    {
        std::string names[] = { "Child1", "Child2", "Child3" };
        Node parent("Parent");
        const Node &ref = parent;
        for(unsigned i = 0; i < sizeof(names) / sizeof(names[0]); ++i)
        {
            Node child(names[i]);
            parent.AddChild(child);
        }
        for(unsigned i = 0; i < sizeof(names) / sizeof(names[0]); ++i)
        {
            REQUIRE(ref.At(i).GetName() == names[i]);
            REQUIRE(ref[i].GetName() == names[i]);
            REQUIRE(parent.At(i).GetName() == names[i]);
            REQUIRE(parent[i].GetName() == names[i]);
        }
    }

    SECTION("Traversing the node using names")
    {
        std::string names[] = { "Child1", "Child2", "Child3" };
        Node parent("Parent");
        const Node &ref = parent;
        for(unsigned i = 0; i < sizeof(names) / sizeof(names[0]); ++i)
        {
            Node child(names[i]);
            parent.AddChild(child);
        }
        for(unsigned i = 0; i < sizeof(names) / sizeof(names[0]); ++i)
        {
            REQUIRE(ref.At(names[i]).GetName() == names[i]);
            REQUIRE(ref[names[i]].GetName() == names[i]);
            REQUIRE(parent.At(names[i]).GetName() == names[i]);
            REQUIRE(parent[names[i]].GetName() == names[i]);
        }
    }
}
