/* ========================================================================= */
/**
 * @author          David Wong Cascante
 * @file            Engine.hpp
 * @par             
 * @date            11/04/2020
 * 
 * @brief
 * Provides the main entry point into the engine and therefore the game.
 * The engine contains a collection of systems needed to run the engine.
 **/
/* ========================================================================= */

/* ========================================================================= */
#ifndef Engine_MODULE_H
#define Engine_MODULE_H
/* ========================================================================= */

/* ========================================================================= */
/* Includes */
/* ========================================================================= */
#include "Ludus/Precompile.hpp"
#include "Ludus/System/IObject.hpp"
#include <vector>
#include <memory>

namespace Ludus
{
    /* ===================================================================== */
    /**
     * The engine that drives the entire simulation.
    **/
    /* ===================================================================== */
    class Engine final : public IObject
    {
    public:
        /* ================================================================= */
        /**
         * Creates the engine.
        **/
        /* ================================================================= */
        Engine();
        /* ================================================================= */
        /**
         * Adds an additional system to the engine.
         * If desired, extra systems can be added to the engine before
         * it gets started.
         * @tparam T                The type of the system being added.
         *                          Usually, manually specifying this is not
         *                          desired.
         *                          The system being added must derive
         *                          from IObject.
         *                          The system must have a default constructor.
        **/
        /* ================================================================= */
        template <class T>
        void AddOn();
        /* ================================================================= */
        /**
         * Starts running the engine.
        **/
        /* ================================================================= */
        void Run();
        /* ================================================================= */
        /**
         * Stops running the systems in the engine and shutsdown 
         * the systems it encompases.
        **/
        /* ================================================================= */
        void Stop();

        /* ================================================================= */
        /**
         * Finds the system with the associated type.
         * @tparam T                    The type of the system being found.
         * @returns                     A reference of the system found.
         * @throw std::exception        If the system was not found at all.
        **/
        /* ================================================================= */
        template <typename T>
        T &Find() const noexcept(false);
        /* ================================================================= */
        /**
         * Gets whether the engine is still running.
         * @returns                 True if the engine is running
         *                          and false otherwise.
         */
        /* ================================================================= */
        bool IsRunning() const;
    private:
        /** Keeps track of whether the engine should keep running. */
        bool running_;
        /** The list of pointers to the systems encompassing the engine. */
        std::vector<std::unique_ptr<IObject> > systems_;

        /* ================================================================= */
        /**
         * Hides the copy constructor, the engine should never be
         * copied in the first place.
         */
        /* ================================================================= */
        Engine(Engine const &engine) = default;
        /* ================================================================= */
        /**
         * Hides the assignment operator, the engine should be never
         * be copied in the first place.
        **/
        /* ================================================================= */
        Engine &operator=(Engine const& engine) = default;
    };
}

#include "Engine.tpp"
/* ========================================================================= */
#endif // Engine_MODULE_H
/* ========================================================================= */
