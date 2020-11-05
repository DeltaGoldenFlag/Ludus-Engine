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
#ifndef IObject_MODULE_H
#define IObject_MODULE_H
/* ========================================================================= */

/* ========================================================================= */
/**
 * Defines the namespace that all source files for the Ludus game 
 * engine should go into.
 **/
/* ========================================================================= */
namespace Ludus
{
    /* ===================================================================== */
    /**
     * Defines the base object for all the objects int he Ludus game engine.
     **/
    /* ===================================================================== */
    class IObject
    {
    public:
        /* ================================================================= */
        /**
         * Defines a virtual destructor so subclasses can be cleaned up
         * through an IObject pointer.
         **/
        /* ================================================================= */
        virtual ~IObject() = default;
        /* ================================================================= */
        /**
         * Initializes any states of the variables for the object.
         **/
        /* ================================================================= */
        virtual void Initialize();
        /* ================================================================= */
        /**
         * Updates the object with a variadic delta time.
         * @param dt            The amount of time the last frame took.
         **/
        /* ================================================================= */
        virtual void Update(const double &dt);
        /* ================================================================= */
        /**
         * Updates the object with a fixed time frame.
         * This function gets multiple times to cover the amount of time
         * the last frame took to calculate.
         * @param fixedDt       The fixed amount of time this current
         *                      frame is taking.
         **/
        /* ================================================================= */
        virtual void FixedUpdate(const double &dt);
        /* ================================================================= */
        /**
         * Performs any algorithms needed before actually drawing
         * anything.
         **/
        /* ================================================================= */
        virtual void PreDraw();
        /* ================================================================= */
        /**
         * Draws anything the object needs to show up in-game.
         **/
        /* ================================================================= */
        virtual void Draw() const;
        /* ================================================================= */
        /**
         * Pops any resources used for rendering off the rendering engine.
         **/
        /* ================================================================= */
        virtual void PostDraw();
        /* ================================================================= */
        /**
         * Draws any gizmos needed as debug information or editor.
         **/
        /* ================================================================= */
        virtual void DrawGizmo();
        /* ================================================================= */
        /**
         * Shuts down any variables that need cleaning before releasing
         * resources.
         **/
        /* ================================================================= */
        virtual void Shutdown();
    };
}

/* ========================================================================= */
#endif // Module_Name_MODULE_H
/* ========================================================================= */