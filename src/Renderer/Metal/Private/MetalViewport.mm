#include "MetalViewport.h"

#include <AppKit/NSWindow.h>
#include <CoreFoundation/CoreFoundation.h>
#include <CoreGraphics/CoreGraphics.h>
#include <Metal/MTLPixelFormat.hpp>
#include <QuartzCore/CAMetalDrawable.hpp>
#include <QuartzCore/CAMetalLayer.hpp>

#include "MetalDevice.h"

KMetalViewport::KMetalViewport(
    void* InWindow, std::shared_ptr<KMetalDevice> InDevice
)
    : Window(InWindow)
{
    assert(InDevice != nil);
    assert(InWindow != nil);

    NSWindow* CocoaWindow = (NSWindow*)Window;

    CA::MetalLayer* Layer = CA::MetalLayer::layer();

    const NSRect contentRect = [CocoaWindow contentLayoutRect];
    Layer->setDevice(InDevice->Get());
    Layer->setPixelFormat(MTL::PixelFormatBGRA8Unorm);
    Layer->setDrawableSize(contentRect.size);

    [[CocoaWindow contentView] setLayer:(CALayer*)Layer];
    [[CocoaWindow contentView] setWantsLayer:YES];

    MetalLayer = Layer;
}

KMetalViewport::~KMetalViewport() {}

bool KMetalViewport::IsViewportReady() const { return MetalLayer != nil; }

CA::MetalDrawable* KMetalViewport::GetDrawable()
{
    return MetalLayer->nextDrawable();
}
