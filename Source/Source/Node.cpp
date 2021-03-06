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
        : std::out_of_range(("Failed to find the child: " + name).c_str())
    {
    }

    Node::Node(const std::string& name)
        : name_(name), parent_(nullptr)
    {
    }

    void Node::AddChild(std::shared_ptr<Node> child)
    {
        children_.push_back(child);
        child->parent_ = this;
    }

    const Node &Node::GetParent() const
    {
        return *parent_;
    }

    const std::string &Node::GetName() const
    {
        return name_;
    }

    Node &Node::GetParent()
    {
        return *parent_;
    }

    const Node &Node::At(const unsigned &i) const
    {
        return *children_.at(i);
    }

    Node &Node::At(const unsigned &i)
    {
        return *children_.at(i);
    }

    const Node &Node::operator[](const unsigned &i) const
    {
        return At(i);
    }

    Node &Node::operator[](const unsigned &i)
    {
        return At(i);
    }

    const Node &Node::Find(const std::string &name) const
    {
        for(auto iter = children_.cbegin(); iter != children_.cend(); ++iter)
        {
            if((*iter)->GetName() == name)
            {
                return **iter;
            }
        }

        throw NodeNotFound(name);
    }

    Node &Node::Find(const std::string &name)
    {
        for(auto iter = children_.cbegin(); iter != children_.cend(); ++iter)
        {
            if((*iter)->GetName() == name)
            {
                return **iter;
            }
        }

        throw NodeNotFound(name);
    }

    size_t Node::Size() const
    {
        return 0u;
    }

    Node::Iterator Node::begin()
    {
        return Iterator(nullptr);
    }

    Node::Iterator const Node::begin() const
    {
        return Iterator(nullptr);
    }

    Node::Iterator const Node::cbegin() const
    {
        return Iterator(nullptr);
    }

    Node::Iterator Node::end()
    {
        return Iterator(nullptr);
    }

    Node::Iterator const Node::end() const
    {
        return Iterator(nullptr);
    }

    Node::Iterator const Node::cend() const
    {
        return Iterator(nullptr);
    }

    Node::Iterator Node::Begin()
    {
        return begin();
    }

    Node::Iterator const Node::Begin() const
    {
        return begin();
    }

    Node::Iterator const Node::CBegin() const
    {
        return cbegin();
    }

    Node::Iterator Node::End()
    {
        return end();
    }

    Node::Iterator const Node::End() const
    {
        return end();
    }

    Node::Iterator const Node::CEnd() const
    {
        return cend();
    }
}
