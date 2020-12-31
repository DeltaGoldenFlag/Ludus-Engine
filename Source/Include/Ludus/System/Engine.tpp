/* ========================================================================= */
/**
 * @author          David Wong Cascante
 * @file            Engine.tpp
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
#include <sstream>
#include <stdexcept>

namespace Ludus
{
    template <class T>
    void Engine::AddOn()
    {
    }

    template <class T>
    T& Engine::Find() const noexcept(false)
    {
        std::stringstream builder;
        builder << "Failed to find the system ";
        builder << typeid(T).name();
        throw std::runtime_error(builder.str().c_str());
    }
}
