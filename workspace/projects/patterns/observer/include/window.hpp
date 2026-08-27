#ifndef __WINDOW_H__
#define __WINDOW_H__ 

#include <memory>
class Window {
    public:
        using Ptr = std::shared_ptr<Window>;

        Window() = default;
        virtual ~Window() {}

        virtual void draw() = 0;
};

#endif /* ifndef __WINDOW_H__ */
