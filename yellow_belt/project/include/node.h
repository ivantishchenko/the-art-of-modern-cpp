#pragma once

#include "date.h"

#include <string>
#include <memory>

enum class Comparison {
    Less,
    LessOrEqual,
    Greater,
    GreaterOrEqual,
    Equal,
    NotEqual
};

enum class LogicalOperation {
    And,
    Or
};

class Node {
public:
    virtual bool Evaluate(const Date& date, const string& str) const = 0;
};

class EmptyNode : public Node {
public:
    bool Evaluate(const Date& date, const string& str) const override;
};

class DateComparisonNode : public Node {
public:
    DateComparisonNode(Comparison cmp, const Date& date);
    bool Evaluate(const Date& date, const string& str) const override;
private:
    Comparison cmp_;
    Date date_;
};

class EventComparisonNode : public Node {
public:
    EventComparisonNode(Comparison cmp, const string& value);
    bool Evaluate(const Date& date, const string& str) const override;
private:
    Comparison cmp_;
    string value_;
};

class LogicalOperationNode : public Node {
public:
    LogicalOperationNode(const LogicalOperation logical_operation, 
        shared_ptr<Node> left, shared_ptr<Node> right);
    bool Evaluate(const Date& date, const string& str) const override;
private:
    const LogicalOperation logical_operation_;
    shared_ptr<Node> left_;
    shared_ptr<Node> right_;
};
