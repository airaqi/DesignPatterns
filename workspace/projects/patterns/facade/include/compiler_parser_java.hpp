#ifndef __COMPILER_PARSER_JAVA_H__
#define __COMPILER_PARSER_JAVA_H__ 

#include "compiler_parser.hpp"
#include "compiler_scanner.hpp"
#include "compiler_token.hpp"
#include "compiler_token_word_type.hpp"
#include "program_node.hpp"
#include "program_node_builder.hpp"

class ExprNode;
class StmtNode;
class AssignmentNode;
class VariableNode;
class BlockNode;

class ParserJava : public Parser
{
    public:
        ParserJava(Scanner&, ProgramNodeBuilder&);
        virtual ~ParserJava();

        virtual ProgNode* parse(ProgNode*) override;

        virtual BlockNode*          block(ProgNode*);
        virtual void                decls(ProgNode*);
        virtual Type*               type();
        virtual Type*               dims(Type* p);
        virtual StmtNode*      stmts();
        virtual StmtNode*      stmt();
        virtual StmtNode*      assign();
        virtual ExprNode*     boolean();
        virtual ExprNode*     join();
        virtual ExprNode*     equality();
        virtual ExprNode*     rel();
        virtual ExprNode*     expr();
        virtual ExprNode*     term();
        virtual ExprNode*     unary();
        virtual ExprNode*     factor();

};

#endif /* ifndef __COMPILER_PARSER_JAVA_H__ */
