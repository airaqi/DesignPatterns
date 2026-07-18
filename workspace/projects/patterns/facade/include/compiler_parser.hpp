#ifndef __COMPILER_PARSER_H__
#define __COMPILER_PARSER_H__

#include "compiler_scanner.hpp"
#include "compiler_token.hpp"
#include "program_node_builder.hpp"
#include "program_node_expr_op_access.hpp"
#include "program_node_stmt.hpp"
#include <string>
#include <plog/Log.h>
#include <plog/Formatters/TxtFormatter.h>
#include <plog/Initializers/ConsoleInitializer.h>


class Parser
{
    public:
        Parser(Scanner& scanner, ProgramNodeBuilder& builder);
        virtual ~Parser();

        void move();
        void error(std::string s); 
        void match(Tag::Kind t);
        
        virtual StmtNode::Ptr parse();

        virtual StmtNode::Ptr   block();
        virtual void            decls();
        virtual Type::Ptr       type();
        virtual Type::Ptr       dims(Type::Ptr p);
        virtual StmtNode::Ptr   stmts();
        virtual StmtNode::Ptr   stmt();
        virtual StmtNode::Ptr   assign();
        virtual ExprNode::Ptr   boolean();
        virtual ExprNode::Ptr   join();
        virtual ExprNode::Ptr   equality();
        virtual ExprNode::Ptr   rel();
        virtual ExprNode::Ptr   expr();
        virtual ExprNode::Ptr   term();
        virtual ExprNode::Ptr   unary();
        virtual ExprNode::Ptr   factor();
        virtual AccessNode::Ptr offset(Id::Ptr);

    protected:
        Scanner                     &_scanner;
        ProgramNodeBuilder          &_builder;
        Token::Ptr                  _look;
        Env::Ptr                    _top;
        int                         _used;
};

#endif /* ifndef __COMPILER_PARSER_H__ */
