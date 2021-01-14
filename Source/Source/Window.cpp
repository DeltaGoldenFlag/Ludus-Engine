/* ========================================================================= */
/**
 * @author          David Wong Cascante
 * @file            Window.cpp
 * @par             
 * @date            12/30/2020
 * 
 * @brief
 * Contains the data needed for the Engine's window to run.
 * The only requirement for a window to exist is that it needs a swapchain.
 **/
/* ========================================================================= */

/* ========================================================================= */
/* Includes */
/* ========================================================================= */
#include "Ludus/Precompile.hpp"
#include "Ludus/Graphics/Window.hpp"

namespace Ludus
{
    Window::Window(Settings const &settings, Swapchain const &swapchain) :
        settings_(settings), swapchain_(swapchain)
    {
    }

    void Window::SetTitle(std::wstring const &title)
    {
        UNREFERENCED(title);
    }

    void Window::SetSwapchainDimensions(unsigned const &width, unsigned const &height)
    {
        UNREFERENCED(width);
        UNREFERENCED(height);
    }

    void Window::SetRenderingAPI(Graphics::DeviceType const &api)
    {
        UNREFERENCED(api);
    }

    unsigned Window::GetWidth() const
    {
        return 0;
    }

    unsigned Window::GetHeight() const
    {
        return 0;
    }

    std::wstring const &Window::GetTitle() const
    {
        return settings_.title_;
    }

    Graphics::DeviceType const &Window::GetRenderingAPI() const
    {
        return settings_.device_;
    }
}
