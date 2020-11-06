/* ========================================================================= */
/**
 * @author          David Wong Cascante
 * @file            IObject.hpp
 * @par             Ludus Engine
 * @date            11/05/2020
 * 
 * @brief
 * Provides the interface for all objects in the Ludus game engine.
 * Provides the following functions:
 * - dtor
 * - Initialize
 * - Update
 * - FixedUpdate
 * - PreDraw
 * - Draw
 * - PostDraw
 * - Shutdown
 * All derived objects should initialize their resources during construction.
 **/
/* ========================================================================= */

/* ========================================================================= */
/* Includes */
/* ========================================================================= */

#include "Ludus/Precompile.hpp"
#include "Ludus/System/IObject.hpp"

namespace Ludus
{
    void IObject::Initialize()
    {
    }

    void IObject::Update(const double &dt)
    {
        UNREFERENCED(dt);
    }

    void IObject::FixedUpdate(const double &fixedDt)
    {
        UNREFERENCED(fixedDt);
    }

    void IObject::PreDraw()
    {
    }

    void IObject::Draw() const
    {
    }

    void IObject::PostDraw()
    {
    }

    void IObject::DrawGizmo()
    {
    }

    void IObject::Shutdown()
    {
    }
}
