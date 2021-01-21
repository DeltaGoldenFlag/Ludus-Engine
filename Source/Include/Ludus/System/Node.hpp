/* ========================================================================= */
/**
 * @author          David Wong Cascante
 * @file            Node.hpp
 * @par             Ludus Engine
 * @date            11/05/2020
 * 
 * @brief
 * All objects that belong to some sort of hierarchy will derive from Node.
 * Source for setting up iterators found here:
 * https://www.internalpointers.com/post/writing-custom-iterators-modern-cpp
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
#include <iterator>
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
        /* ===================================================================== */
        /**
         * The class representing the iterators used by users of the Node
         * class to traverse through children.
        **/
        /* ===================================================================== */
        struct Iterator
        {
        public:
            // Setting up the tags for the STL.
            using iterator_category = std::forward_iterator_tag;
            using difference_type = std::ptrdiff_t;
            using value_type = Node;
            using pointer = Node *;
            using reference = Node &;
            
            /* ================================================================= */
            /**
             * Constructs an iterator at any give position in the Node class.
             * @param pointer           The pointer to the node the iterator
             *                          represents.
            **/
            /* ================================================================= */
            Iterator(Node *pointer);
            /* ================================================================= */
            /**
             * Makes a copy of another iterator.
             * @param other             The iterator being made a copy of.
            **/
            /* ================================================================= */
            Iterator(Iterator const &other);
            /* ================================================================= */
            /**
             * Copies the state of the other iterator into this one.
             * @param other             The other iterator copying the values
             *                          from.
             * @returns                 A reference to the iterator the values
             *                          were copied to.
            **/
            /* ================================================================= */
            Iterator &operator=(Iterator const &other);

            /* ================================================================= */
            /**
             * Gets the object the iterator is pointing to.
             * @returns                 A reference to the Node object
             *                          this iterator is pointing to.
            **/
            /* ================================================================= */
            Node &operator*();
            /* ================================================================= */
            /**
             * Gets a constant version of the object the iterator points to.
             * @returns                 A constant reference to the Node
             *                          this iterator is pointing to.
            **/
            /* ================================================================= */
            Node const &operator*() const;
            /* ================================================================= */
            /**
             * Calls member functions of the object the iterator is referencing.
             * @returns                 The pointer the iterator is referencing
             *                          so its member function can be called.
            **/
            /* ================================================================= */
            Node *operator->();
            /* ================================================================= */
            /**
             * Calls member functions of the object the iterator is referencing.
             * @returns                 The pointer the iterator is referencing
             *                          so its constant  member function 
             *                          can be called.
            **/
            /* ================================================================= */
            Node const *operator->() const;

            /* ================================================================= */
            /**
             * Advances the iterator to the next element.
             * @returns                 A reference to the iterator being
             *                          stepped forward.
            **/ 
            /* ================================================================= */
            Iterator &operator++();
            /* ================================================================= */
            /**
             * Advances the iterator but returning the state of the iterator
             * before advancing it.
             * @returns                 A copy of the iterator before advancing it.
            **/
            /* ================================================================= */
            Iterator operator++(int);
            /* ================================================================= */
            /**
             * Checks for equality with another iterator.
             * @param rhs               The iterator on the right hand side
             *                          of the equality check.
             * @returns                 True if the iterators are equal,
             *                          false otherwise.
            **/
            /* ================================================================= */
            bool operator==(Iterator const &rhs) const;
            /* ================================================================= */
            /**
             * Checks for inequality with another iterator.
             * @param rhs               The iterator on the right hand side
             *                          of the inequality.
             * @returns                 True if the iterators are not equal,
             *                          false otherwise.
            **/
            /* ================================================================= */
            bool operator!=(Iterator const &rhs) const;
        private:
            /** The pointer the iterator manages. */
            Node *pointer_;
        };
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
        /* ================================================================= */
        /**
         * Gets the number of children for this node.
         * @returns             The number of children this node has.
         */
        /* ================================================================= */
        size_t Size() const;
        /* ================================================================= */
        /**
         * Gets the beginning element of the children.
         * @returns             The iterator pointing to the beginning of
         *                      the children list.
        **/
        /* ================================================================= */
        Iterator begin();
        /* ================================================================= */
        /**
         * Gets the beginning element of the children.
         * @returns             The iterator pointing to the beginning of
         *                      the children list.
        **/
        /* ================================================================= */
        Iterator const begin() const;
        /* ================================================================= */
        /**
         * Gets the beginning element of the children.
         * @returns             The iterator pointing to the beginning of
         *                      the children list.
        **/
        /* ================================================================= */
        Iterator const cbegin() const;
        /* ================================================================= */
        /**
         * Gets the ending element of the children.
         * @returns             The iterator pointing to the end of
         *                      the children list.
        **/
        /* ================================================================= */
        Iterator end();
        /* ================================================================= */
        /**
         * Gets the ending element of the children.
         * @returns             The iterator pointing to the end of
         *                      the children list.
        **/
        /* ================================================================= */
        Iterator const end() const;
        /* ================================================================= */
        /**
         * Gets the ending element of the children.
         * @returns             The iterator pointing to the end of
         *                      the children list.
        **/
        /* ================================================================= */
        Iterator const cend() const;
        /* ================================================================= */
        /**
         * Gets the beginning element of the children.
         * @returns             The iterator pointing to the beginning of
         *                      the children list.
        **/
        /* ================================================================= */
        Iterator Begin();
        /* ================================================================= */
        /**
         * Gets the beginning element of the children.
         * @returns             The iterator pointing to the beginning of
         *                      the children list.
        **/
        /* ================================================================= */
        Iterator const Begin() const;
        /* ================================================================= */
        /**
         * Gets the beginning element of the children.
         * @returns             The iterator pointing to the beginning of
         *                      the children list.
        **/
        /* ================================================================= */
        Iterator const CBegin() const;
        /* ================================================================= */
        /**
         * Gets the ending element of the children.
         * @returns             The iterator pointing to the end of
         *                      the children list.
        **/
        /* ================================================================= */
        Iterator End();
        /* ================================================================= */
        /**
         * Gets the ending element of the children.
         * @returns             The iterator pointing to the end of
         *                      the children list.
        **/
        /* ================================================================= */
        Iterator const End() const;
        /* ================================================================= */
        /**
         * Gets the ending element of the children.
         * @returns             The iterator pointing to the end of
         *                      the children list.
        **/
        /* ================================================================= */
        Iterator const CEnd() const;
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
