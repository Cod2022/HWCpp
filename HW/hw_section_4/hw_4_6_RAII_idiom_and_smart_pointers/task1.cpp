/*
Коля пишет класс «Дерево». Узел дерева может хранить целое число, 
а также знает о своём родителе и о своих потомках. У узла есть 
функция AddChild для добавления потомка с заданным числовым значением, 
а также функция Print для красивой печати поддерева начиная с этого узла.

Вот что получилось у Коли:
*/

#include <iostream>
#include <vector>
#include <memory>

class TreeNode {
private:
    int value;
    TreeNode* root = nullptr;
    std::vector<std::unique_ptr<TreeNode>> children;

public:
    TreeNode(int val): value(val) {}

    TreeNode(const TreeNode&) = delete;
    TreeNode& operator=(const TreeNode&) = delete;

    TreeNode* AddChild(int child_value) {
        auto node = std::make_unique<TreeNode>(child_value);
        node->root = this;
        children.emplace_back(std::move(node));
        return children.back().get();
    }

    void Print(int depth = 0) const {
        for (int i = 0; i < depth; ++i) {
            std::cout << " ";
        }
        std::cout << "- " << value << "\n";
        for (const auto& child : children) {
            child->Print(depth + 1);
        }
    }
};

// Использоваться этот класс будет примерно так:
int main() {
    TreeNode root(1);

    auto left_son = root.AddChild(10);
    auto middle_son = root.AddChild(20);
    auto right_son = root.AddChild(30);

    left_son->AddChild(100);
    left_son->AddChild(200);

    middle_son->AddChild(150);
    middle_son->AddChild(250);

    root.Print();
}
/*
Однако эта работающая на первый взгляд тестовая программа падает, 
если её собрать с адресным санитайзером. Исправьте код класса TreeNode, 
чтобы решить эту проблему.
*/