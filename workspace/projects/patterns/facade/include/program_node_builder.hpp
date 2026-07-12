#ifndef __COMPILER_PROGRAM_NODE_BUILDER_H__
#define __COMPILER_PROGRAM_NODE_BUILDER_H__ 

#include "compiler_token.hpp"
#include "compiler_token_word_type.hpp"
#include "program_node_expr_block.hpp"
#include "program_node_expr.hpp"
#include "program_node_stmt.hpp"
#include "program_node_stmt_if.hpp"
#include "program_node_stmt_equal.hpp"

class ProgNode;
class VariableNode;
class AssignmentNode;
class BlockNode;
class IfNode;

/* Basic ProgramNode builder (Builder Pattern)
 */
class ProgramNodeBuilder
{
    public:
        ProgramNodeBuilder();
        ~ProgramNodeBuilder();
    
        virtual BlockNode::Ptr newBlock(Token::Ptr) const;
        virtual ExprNode::Ptr newExpression() const;
        virtual ExprNode::Ptr newExpression(Token::Ptr, Type::Ptr) const;
        //virtual AssignmentNode::Ptr newAssignment(ProgNode::Ptr variable, ProgNode::Ptr expression) const;
        virtual ProgNode::Ptr newReturnStatement(ProgNode::Ptr value) const;
        virtual IfNode::Ptr newIfStmt(ExprNode::Ptr, StmtNode::Ptr) const;
        virtual EqualNode::Ptr newEqual(ProgNode::Ptr, ProgNode::Ptr) const;
        //virtual AdditionNode::Ptr newAddition(ProgNode::Ptr, ProgNode::Ptr) const;
        //virtual MultiplicationNode::Ptr newMultiplication(ProgNode::Ptr, ProgNode::Ptr) const;

        ProgNode::Ptr getRootNode();

    private:
        ProgNode::Ptr _node;
};

#endif /* ifndef __COMPILER_PROGRAM_NODE_BUILDER_H__ */
