#ifndef __COMPILER_PROGRAMnODE_EXPRESSION_H__
#define __COMPILER_PROGRAMnODE_EXPRESSION_H__ 

#include "compiler_token.hpp"
#include "compiler_token_word_type.hpp"
#include "program_node.hpp"
#include <map>
#include <memory>
#include <ostream>
#include <string>

/* Represents an expression.
 */
class ExprNode : public ProgNode, public std::enable_shared_from_this<ExprNode>
{
    public: 
        typedef std::shared_ptr<ExprNode> Ptr;
        typedef std::weak_ptr<ExprNode> Wptr;

    public:
        ExprNode(Token::Ptr token, Type::Ptr type);

    public:
        static Ptr create(Token::Ptr, Type::Ptr);

        virtual Ptr gen();
        virtual Ptr reduce();
        virtual void jumping(int, int);
        virtual void emitjumps(std::string test, int t, int f) const;

        virtual void getSourcePosition(int &line, int &index) override;

        virtual void add(ProgNode::Ptr) override;
        virtual void remove(ProgNode::Ptr) override;
        virtual const ProgNode& child(const int) const override;

        virtual std::map<int, ProgNode::Ptr>::const_iterator begin() const noexcept;
        virtual std::map<int, ProgNode::Ptr>::const_iterator end() const noexcept;

        virtual void traverse(CodeGenerator&) override;

        virtual bool isExpression() override;

        virtual std::string to_string(std::string = "") const override;
        virtual std::string print(std::string = "") const override;

        virtual bool equals(const ProgNode&) const override;

        virtual bool operator==(const ProgNode&) const override;
        virtual bool operator!=(const ProgNode&) const override;

        friend std::ostream& operator<<(std::ostream&, const ExprNode&);
        friend std::ostream& operator<<(std::ostream&, const ExprNode::Ptr);

        virtual void type(Type::Ptr t);         virtual Type::Ptr type() const;
        void op(Token::Ptr p);                  Token::Ptr op() const;

    public:
        static const ExprNode::Ptr       Null;
    protected:
        Token::Ptr                       _op;
        Type::Ptr                        _type;

        std::map<int, ProgNode::Ptr>    _children; 
};

#endif /* ifndef __COMPILER_PROGRAMnODE_EXPRESSION_H__ */
