#include "Window.hpp"
#include "../../Lib/Engine/SFMLGraphics.hpp"


bool AbstractWindow::dispatch_event(const Event& event)
{
    for (auto sub: subwindows) {
        if (sub->dispatch_event(event)) {
            return true;
        }
    }

    return false;
}

void AbstractWindow::add_subwindow(AbstractWindow* another)
{
    subwindows.push_back(another);
}

AbstractWindow::~AbstractWindow()
{
    for (auto sub: subwindows) {
        sub->~AbstractWindow();
        delete sub;
        sub = nullptr;
    }
}

//================================================================================

template <class Shape>
void ShapedWindow<Shape>::draw()
{
    shape.draw();
}
//================================================================================

