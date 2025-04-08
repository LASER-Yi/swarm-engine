#pragma once

#include <memory>

namespace CA
{
class MetalLayer;
class MetalDrawable;
} // namespace CA

class KMetalDevice;

/**
 * The viewport for Metal
 * Metal's clip space is a left-handed coordinate system, where
 * the x-axis is the horizontal direction in screen (-1.0 - 1.0)
 * the y-axis is the vertical direction in screen (-1.0 - 1.0)
 * the x-axis is the depth in screen (0.0 - 1.0)
 */
class KMetalViewport
{
public:
    KMetalViewport(void* InWindow, std::shared_ptr<KMetalDevice> InDevice);

    ~KMetalViewport();

    bool IsViewportReady() const;

    CA::MetalDrawable* GetDrawable();

private:
    void* Window;
    CA::MetalLayer* MetalLayer;
};
