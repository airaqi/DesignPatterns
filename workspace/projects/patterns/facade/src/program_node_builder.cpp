#include "program_node_builder.hpp"
#include "compiler_token_word_type.hpp"
#include "program_node.hpp"
#include "program_node_expr_block.hpp"
#include "program_node_expr.hpp"
#include "program_node_stmt.hpp"
#include "program_node_stmt_equal.hpp"
#include "program_node_stmt_if.hpp"


ProgramNodeBuilder::ProgramNodeBuilder() : _node(nullptr) {}

ProgramNodeBuilder::~ProgramNodeBuilder() 
{
    _node = nullptr;
}

ProgNode::Ptr ProgramNodeBuilder::getRootNode()
{
    return _node;
}

BlockNode::Ptr ProgramNodeBuilder::newBlock(Token::Ptr token) const
{
    BlockNode::Ptr node = BlockNode::create(token, nullptr);
    return node;
}

ExprNode::Ptr ProgramNodeBuilder::newExpression() const
{
    ExprNode::Ptr node = ExprNode::create(nullptr, nullptr);
    return node;
}

ExprNode::Ptr ProgramNodeBuilder::newExpression(Token::Ptr token, Type::Ptr type) const
{
    ExprNode::Ptr node = ExprNode::create(token, type);
    return node;
}

/*AssignmentNode::Ptr ProgramNodeBuilder::newAssignment(ProgNode::Ptr variable, ProgNode::Ptr expression) const*/
/*{*/
    /*AssignmentNode::Ptr node = AssignmentNode::create(variable, expression);*/
    /*return node;*/
/*}*/

ProgNode::Ptr ProgramNodeBuilder::newReturnStatement(ProgNode::Ptr value) const
{
    ProgNode::Ptr node = StmtNode::create();
    return node;
}

IfNode::Ptr ProgramNodeBuilder::newIfStmt(ExprNode::Ptr e, StmtNode::Ptr s) const
{
    IfNode::Ptr node = IfNode::create(e, s);
    return node;
}

EqualNode::Ptr ProgramNodeBuilder::newEqual(ProgNode::Ptr lhs, ProgNode::Ptr rhs) const
{
    EqualNode::Ptr node = EqualNode::create(lhs, rhs);
    return node;
}

/*AdditionNode::Ptr ProgramNodeBuilder::newAddition(ProgNode::Ptr lhs, ProgNode::Ptr rhs) const*/
/*{*/
    /*AdditionNode::Ptr node = AdditionNode::create(lhs, rhs);*/
    /*return node;*/
/*}*/

/*MultiplicationNode::Ptr ProgramNodeBuilder::newMultiplication(ProgNode::Ptr lhs, ProgNode::Ptr rhs) const*/
/*{*/
    /*MultiplicationNode::Ptr node = MultiplicationNode::create(lhs, rhs);*/
    /*return node;*/
/*}*/
