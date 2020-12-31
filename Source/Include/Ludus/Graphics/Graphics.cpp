/* ========================================================================= */
/**
 * @author          David Wong Cascante
 * @file            Graphics.cpp
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
/* Includes */
/* ========================================================================= */
#include "Window.hpp"
#include "Graphics.hpp"

namespace Ludus
{
    Graphics::Graphics(DeviceType const &renderAPI) :
        window_()
    {
        /* Set the default window and swapchain settings for the window. */
        Window::Settings settings;
        Window::Swapchain swapchain;

        settings.title_ = L"Ludus";
        settings.device_ = renderAPI;

        swapchain.width_ = 800;
        swapchain.height_ = 600;

        window_ = std::make_unique<Window>(new Window(settings, swapchain));
    }

    Window &Graphics::GetWindow() const
    {
        return *window_;
    }
}
