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
#include "Precompile.hpp"
#include "Window.hpp"

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

    void Window::SetSwapchainDimensions(float width, float height)
    {
        UNREFERENCED(width);
        UNREFERENCED(height);
    }

    void Window::SetRenderingAPI(Graphics::DeviceType const &api)
    {
        UNREFERENCED(api);
    }

    float Window::GetWidth() const
    {
        return 0.0f;
    }

    float Window::GetHeight() const
    {
        return 0.0f;
    }

    std::wstring const &Window::GetTitle() const
    {
        return L"";
    }

    Graphics::DeviceType const &Window::GetRenderingAPI() const
    {
        return Graphics::DeviceType::OPENGL;
    }
}
