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

        friend bool operator==(const Document&, const Document&);

    private:
        char _name[256];
};

#endif /* ifndef __DOCUMENT_H__ */
