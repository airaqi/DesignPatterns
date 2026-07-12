#ifndef __COMPILER_CODE_GENERATOR_H__
#define __COMPILER_CODE_GENERATOR_H__ 

#include "compiler_byte_code.hpp"

class StmtNode;
class ExprNode;

/* Code generation visitor pattern
 * tranverses all nodes and generates the byte code.
 * There will be several CodeGenerators as subclasses 
 * of this class, each for every language of the 
 * implemented languauges.
 */
class CodeGenerator
{
    public:
        virtual void visit(StmtNode*);
        virtual void visit(ExprNode*);

    protected:
        CodeGenerator(ByteCodeStream&);
    protected:
        ByteCodeStream& _stream;
};

#endif /* ifndef __COMPILER_CODE_GENERATOR_H__ */
