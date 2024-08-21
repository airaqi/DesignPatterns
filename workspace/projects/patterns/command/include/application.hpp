#ifndef __APPLICATION_H__
#define __APPLICATION_H__ 

#include "document.hpp"
#include "list.h"
class Application 
{
    public:
        Application();
        virtual ~Application();

        virtual void addDocument(Document*);
        virtual void removeDocument(Document*);

    private:
        List<Document*> _documents;
};

#endif /* ifndef __APPLICATION_H__ */
