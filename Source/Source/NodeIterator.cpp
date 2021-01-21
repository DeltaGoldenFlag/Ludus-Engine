/* ========================================================================= */
/**
 * @author          David Wong Cascante
 * @file            NodeIterator.cpp
 * @par             Ludus Engine
 * @date            11/05/2020
 * 
 * @brief
 * All objects that belong to some sort of hierarchy will derive from Node.
 * Source for setting up iterators found here:
 * https://www.internalpointers.com/post/writing-custom-iterators-modern-cpp
 * 
 * This source file in particular implements the iterators for Node.
 * 
 **/
/* ========================================================================= */

#include "Ludus/Precompile.hpp"
#include "Ludus/System/Node.hpp"

namespace Ludus
{
    Node::Iterator::Iterator(Node *pointer)
    {
        UNREFERENCED(pointer);
    }

    Node::Iterator::Iterator(Iterator const &other)
    {
        UNREFERENCED(other);
    }

    Node::Iterator &Node::Iterator::operator=(Iterator const &other)
    {
        UNREFERENCED(other);
        return *this;
    }

    Node &Node::Iterator::operator*()
    {
        return *pointer_;
    }

    Node const &Node::Iterator::operator*() const
    {
        return *pointer_;
    }

    Node *Node::Iterator::operator->()
    {
        return nullptr;
    }

    Node const *Node::Iterator::operator->() const
    {
        return nullptr;
    }

    Node::Iterator &Node::Iterator::operator++()
    {
        return *this;
    }

    Node::Iterator Node::Iterator::operator++(int)
    {
        return *this;
    }

    bool Node::Iterator::operator==(Iterator const &rhs) const
    {
        UNREFERENCED(rhs);
        return false;
    }

    bool Node::Iterator::operator!=(Iterator const &rhs) const
    {
        UNREFERENCED(rhs);
        return false;
    }
}
