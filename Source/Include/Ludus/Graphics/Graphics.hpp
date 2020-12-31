/* ========================================================================= */
/**
 * @author          David Wong Cascante
 * @file            Graphics.hpp
 * @par             
 * @date            12/30/2020
 * 
 * @brief
 * Provides access to all graphical functions the engine is able to do:
 * - The Window.
 * - The Context.
 * - The Rendering Pipeline.
 * While GLFW will always be used to create the window, the context it uses
 * will change and the rendering API will change depending on the settings
 * used.
 **/
/* ========================================================================= */

/* ========================================================================= */
#ifndef Graphics_MODULE_H
#define Graphics_MODULE_H
/* ========================================================================= */

/* ========================================================================= */
/* Includes */
/* ========================================================================= */
#include "Ludus/System/IObject.hpp"
#include <memory>
#include <string>

namespace Ludus
{
    /** Forward declaration to the Window. */
    class Window;
    /** Forward declaration to the Device. */
    class Device;
    /** Forward declaration to the Renderer. */
    class Renderer;

    /* ===================================================================== */
    /**
     * Provides the encompassing graphical object used in the engine.
    **/
    /* ===================================================================== */
    class Graphics : public IObject
    {
    public:
        /* ================================================================= */
        /* Enums */
        /* ================================================================= */
        
        /* ================================================================= */
        /**
         * Defines which kind of rendering API to use.
         * @enum DeviceType
        **/
        /* ================================================================= */
        enum DeviceType
        {
            OPENGL,  /* Use OpenGL for the rendering device. */
            DIRECTX, /* Use DirectX for the rendering device. */
        };

        /* ================================================================= */
        /**
         * Creates the Graphical application encompassing the entire engine.
         * @param renderAPI         The kind of rendering API to use.
        **/
        /* ================================================================= */
        Graphics(DeviceType const &renderAPI);
        /* ================================================================= */
        /**
         * Gets the window (and swapchain) for the graphics class.
         * @returns             A reference to the window class.
         **/
        /* ================================================================= */
        Window &GetWindow() const;
    
    private:
        /** The window that holds the context used by the device. */
        std::unique_ptr<Window> window_;
        /** The graphics device used to create all the assets to render. */
        //std::unique_ptr<Device> device_;
        /** The rendering device used to draw everything. */
        //std::unique_ptr<Renderer> renderer_;
    };
}

/* ========================================================================= */
#endif // Module_Name_MODULE_H
/* ========================================================================= */
