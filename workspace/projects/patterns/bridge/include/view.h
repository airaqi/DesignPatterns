#ifndef __VIEW_H__
#define __VIEW_H__ 

class View
{
    public:
        View();

        char* contents() { return _contents; }
        void contents(char* contents) { _contents = contents; }

        virtual void draw();

    private:
        char* _contents;
};

#endif /* ifndef __VIEW_H__ */
