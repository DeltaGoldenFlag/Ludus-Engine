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
#include "Engine.hpp"

namespace Ludus
{
    Engine::Engine()
    {
    }

    void Engine::Run()
    {
    }

    void Engine::Stop()
    {
    }

    bool Engine::IsRunning() const
    {
        return running_;
    }
}
