/*
Вася пишет новую структуру данных — дерево. 
В узлах и листьях дерева хранятся строковые ключи. 
Каждый путь от корня до какого-нибудь узла можно записать, 
перечисляя последовательные ключи узлов. 
Типичный пример — иерархия папок в файловой системе. 
Вася уже выбрал способ хранения дерева:

#include <map>
#include <string>
#include <vector>

struct Node {
    std::map<std::string, Node> children;
};

class Tree {
private:
    Node root;

public:
    bool Has(const std::vector<std::string>& node) const;
    void Insert(const std::vector<std::string>& node);
    void Delete(const std::vector<std::string>& node);
};

// Ваш код будет вставлен сюда
#include "your_code"

Не будем обсуждать, насколько это эффективно.

Ваша задача — написать реализации функций Has, Insert и Delete для этого класса. 
В примере с папками в файловой системе функция Has должна проверить, существует ли такая папка, 
функция Insert должна создать папку (возможно, с промежуточными родительскими папками), 
а Delete — удалить папку со всеми вложенными подпапками, если такая папка существует.

Можно считать, что вектор, передаваемый на вход этих функций, всегда непустой.
*/
#include <map>
#include <string>
#include <vector>

struct Node {
    std::map<std::string, Node> children;
};

class Tree {
private:
    Node root;

public:
    bool Has(const std::vector<std::string>& node) const;
    void Insert(const std::vector<std::string>& node);
    void Delete(const std::vector<std::string>& node); 
};

bool Tree::Has(const std::vector<std::string>& node) const {
    const Node* temp = &root;
    for (const auto& elem : node) {
        if(!temp->children.contains(elem)) {
            return false;
        }
        temp = &temp->children.at(elem);
    }
    return true;
}

void Tree::Insert(const std::vector<std::string>& node) {
    Node* temp = &root;
    for (const auto& elem : node) {
        if(!temp->children.contains(elem)) {
            temp->children[elem];
        }
        temp = &temp->children.at(elem);
    }

}

void Tree::Delete(const std::vector<std::string>& node) {
    Node* temp = &root;
    for (size_t i = 0; i < node.size(); ++i) {
        const auto& elem = node[i];
        if (!temp->children.contains(elem)) {
            return;
            }
        if (i + 1 == node.size()) {
            temp->children.erase(elem);
        } else {
            temp = &temp->children.at(elem);
            }
        }
    }

    int main() {

    }
