#ifndef __APPLICATION_H__
#define __APPLICATION_H__ 

#include "application_menu_base.hpp"
#include "document.hpp"
#include "list.h"
class Application 
{
    public:
        Application();
        virtual ~Application();

        virtual void addDocument(Document*);
        virtual void removeDocument(Document*);
        virtual Document* getDocument(int) const;

        virtual void menu(BaseMenu*);
        virtual BaseMenu* menu();

    private:
        List<Document*> _documents;
        BaseMenu* _menu;
};

#endif /* ifndef __APPLICATION_H__ */
