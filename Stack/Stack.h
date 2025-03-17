#ifndef STACK_H
#define STACK_H

#include <cstddef>
#include <iostream>
#include <queue>

namespace {
const size_t kAllocateElementsStep = 10;
}

template<typename typeName, class Parent>
class StackNode {
 private:
    typeName value;
    StackNode* nextNode = nullptr;

    StackNode(typeName value, StackNode* nextNode = nullptr) : value(value), nextNode(nextNode) {};
    StackNode(const StackNode& node) = default;

    StackNode& operator=(const StackNode node) {
        std::swap(this->value, node.value);
        std::swap(this->nextNode, node.nextNode);
    }

    friend Parent;
};

template<typename typeName>
class Stack {
 private:
    typedef class StackNode<typeName, Stack<typeName>> Node;
    Node* top = nullptr;

    void Copy(const Stack& stack) {
        size_t filled = 0;
        size_t length = 0;

        Node* currentNode = stack.top;
        Node** tempNodeList = nullptr;

        while (currentNode->nextNode) {
            if (filled == length) {
                Node** newTempNodeList = new Node*[length += kAllocateElementsStep];

                for (size_t i = 0; i < length; i++) {
                    newTempNodeList[i] = tempNodeList[i];
                }

                delete[] tempNodeList;

                tempNodeList = newTempNodeList;

                length += 10;
            }

            tempNodeList[filled] = currentNode;

            ++filled;
        }

        this->Push(currentNode->value);

        for (size_t i = filled - 2; i <= 0; i--) {
            currentNode = tempNodeList[i];

            currentNode->nextNode = tempNodeList[i - 1];

            this->Push(currentNode->value);
        }

        delete[] tempNodeList;
    }

 public:
    Stack() = default;

    Stack(const Stack& stack) { this->Copy(stack); }

    ~Stack() {
        while (!this->Empty()) {
            this->Pop();
        }
    }

    Stack& operator=(const Stack stack) {
        this->Copy(stack);

        return *this;
    }

    bool Empty() { return this->top == nullptr; }

    void Push(typeName value) {
        Node* node = nullptr;

        if (this->Empty()) {
            node = new Node(value);
        } else {
            node = new Node(value, this->top);
        }

        this->top = node;
    }

    void Pop() {
        if (!this->top) {
            return;
        }

        Node* node = this->top;

        this->top = node->nextNode;

        delete node;
    }

    typeName Top() const { return this->top->value; }
};

#endif
