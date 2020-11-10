/* ========================================================================= */
/**
 * @author          David Wong Cascante
 * @file            Node.cpp
 * @par             Ludus Engine
 * @date            11/05/2020
 * 
 * @brief
 * All objects that belong to some sort of hierarchy will derive from Node.
 * 
 **/
/* ========================================================================= */

/* ========================================================================= */
/* Includes */
/* ========================================================================= */
#include "Ludus/Precompile.hpp"
#include "Ludus/System/Node.hpp"

namespace Ludus
{
    NodeNotFound::NodeNotFound(const std::string &name)
        : out_of_range(("Failed to find the child: " + name).c_str())
    {
    }

    Node::Node(const std::string& name)
    {
        UNREFERENCED(name);
    }

    void Node::AddChild(std::shared_ptr<Node> child)
    {
        UNREFERENCED(child);
    }

    const Node &Node::GetParent() const
    {
        return *parent_;
    }

    const std::string& Node::GetName() const
    {
        return name_;
    }

    Node Node::GetParent()
    {
        return Node();
    }

    const Node &Node::At(const unsigned &i) const
    {
        UNREFERENCED(i);
        return *parent_;
    }

    Node Node::At(const unsigned &i)
    {
        UNREFERENCED(i);
        return Node();
    }

    const Node &Node::operator[](const unsigned &i) const
    {
        return At(i);
    }

    Node Node::operator[](const unsigned &i)
    {
        return At(i);
    }

    const Node &Node::Find(const std::string &name) const
    {
        UNREFERENCED(name);
        return *parent_;
    }

    Node Node::Find(const std::string &name)
    {
        UNREFERENCED(name);
        return Node();
    }
}
