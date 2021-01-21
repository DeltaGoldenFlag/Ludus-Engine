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
    // Check that nodes can be given names and that those names can
    // be checked.
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
        // Check to see if added children have the parent
        // set correctly.
        parent.AddChild(child);
        REQUIRE(child->GetParent().GetName() == parent.GetName());
    }

    SECTION("Doing more tree traversal")
    {
        Node parent("Parent");
        // Set up a tree between nodes.
        for(int i = 0; i < 3; ++i)
        {
            std::shared_ptr<Node> child = std::make_shared<Node>("Child-" + std::to_string(i));
            for(int j = 0; j < 3; ++j)
            {
                std::shared_ptr<Node> grandChild = std::make_shared<Node>(("Grand-Child-" + std::to_string(i)));
                child->AddChild(grandChild);
                // Make sure the grand children have the parents set up correctly.
                REQUIRE(grandChild->GetParent().GetName() == child->GetName());
            }
            // Make sure the child of the parent has its parent saved correctly.
            // Also check that children can be added after the fact and their
            // corresponding parent can be updated.
            parent.AddChild(child);
            REQUIRE(child->GetParent().GetName() == parent.GetName());
        }
    }
}

TEST_CASE("Traversal of children.")
{
    using Ludus::Node;
    // Setting up the names of the children.
    std::string names[] = { "Child1", "Child2", "Child3" };
    Node parent("Parent");
    // Test against a constant reference of the same object.
    const Node &ref = parent;
    // Add the children to the parent object.
    for(unsigned i = 0; i < sizeof(names) / sizeof(names[0]); ++i)
    {
        std::shared_ptr<Node> child = std::make_shared<Node>(names[i]);
        parent.AddChild(child);
    }

    SECTION("Traversing the node using indices")
    {
        // Test the sizes are identical of thte array of names.
        REQUIRE(ref.Size() == sizeof(names) / sizeof(names[0]));
        REQUIRE(parent.Size() == sizeof(names) / sizeof(names[0]));
        // Check the children exist and have the same names
        // as the array of names.
        for(unsigned i = 0; i < sizeof(names) / sizeof(names[0]); ++i)
        {
            REQUIRE(ref.At(i).GetName() == names[i]);
            REQUIRE(ref[i].GetName() == names[i]);
            REQUIRE(parent.At(i).GetName() == names[i]);
            REQUIRE(parent[i].GetName() == names[i]);
        }
        REQUIRE_THROWS(parent.At(static_cast<unsigned>(-1)));
    }

    SECTION("Traversing the node using names")
    {
        // Check both objects have children of the same
        // names of the array.
        for(unsigned i = 0; i < sizeof(names) / sizeof(names[0]); ++i)
        {
            REQUIRE(ref.Find(names[i]).GetName() == names[i]);
            REQUIRE(parent.Find(names[i]).GetName() == names[i]);
        }
        // Check that the objects throw exception when trying to
        // find a non-existing child.
        REQUIRE_THROWS(parent.Find("YEEHAW"));
        REQUIRE_THROWS(ref.Find("YEEHAW"));
    }

    SECTION("Traversing the node through iterators")
    {
        // Check that iterators advance through the list
        // of children.
        size_t nameIndex = 0;
        size_t numNames = sizeof(names) / sizeof(names[0]);

        // First check loops with explicit instantiations of 
        // iterators.
        for(Node::Iterator iter = parent.Begin(); iter != parent.End();
            ++iter)
        {
            REQUIRE(iter->GetName() == names[nameIndex++]);
        }
        for(Node::Iterator iter = parent.CBegin(); iter != parent.CEnd();
            ++iter)
        {
            REQUIRE(iter->GetName() == names[nameIndex++ % numNames]);
        }
        for(Node::Iterator iter = ref.CBegin(); iter != ref.CEnd(); ++iter)
        {
            REQUIRE(iter->GetName() == names[nameIndex++ % numNames]);
        }
        // Then check C++11 for each loops.
        for(Node &iter : parent)
        {
            REQUIRE(iter.GetName() == names[nameIndex++ % numNames]);
        }
        for(Node const &iter : parent)
        {
            REQUIRE(iter.GetName() == names[nameIndex++ % numNames]);
        }
        for(Node const &iter : ref)
        {
            REQUIRE(iter.GetName() == names[nameIndex++ % numNames]);
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
        class TestSystem final : public Ludus::Node
        {
        };

        Ludus::Engine engine;
        engine.AddOn<TestSystem>();
        REQUIRE_NOTHROW(engine.Find<TestSystem>());
    }

    SECTION("Check whether can add addons can shut down the engine.")
    {
        class TestSystem final : public Ludus::Node
        {
        public:
            virtual void Update(double const &dt) override
            {
                static unsigned updateCount = 0;
                UNREFERENCED(dt);

                // Make sure this update function only runs once.
                REQUIRE(updateCount++ < 1);
                // Get the parent, and shut it down as the engine.
                Ludus::Engine *engine = reinterpret_cast<Ludus::Engine *>(&GetParent());
                engine->Stop();
                // The engine should stop running here.
                REQUIRE(engine->IsRunning() == false);
            }
        };

        Ludus::Engine engine;
        engine.AddOn<TestSystem>();
        REQUIRE_NOTHROW(engine.Find<TestSystem>());
        engine.Run();
    }
}

/*  ======================================================================== */
/*  GRAPHICS                                                                 */
/*  ======================================================================== */
#include <Ludus/Graphics/Graphics.hpp>
#include <Ludus/Graphics/Window.hpp>

TEST_CASE("Testing the Graphics interface.")
{
    SECTION("Check whether the engine comes with the graphics package.")
    {
        Ludus::Engine engine;
        REQUIRE_NOTHROW(engine.Find<Ludus::Graphics>());
    }

    SECTION("Check whether the graphics package comes with default window data.")
    {
        Ludus::Engine engine;
        Ludus::Graphics const &graphics = engine.Find<Ludus::Graphics>();
        Ludus::Window const &window = graphics.GetWindow();
        // Check if we have a valid device type at all.
        CHECK(window.GetRenderingAPI() & 
            (Ludus::Graphics::DeviceType::DIRECTX | Ludus::Graphics::DeviceType::OPENGL));
        // Check the dimensions.
        CHECK(window.GetWidth() != 0);
        CHECK(window.GetHeight() != 0);
        // The initial window title should be empty.
        CHECK(window.GetTitle().empty());
    }

    SECTION("Check if the user can change the default settings.")
    {
        Ludus::Engine engine;
        Ludus::Graphics &graphics = engine.Find<Ludus::Graphics>();
        Ludus::Window &window = graphics.GetWindow();
        // Set settings other than the default.
        const wchar_t* titleSet = L"Testing Title";
        window.SetRenderingAPI(Ludus::Graphics::DeviceType::DIRECTX);
        window.SetSwapchainDimensions(500, 500);
        window.SetTitle(titleSet);
        // Check for the changes.
        CHECK(window.GetRenderingAPI() == Ludus::Graphics::DeviceType::DIRECTX);
        CHECK(window.GetWidth() == 500);
        CHECK(window.GetHeight() == window.GetWidth());
        CHECK(window.GetTitle() == titleSet);
    }
}
