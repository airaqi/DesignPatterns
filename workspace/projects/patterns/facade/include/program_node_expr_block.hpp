#ifndef __COMPILER_PROGRAM_NODE_EXPR_BLOCKH__
#define __COMPILER_PROGRAM_NODE_EXPR_BLOCKH__ 

#include "compiler_env.hpp"
#include "compiler_token_word_type.hpp"
#include "program_node_expr.hpp"
#include <map>
#include <memory>
#include <string>

class BlockNode : public ExprNode
{
    public: 
        typedef std::shared_ptr<BlockNode> Ptr;

    public:
        BlockNode(Token::Ptr token, Type::Ptr type);

    public:
        static Ptr create(Token::Ptr, Type::Ptr);

        virtual void define(std::string, ProgNode::Ptr) override;
        virtual void undefine(std::string) override;
        virtual bool exists(std::string) override;
        virtual ProgNode::Ptr get(std::string) override;

        //virtual void traverse(CodeGenerator &) override;

        virtual std::string to_string(std::string = "") const override;
        virtual bool isBlock() override;

    private:
        std::map<std::string, ProgNode::Ptr> _oenv;
        Env::Ptr _env;

};

#endif /* ifndef __COMPILER_PROGRAM_NODE_EXPR_BLOCKH__ */
