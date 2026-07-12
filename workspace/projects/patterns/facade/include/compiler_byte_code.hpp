#ifndef __COMPILER_BYTE_CODE_H__
#define __COMPILER_BYTE_CODE_H__ 

#include <vector>
class ByteCode
{

};

class ByteCodeStream
{
    public: 
        ByteCodeStream();

        virtual ByteCode* next();

    private:
        std::vector<ByteCode*> _content;
};

#endif /* ifndef __COMPILER_BYTE_CODE_H__ */
