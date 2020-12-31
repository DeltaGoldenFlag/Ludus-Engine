/* ========================================================================= */
/**
 * @author          David Wong Cascante
 * @file            Window.hpp
 * @par             
 * @date            12/30/2020
 * 
 * @brief
 * Contains the data needed for the Engine's window to run.
 * The only requirement for a window to exist is that it needs a swapchain.
 **/
/* ========================================================================= */

/* ========================================================================= */
#ifndef Window_MODULE_H
#define Window_MODULE_H
/* ========================================================================= */

/* ========================================================================= */
/* Includes */
/* ========================================================================= */
#include "Ludus/Graphics/Graphics.hpp"

namespace Ludus
{
    /* ================================================================= */
    /**
     * The window that holds all the information for the rendering 
     * context.
     */
    /* ================================================================= */
    class Window
    {
    public:
        /* ============================================================= */
        /** The settings relating to the window. */
        /* ============================================================= */
        struct Settings
        {
            /** The window's title. */
            std::wstring title_;
            /** The rendering API used. */
            Graphics::DeviceType device_;
        };
        /* ============================================================= */
        /** The settings for the swap chain. */
        /* ============================================================= */
        struct Swapchain
        {
            /** The width of the swap chain. */
            unsigned width_;
            /** The height of the swap chain. */
            unsigned height_;
        };

        /* ============================================================= */
        /**
         * The creation of the window itself.
        **/
        /* ============================================================= */
        Window(Settings const &settings, Swapchain const &swapchain);
        /* ============================================================= */
        /**
         * Sets the title of the window.
         * @param title                     The title of the window.
        **/
        /* ============================================================= */
        void SetTitle(std::wstring const &title);
        /* ============================================================= */
        /**
         * Sets the dimensions of the swap chain.
         * @param width                 The new width of the swapchain.
         * @param height                The new height of the swapchain.
         */
        /* ============================================================= */
        void SetSwapchainDimensions(
            unsigned const &width, unsigned const &height);
        /* ============================================================= */
        /**
         * Sets the rendering API to use for the renderer.
         * @param api              The rendering API to use.
         */
        /* ============================================================= */
        void SetRenderingAPI(Graphics::DeviceType const &api);

        /* ============================================================= */
        /**
         * Gets the width of the swapchain.
         * @returns                     The width of the swapchain.
        **/
        /* ============================================================= */
        unsigned GetWidth() const;
        /* ============================================================= */
        /**
         * Gets the height of the swapchain.
         * @returns                     The height of the swapchain.
        **/
        /* ============================================================= */
        unsigned GetHeight() const;
        /* ============================================================= */
        /**
         * Gets the title of the window.
         * @returns                     The title of the window.
        **/
        /* ============================================================= */
        std::wstring const &GetTitle() const;
        /* ============================================================= */
        /**
         * Gets the rendering API used by the renderer/window.
         * @returns                     The rendering API used.
         */
        /* ============================================================= */
        Graphics::DeviceType const &GetRenderingAPI() const;

    private:
        /** The settings relating to the window itself. */
        Settings settings_;
        /** The settings for the swap chain of this window. */
        Swapchain swapchain_;
    };
}

/* ========================================================================= */
#endif // Window_MODULE_H
/* ========================================================================= */
