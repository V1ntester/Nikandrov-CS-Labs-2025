#ifndef STACK_H
#define STACK_H

#include <cstddef>
#include <iostream>
#include <queue>

namespace {
const size_t kAllocateElementsStep = 10;
}

template<typename typeName, class Parent>
class ListNode {
 private:
    typeName value;
    ListNode* nextNode = nullptr;

    ListNode(const typeName& value, ListNode* nextNode = nullptr) : value(value), nextNode(nextNode) {};
    ListNode(const ListNode& node) = default;

    ListNode& operator=(const ListNode node) {
        std::swap(this->value, node.value);
        std::swap(this->nextNode, node.nextNode);
    }

    friend Parent;
};

template<typename typeName>
class Stack {
 private:
    typedef class ListNode<typeName, Stack<typeName>> Node;
    Node* top = nullptr;

    void Copy(const Stack& stack) {
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

 public:
    Stack() = default;

    Stack(const Stack& stack) { this->Copy(stack); }

    ~Stack() {
        while (!this->Empty()) {
            this->Pop();
        }
    }

    Stack& operator=(const Stack& stack) {
        this->Copy(stack);

        return *this;
    }

    bool Empty() const { return this->top == nullptr; }

    void Push(const typeName& value) {
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

    friend std::ostream& operator<<(std::ostream& stream, const Stack& stack) {
        if (!stack.top) {
            return stream;
        }

        Node* currentNode = stack.top;

        while (currentNode) {
            stream << currentNode->value;

            if (currentNode->nextNode) {
                stream << ' ';
            }

            currentNode = currentNode->nextNode;
        }

        return stream;
    }
};

#endif
