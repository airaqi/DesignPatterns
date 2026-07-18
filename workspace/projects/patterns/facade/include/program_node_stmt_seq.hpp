#ifndef __COMPILER_PROGRAM_NODE_STMT_SEQ_H__
#define __COMPILER_PROGRAM_NODE_STMT_SEQ_H__ 

#include "program_node_stmt.hpp"
#include <memory>
#include <ostream>

class SeqNode : public StmtNode
{
    public:
        typedef std::shared_ptr<SeqNode> Ptr;

    public:
        SeqNode(StmtNode::Ptr, StmtNode::Ptr);

    public:
        static Ptr create(StmtNode::Ptr, StmtNode::Ptr);

        StmtNode::Ptr stmt1() const;
        void stmt1(const StmtNode::Ptr);

        StmtNode::Ptr stmt2() const;
        void stmt2(const StmtNode::Ptr);
        
        virtual void gen(int, int) override;

        virtual bool equals(const ProgNode&) const override;

        virtual std::string to_string(std::string = "") const override;
        virtual std::string print(std::string = "") const override;

        virtual bool operator==(const ProgNode &) const override;
        virtual bool operator!=(const ProgNode &) const override;

        friend std::ostream& operator<<(std::ostream &, const SeqNode &);
        friend std::ostream& operator<<(std::ostream &, const SeqNode::Ptr);

    private:
        StmtNode::Ptr   _stmt1;
        StmtNode::Ptr   _stmt2;
};

#endif /* ifndef __COMPILER_PROGRAM_NODE_STMT_SEQ_H__ */
