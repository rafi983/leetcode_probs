#include <string>
#include <algorithm>

class TextEditor {
    std::string text;
    int cursor;

public:
    TextEditor() {
        text = "";
        cursor = 0;
    }

    void addText(std::string newText) {
        text.insert(cursor, newText);
        cursor += newText.length();
    }

    int deleteText(int k) {
        int toDelete = std::min(k, cursor);
        text.erase(cursor - toDelete, toDelete);
        cursor -= toDelete;
        return toDelete;
    }

    std::string cursorLeft(int k) {
        cursor = std::max(0, cursor - k);
        int start = std::max(0, cursor - 10);
        return text.substr(start, cursor - start);
    }

    std::string cursorRight(int k) {
        int maxPos = text.length();
        cursor = std::min(maxPos, cursor + k);
        int start = std::max(0, cursor - 10);
        return text.substr(start, cursor - start);
    }
};

