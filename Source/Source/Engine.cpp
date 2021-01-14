/* ========================================================================= */
/**
 * @author          David Wong Cascante
 * @file            Engine.cpp
 * @par             
 * @date            11/04/2020
 * 
 * @brief
 * Provides the main entry point into the engine and therefore the game.
 * The engine contains a collection of systems needed to run the engine.
 **/
/* ========================================================================= */

/* ========================================================================= */
/* Includes */
/* ========================================================================= */
#include "Ludus/System/Engine.hpp"

namespace Ludus
{
    Engine::Engine()
    {
    }

    void Engine::Run()
    {
        // Initialize all the systems.
        while(running_)
        {
            // Update simulation until stopped.
        }
        // Stop simulation here.
    }

    void Engine::Stop()
    {
    }

    bool Engine::IsRunning() const
    {
        return running_;
    }
}
