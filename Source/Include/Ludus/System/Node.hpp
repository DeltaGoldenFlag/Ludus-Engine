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
#include <string>
#include "Ludus/System/IObject.hpp"

namespace Ludus
{
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
        void AddChild(Node &child);
        
        /* ================================================================= */
        /**
         * Gets a constant pointer to the parent element.
         * @returns             A constant reference to the parent element
         *                      of this node.
         **/
        /* ================================================================= */
        const Node &GetParent() const;
        /* ================================================================= */
        /**
         * Gets a pointer to the parent element.
         * @returns             A copy of the parent element
         *                      of this node.
         **/
        /* ================================================================= */
        Node GetParent();
        /* ================================================================= */
        /**
         * Gets the name of the node.
         * @returns             The name of the node.
         **/
        /* ================================================================= */
        const std::string& GetName() const;
        /* ================================================================= */
        /**
         * Gets a constant pointer to a child element given an index.
         * @param i             The index to access a child.
         * @returns             A constant reference to a shared pointer.
         **/
        /* ================================================================= */
        const Node &At(const unsigned &i) const;
        /* ================================================================= */
        /**
         * Gets a pointer to a child element given an index.
         * @param i             The index to access a child.
         * @returns             A copy of the object being gotten.
         **/
        /* ================================================================= */
        Node At(const unsigned &i);
        /* ================================================================= */
        /**
         * Gets a pointer to a child element given the name.
         * @param name          The name of the element gotten.
         * @returns             A constatn reference
         *                      to the child element.
         **/
        /* ================================================================= */
        const Node &At(const std::string &name) const;
        /* ================================================================= */
        /**
         * Gets a pointer to the child element given a name.
         * @param name          The name of the element gotten.
         * @returns             A copy of the element gotten.
         **/
        /* ================================================================= */
        Node At(const std::string &name);
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
         * Gets a copy to a child element given an index.
         * @param i             The index to access a child.
         * @returns             A copy of the object being gotten.
         **/
        /* ================================================================= */
        Node operator[](const unsigned &i);
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
         * @returns             A copy of the child element indexed.
         **/
        /* ================================================================= */
        Node operator[](const std::string &name);
    private:
        /** The name of the node to identiy it. */
        std::string name_;
        /** The list of children this node has. */
        std::vector<Node> children_;
        /** The parent node of this element. */
        Node *parent_;
    };
}

/* ========================================================================= */
#endif // Module_Name_MODULE_H
/* ========================================================================= */
