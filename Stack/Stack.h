#pragma once

#include <cstddef>
#include <iostream>
#include <stdexcept>

namespace {
const size_t kAllocateElementsStep = 10;
}

template<typename TypeName, class Parent>
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
    typedef class ListNode<TypeName, Stack<TypeName>> Node;

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
    void Delete(size_t index);
    void Clear();

    TypeName Top() const;

    void Print() const;

    friend std::ostream& operator<<(std::ostream& stream, const Stack& stack) {
        if (!stack.top) {
            return stream;
        }

        Node* currentNode = stack.top;

        while (currentNode) {
            if (std::is_pointer_v<TypeName>) {
                stream << *(currentNode->value);
            } else {
                stream << currentNode->value;
            }

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
ListNode<TypeName, Parent>::~ListNode() {
    if (this->value) {
        delete this->value;
    }
}

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

    while (!this->Empty()) {
        this->Pop();
    }

    Node* currentNode = stack.top;
    Stack tempStack;

    while (currentNode) {
        tempStack.Push(currentNode->value);

        currentNode->nextNode ? currentNode = currentNode->nextNode : currentNode = nullptr;
    }

    while (!tempStack.Empty()) {
        this->Push(tempStack.Top());

        tempStack.Pop();
    }
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
void Stack<TypeName>::Delete(size_t index) {
    if (this->Empty()) {
        return;
    }

    size_t stackLength = 0;

    Node* currentNode = this->top;

    while (currentNode) {
        currentNode = currentNode->nextNode;

        ++stackLength;
    }

    try {
        if (index >= stackLength) {
            throw std::invalid_argument("Index out range");
        }
    } catch (const std::invalid_argument& exception) {
        std::cerr << exception.what();

        return;
    }

    if (index == stackLength - 1) {
        this->Pop();
    } else if (index == 0) {
        Node* previousNode = this->top;

        while (previousNode->nextNode && previousNode->nextNode->nextNode) {
            previousNode = previousNode->nextNode;
        }

        delete previousNode->nextNode;

        previousNode->nextNode = nullptr;
    } else {
        Node* previousNode = this->top;

        for (size_t i = 0; i < stackLength - index - 1; i++) {
            previousNode = previousNode->nextNode;
        }

        Node* nodeToDelete = previousNode->nextNode;

        previousNode->nextNode = nodeToDelete->nextNode;

        delete nodeToDelete;
    }
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
