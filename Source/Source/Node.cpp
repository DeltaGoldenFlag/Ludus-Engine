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
#include <exception>

namespace Ludus
{
    Node::Node(const std::string& name)
    {
        UNREFERENCED(name);
    }

    void Node::AddChild(std::shared_ptr<Node> &child)
    {
        UNREFERENCED(child);
    }

    const std::shared_ptr<Node> &Node::GetParent() const
    {
        return parent_;
    }

    const std::string& Node::GetName() const
    {
        return name_;
    }

    std::shared_ptr<Node> Node::GetParent()
    {
        return parent_;
    }

    const std::shared_ptr<Node> &Node::At(const unsigned &i) const
    {
        UNREFERENCED(i);
        return parent_;
    }

    std::shared_ptr<Node> Node::At(const unsigned &i)
    {
        UNREFERENCED(i);
        return std::make_shared<Node>("");
    }

    const std::shared_ptr<Node> &Node::operator[](const unsigned &i) const
    {
        return At(i);
    }

    std::shared_ptr<Node> Node::operator[](const unsigned &i)
    {
        return At(i);
    }
}
