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
#include <memory>
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
        explicit Node(const std::string &name);
        /* ================================================================= */
        /**
         * Adds a child to this node object.
         * @param child         A pointer to a newly created child. 
         *                      This function uses move semantics and will
         *                      make the pointer copied from invalidated.
         **/
        /* ================================================================= */
        void AddChild(std::shared_ptr<Node> &child);
        
        /* ================================================================= */
        /**
         * Gets a constant pointer to the parent element.
         * @returns             A constant pointer to the parent element
         *                      of this node.
         **/
        /* ================================================================= */
        const std::shared_ptr<Node> &GetParent() const;
        /* ================================================================= */
        /**
         * Gets a pointer to the parent element.
         * @returns             A pointer to the parent element
         *                      of this node.
         **/
        /* ================================================================= */
        std::shared_ptr<Node> GetParent();
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
        const std::shared_ptr<Node> &At(const unsigned &i) const;
        /* ================================================================= */
        /**
         * Gets a pointer to a child element given an index.
         * @param i             The index to access a child.
         * @returns             A weak pointer to the object being gotten.
         **/
        /* ================================================================= */
        std::shared_ptr<Node> At(const unsigned &i);
        /* ================================================================= */
        /**
         * Gets a pointer to a child element given the name.
         * @param name          The name of the element gotten.
         * @returns             A constatn referenced to shared pointer
         *                      to the child element.
         **/
        /* ================================================================= */
        const std::shared_ptr<Node> &At(const std::string &name) const;
        /* ================================================================= */
        /**
         * Gets a pointer to the child element given a name.
         * @param name          The name of the element gotten.
         * @returns             A pointer to element with the name.
         **/
        /* ================================================================= */
        std::shared_ptr<Node> At(const std::string &name);
        /* ================================================================= */
        /**
         * Gets a constant pointer to a child element given an index.
         * @param i             The index to access a child.
         * @returns             A constant reference to a shared pointer.
         **/
        /* ================================================================= */
        const std::shared_ptr<Node> &operator[](const unsigned &i) const;
        /* ================================================================= */
        /**
         * Gets a pointer to a child element given an index.
         * @param i             The index to access a child.
         * @returns             A weak pointer to the object being gotten.
         **/
        /* ================================================================= */
        std::shared_ptr<Node> operator[](const unsigned &i);

    private:
        /** The name of the node to identiy it. */
        std::string name_;
        /** The list of children this node has. */
        std::vector<std::shared_ptr<Node>> children_;
        /** The parent node of this element. */
        std::shared_ptr<Node> parent_;
    };
}

/* ========================================================================= */
#endif // Module_Name_MODULE_H
/* ========================================================================= */
