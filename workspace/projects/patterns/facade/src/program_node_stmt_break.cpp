#include "program_node_stmt_break.hpp"
#include <format>
#include <memory>

BreakNode::BreakNode() 
{
            if (_stmt->Enclosing == StmtNode::Null())
                error("unenclosed break");
            _stmt = std::dynamic_pointer_cast<StmtNode>(StmtNode::Enclosing);
}

BreakNode::Ptr BreakNode::create() { return std::make_shared<BreakNode>(); }

StmtNode::Ptr BreakNode::stmt() const { return _stmt; }

void BreakNode::gen(int b, int a) 
{
    emit(std::format("{}{}", "goto L", _stmt->after()));
}

bool BreakNode::is_equals(const ProgNode & other) const
{ 
  return stmt() == static_cast<const BreakNode&>(other).stmt(); 
}

