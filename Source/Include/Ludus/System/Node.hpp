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
         * Adds a child to this node object.
         * @param child         A pointer to a newly created child. 
         *                      This function uses move semantics and will
         *                      make the pointer copied from invalidated.
         **/
        /* ================================================================= */
        void AddChild(std::unique_ptr<Node> &child);
        
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
        std::weak_ptr<Node> GetParent();
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
        std::weak_ptr<Node> At(const unsigned &i);
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
        std::weak_ptr<Node> operator[](const unsigned &i);

    private:
        /** The list of children this node has. */
        std::vector<std::unique_ptr<Node>> chlidren_;
        /** The parent node of this element. */
        std::shared_ptr<Node> parent_;
    };
}

/* ========================================================================= */
#endif // Module_Name_MODULE_H
/* ========================================================================= */