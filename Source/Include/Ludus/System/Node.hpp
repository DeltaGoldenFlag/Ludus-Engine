/* ========================================================================= */
/**
 * @author          David Wong Cascante
 * @file            Node.hpp
 * @par             Ludus Engine
 * @date            11/05/2020
 * 
 * @brief
 * All objects that belong to some sort of hierarchy will derive from Node.
 * 
 **/
/* ========================================================================= */

/* ========================================================================= */
#ifndef Module_Name_MODULE_H
#define Module_Name_MODULE_H
/* ========================================================================= */

/* ========================================================================= */
/* Includes */
/* ========================================================================= */
#include <vector>
#include <memory>
#include <string>
#include <stdexcept>
#include <memory>
#include "Ludus/System/IObject.hpp"

namespace Ludus
{
    /* ===================================================================== */
    /**
     * The class thrown when the Node fails to get a child node.
     **/
    /* ===================================================================== */
    class NodeNotFound : public std::out_of_range
    {
    public:
        /* ================================================================= */
        /**
         * Constructs an exception to class when the node isn't able
         * to find a child.
         * @param name              The name of the node not found.
         **/
        /* ================================================================= */
        NodeNotFound(const std::string &name);
    };
    /* ===================================================================== */
    /**
     * The super class that every hierarchical object belongs to.
     **/
    /* ===================================================================== */
    class Node : public IObject
    {
    public:
        /* ================================================================= */
        /**
         * Creates a node with a given name.
         * @param name          The name of the node created.
         **/
        /* ================================================================= */
        explicit Node(const std::string &name = std::string());
        /* ================================================================= */
        /**
         * Adds a child to this node object.
         * @param child         A reference to a newly created child. 
         *                      This function uses move semantics and will
         *                      make the pointer copied from invalidated.
         **/
        /* ================================================================= */
        void AddChild(std::shared_ptr<Node> child);
        
        /* ================================================================= */
        /**
         * Gets a constant reference to the parent element.
         * @returns             A constant reference to the parent element
         *                      of this node.
         **/
        /* ================================================================= */
        const Node &GetParent() const;
        /* ================================================================= */
        /**
         * Gets a reference to the parent element.
         * @returns             A reference of the parent element
         *                      of this node.
         **/
        /* ================================================================= */
        Node &GetParent();
        /* ================================================================= */
        /**
         * Gets the name of the node.
         * @returns             The name of the node.
         **/
        /* ================================================================= */
        const std::string& GetName() const;
        /* ================================================================= */
        /**
         * Gets a constant reference to a child element given an index.
         * @param i             The index to access a child.
         * @returns             A constant reference to a shared pointer.
         * @throw NodeNotFound  When the child node was not found at that
         *                      index.
         **/
        /* ================================================================= */
        const Node &At(const unsigned &i) const noexcept(false);
        /* ================================================================= */
        /**
         * Gets a reference to a child element given an index.
         * @param i             The index to access a child.
         * @returns             A reference of the object being gotten.
         * @throw NodeNotFound  When the child node was not found at that
         *                      index.
         **/
        /* ================================================================= */
        Node &At(const unsigned &i) noexcept(false);
        /* ================================================================= */
        /**
         * Gets a reference to a child element given the name.
         * @param name          The name of the element gotten.
         * @returns             A constant reference
         *                      to the child element.
         * @throw NodeNotFound  When the child node was not found with that
         *                      name.
         **/
        /* ================================================================= */
        const Node &Find(const std::string &name) const noexcept(false);
        /* ================================================================= */
        /**
         * Gets a reference to the child element given a name.
         * @param name          The name of the element gotten.
         * @returns             A reference of the element gotten.
         * @throw NodeNotFound  When the child node was not found with that
         *                      name.
         **/
        /* ================================================================= */
        Node &Find(const std::string &name) noexcept(false);
        /* ================================================================= */
        /**
         * Gets a constant reference to a child element given an index.
         * @param i             The index to access a child.
         * @returns             A constant reference to the element gotten.
         **/
        /* ================================================================= */
        const Node &operator[](const unsigned &i) const;
        /* ================================================================= */
        /**
         * Gets a reference to a child element given an index.
         * @param i             The index to access a child.
         * @returns             A reference of the object being gotten.
         **/
        /* ================================================================= */
        Node &operator[](const unsigned &i);
        /* ================================================================= */
        /**
         * Gets a constant reference to a child element given it's name.
         * @param name          The name of the element child to get.
         * @returns             A constant reference to the element gotten.
         **/
        /* ================================================================= */
        const Node &operator[](const std::string &name) const;
        /* ================================================================= */
        /**
         * Gets a copy of to the child element given it's name.
         * @param name          The name of the element child to get.
         * @returns             A reference of the child element indexed.
         **/
        /* ================================================================= */
        Node &operator[](const std::string &name);
        
    private:
        /** The name of the node to identiy it. */
        std::string name_;
        /** The list of children this node has. */
        std::vector<std::shared_ptr<Node> > children_;
        /** The parent node of this element. */
        Node *parent_;
    };
}

/* ========================================================================= */
#endif // Module_Name_MODULE_H
/* ========================================================================= */
