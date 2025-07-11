#include <iostream>
#include <vector>
using namespace std;

struct Point {
    int x, y;
    void print() const {
        cout << "(" << x << ", " << y << ")";
    }
};

struct KDNode {
    Point point;
    KDNode* left;
    KDNode* right;
    KDNode(Point pt) : point(pt), left(nullptr), right(nullptr) {}
};

class KDTree {
    KDNode* root;

    KDNode* insertRec(KDNode* node, Point pt, int depth) {
        if (!node) return new KDNode(pt);
        int axis = depth % 2;
        if ((axis == 0 && pt.x < node->point.x) || (axis == 1 && pt.y < node->point.y))
            node->left = insertRec(node->left, pt, depth + 1);
        else
            node->right = insertRec(node->right, pt, depth + 1);
        return node;
    }

    bool searchRec(KDNode* node, Point pt, int depth) {
        if (!node) return false;
        if (node->point.x == pt.x && node->point.y == pt.y) return true;
        int axis = depth % 2;
        if ((axis == 0 && pt.x < node->point.x) || (axis == 1 && pt.y < node->point.y))
            return searchRec(node->left, pt, depth + 1);
        else
            return searchRec(node->right, pt, depth + 1);
    }

    void inorder(KDNode* node) {
        if (!node) return;
        inorder(node->left);
        node->point.print();
        cout << " ";
        inorder(node->right);
    }

public:
    KDTree() : root(nullptr) {}

    void insert(Point pt) {
        root = insertRec(root, pt, 0);
    }

    bool search(Point pt) {
        return searchRec(root, pt, 0);
    }

    void printInOrder() {
        cout << "In-Order Traversal of Tree: ";
        inorder(root);
        cout << endl;
    }
};

int main() {
    KDTree tree;
    int choice;
    
    while (true) {
        cout << "\n--- KD Tree Menu ---\n";
        cout << "1. Insert a point\n";
        cout << "2. Search for a point\n";
        cout << "3. Display tree (In-Order)\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 1) {
            Point pt;
            cout << "Enter x and y: ";
            cin >> pt.x >> pt.y;
            tree.insert(pt);
            cout << "Point inserted.\n";
        } else if (choice == 2) {
            Point pt;
            cout << "Enter x and y to search: ";
            cin >> pt.x >> pt.y;
            if (tree.search(pt)) {
                cout << "Point found.\n";
            } else {
                cout << "Point not found.\n";
            }
        } else if (choice == 3) {
            tree.printInOrder();
        } else if (choice == 4) {
            cout << "Exiting program.\n";
            break;
        } else {
            cout << "Invalid choice! Try again.\n";
        }
    }

    return 0;
}
