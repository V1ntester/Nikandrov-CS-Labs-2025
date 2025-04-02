#pragma once

#include <cstddef>
#include <iostream>
#include <stdexcept>

namespace {
const size_t kAllocateElementsStep = 10;
}

template<typename TypeName, typename Parent>
class ListNode {
 private:
    TypeName value;
    ListNode* nextNode = nullptr;

 public:
    ListNode(const TypeName& value, ListNode* nextNode = nullptr);
    ListNode(const ListNode& node);

    ~ListNode();

    ListNode& operator=(const ListNode node);

    friend Parent;
};

template<typename TypeName>
class Stack {
 private:
    using Node = ListNode<TypeName, Stack<TypeName>>;

    Node* top = nullptr;

    void Copy(const Stack& stack);

 public:
    Stack();
    Stack(const Stack& stack);

    ~Stack();

    Stack& operator=(const Stack& stack);

    bool Empty() const;

    void Push(const TypeName& value);
    void Pop();
    void Clear();

    TypeName Top() const;

    void Print() const;

    friend std::ostream& operator<<(std::ostream& stream, const Stack<TypeName>& stack) {
        if (!stack.top) {
            return stream;
        }

        Node* currentNode = stack.top;

        while (currentNode) {
            stream << currentNode->value;

            stream << '\n';

            currentNode = currentNode->nextNode;
        }

        return stream;
    }
};

template<typename TypeName, class Parent>
ListNode<TypeName, Parent>::ListNode(const TypeName& value, ListNode* nextNode) : value(value), nextNode(nextNode) {
}

template<typename TypeName, class Parent>
ListNode<TypeName, Parent>::ListNode(const ListNode& node) = default;

template<typename TypeName, class Parent>
ListNode<TypeName, Parent>::~ListNode() = default;

template<typename TypeName, class Parent>
ListNode<TypeName, Parent>& ListNode<TypeName, Parent>::operator=(const ListNode node) {
    std::swap(this->value, node.value);
    std::swap(this->nextNode, node.nextNode);
}

template<typename TypeName>
void Stack<TypeName>::Copy(const Stack& stack) {
    if (stack.Empty()) {
        return;
    }

    size_t filled = 0;
    size_t length = 0;

    Node* currentNode = stack.top;
    Node** nodeList = nullptr;

    while (currentNode) {
        if (filled == length) {
            Node** newNodeList = new Node*[length += kAllocateElementsStep];

            if (nodeList) {
                for (size_t i = 0; i < filled; i++) {
                    newNodeList[i] = nodeList[i];
                }

                delete[] nodeList;
            }

            nodeList = newNodeList;

            length += 10;
        }

        nodeList[filled] = currentNode;

        ++filled;

        currentNode->nextNode ? currentNode = currentNode->nextNode : currentNode = nullptr;
    }

    for (int i = filled - 1; i > -1; i--) {
        this->Push(nodeList[i]->value);
    }

    delete[] nodeList;
}

template<typename TypeName>
Stack<TypeName>::Stack() = default;

template<typename TypeName>
Stack<TypeName>::Stack(const Stack& stack) {
    this->Copy(stack);
}

template<typename TypeName>
Stack<TypeName>::~Stack() {
    while (!this->Empty()) {
        this->Pop();
    }
}

template<typename TypeName>
Stack<TypeName>& Stack<TypeName>::operator=(const Stack& stack) {
    this->Copy(stack);

    return *this;
}

template<typename TypeName>
bool Stack<TypeName>::Empty() const {
    return this->top == nullptr;
}

template<typename TypeName>
void Stack<TypeName>::Push(const TypeName& value) {
    Node* node = nullptr;

    if (this->Empty()) {
        node = new Node(value);
    } else {
        node = new Node(value, this->top);
    }

    this->top = node;
}

template<typename TypeName>
void Stack<TypeName>::Pop() {
    if (this->Empty()) {
        return;
    }

    Node* node = this->top;

    this->top = node->nextNode;

    delete node;
}

template<typename TypeName>
void Stack<TypeName>::Clear() {
    while (!this->Empty()) {
        this->Pop();
    }
}

template<typename TypeName>
TypeName Stack<TypeName>::Top() const {
    return this->top->value;
}

template<typename TypeName>
void Stack<TypeName>::Print() const {
    std::cout << '\n' << *this << '\n';
}
