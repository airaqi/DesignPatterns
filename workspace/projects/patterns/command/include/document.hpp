#ifndef __DOCUMENT_H__
#define __DOCUMENT_H__ 

class Document
{
    public:
        Document(const char* name);
        virtual ~Document();

        virtual void open();
        virtual void close();
        virtual void cut();
        virtual void copy();
        virtual void paste();

    private:
        const char* _name;
};

#endif /* ifndef __DOCUMENT_H__ */
