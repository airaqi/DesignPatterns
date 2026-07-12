#include "program_node_expr_block.hpp"
#include "compiler_token.hpp"
#include "compiler_token_word_type.hpp"
#include "program_node.hpp"
#include <sstream>
#include <string>

BlockNode::BlockNode(Token::Ptr token, Type::Ptr type) : ExprNode(token, type), _env(nullptr)  { scope(BlockNode::Ptr(this)); }

BlockNode::Ptr BlockNode::create(Token::Ptr tok, Type::Ptr t)
{
    return BlockNode::Ptr(new BlockNode(tok, t));
}

bool BlockNode::isBlock()
{
    return true;
}

void BlockNode::define(std::string name, ProgNode::Ptr var)
{
    _oenv.insert_or_assign(name, var);
}

void BlockNode::undefine(std::string name)
{
    _oenv.erase(name);
}

bool BlockNode::exists(std::string name)
{
    return _oenv.find(name) != _oenv.end();
}

ProgNode::Ptr BlockNode::get(std::string name)
{
    //std::cout << "get " << this->id() << " " << name << "\n";
    if (exists(name))
        return _oenv.at(name);
    else if (scope() && scope()->exists(name))
        return scope()->get(name);
    else
        return nullptr;
}

/*void BlockNode::traverse(CodeGenerator& gen)
{
    for (auto& it : _children)
        it.second->traverse(gen);
}*/

std::string BlockNode::to_string(std::string prefix) const
{
    std::stringstream sout;
    std::string subfix = prefix + "  ";

    sout << prefix << "[Block (" << id() << "): \n";
    sout << _env->to_string(subfix);
/*    for (auto const& [key, value] : _oenv)*/
        /*sout << value->to_string(subfix) << "\n";*/
    for (auto const& [key, value] : _children)
        sout << value->to_string(subfix) << "\n";
    sout << prefix << "]";
    return sout.str();
}


