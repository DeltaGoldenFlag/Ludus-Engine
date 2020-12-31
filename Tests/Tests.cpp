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
#include <memory>

#define CATCH_CONFIG_MAIN
#include "catch2.hpp"

/*  ======================================================================== */
/*  NODES                                                                    */
/*  ======================================================================== */
#include "Ludus/System/Node.hpp"

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
        std::shared_ptr<Node> child = std::make_shared<Node>("Child");
        
        parent.AddChild(child);
        REQUIRE(child->GetParent().GetName() == parent.GetName());
    }

    SECTION("Doing more tree traversal")
    {
        Node parent("Parent");
        for(int i = 0; i < 3; ++i)
        {
            std::shared_ptr<Node> child = std::make_shared<Node>("Child-" + std::to_string(i));
            for(int j = 0; j < 3; ++j)
            {
                std::shared_ptr<Node> grandChild = std::make_shared<Node>(("Grand-Child-" + std::to_string(i)));
                child->AddChild(grandChild);
                REQUIRE(grandChild->GetParent().GetName() == child->GetName());
            }
            parent.AddChild(child);
            REQUIRE(child->GetParent().GetName() == parent.GetName());
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
            std::shared_ptr<Node> child = std::make_shared<Node>(names[i]);
            parent.AddChild(child);
        }
        for(unsigned i = 0; i < sizeof(names) / sizeof(names[0]); ++i)
        {
            REQUIRE(ref.At(i).GetName() == names[i]);
            REQUIRE(ref[i].GetName() == names[i]);
            REQUIRE(parent.At(i).GetName() == names[i]);
            REQUIRE(parent[i].GetName() == names[i]);
        }
        try
        {
            parent.At(static_cast<unsigned>(-1));
            /* Failed to throw an exception when an invalid child was not found. */
            REQUIRE(false);
        }
        catch(const std::out_of_range&)
        {
            /* We good. */
            REQUIRE(true);
        }
    }

    SECTION("Traversing the node using names")
    {
        std::string names[] = { "Child1", "Child2", "Child3" };
        Node parent("Parent");
        const Node &ref = parent;
        for(unsigned i = 0; i < sizeof(names) / sizeof(names[0]); ++i)
        {
            std::shared_ptr<Node> child = std::make_shared<Node>(names[i]);
            parent.AddChild(child);
        }
        for(unsigned i = 0; i < sizeof(names) / sizeof(names[0]); ++i)
        {
            REQUIRE(ref.Find(names[i]).GetName() == names[i]);
            REQUIRE(parent.Find(names[i]).GetName() == names[i]);
        }
        try
        {
            parent.Find("YEEHAW");
            /* Failed to throw an exception when an invalid child was not found. */
            REQUIRE(false);
        }
        catch(const Ludus::NodeNotFound&)
        {
            /* We good. */
            REQUIRE(true);
        }
    }
}

/*  ======================================================================== */
/*  ENGINE                                                                   */
/*  ======================================================================== */
#include <Ludus/System/Engine.hpp>
#include <Ludus/Graphics/Graphics.hpp>

TEST_CASE("Test the entry point of the engine")
{
    SECTION("Test the engine doesn't on creation.")
    {
        Ludus::Engine engine;
        REQUIRE(engine.IsRunning() == false);
    }

    SECTION("Check whether can add addons and access them.")
    {
        class TestSystem final : public Ludus::IObject
        {
        };

        Ludus::Engine engine;
        engine.AddOn<TestSystem>();
        REQUIRE_NOTHROW(engine.Find<TestSystem>());
    }
}