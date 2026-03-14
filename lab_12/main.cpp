#include <iostream>
#include <clocale>
#include <fstream>
#include <windows.h>

void print_table() {
    std::cout << "Таблица символов и кодов." << std::endl;
    std::cout << "\nРусские буквы (строчные):" << std::endl;
    for (int i = 224; i <= 255; i++) {
        if (i == 230) {
            unsigned char a = 184;
            std::cout << a << " - 184" << std::endl;
        }
        unsigned char c = static_cast<unsigned char>(i);
        std::cout << c << " - " << i << std::endl;
    }
    std::cout << std::endl;

    std::cout << "\nРусские буквы (заглавные):" << std::endl;
    for (int i = 192; i <= 223; i++) {
        if (i == 198) {
            unsigned char a = 168;
            std::cout << a << " - 168" << std::endl;
        }
        unsigned char c = static_cast<unsigned char>(i);
        std::cout << c << " - " << i << std::endl;
    }

    std::cout << "\nАнглийские буквы (строчные):" << std::endl;
    for (int i = 97; i <= 122; i++) {
        unsigned char c = static_cast<unsigned char>(i);
        std::cout << c << " - " << i << std::endl;
    }
    std::cout << std::endl;

    std::cout << "\nАнглийские буквы (заглавные):" << std::endl;
    for (int i = 65; i <= 90; i++) {
        unsigned char c = static_cast<unsigned char>(i);
        std::cout << c << " - " << i << std::endl;
    }
    std::cout << std::endl;

    std::cout << "\nЦифры:" << std::endl;
    for (int i = 48; i <= 57; i++) {
        unsigned char c = static_cast<unsigned char>(i);
        std::cout << c << " - " << i << std::endl;
    }
    std::cout << std::endl;

    std::cout << "\nЗнаки препинания:" << std::endl;
    for (int i = 33; i <= 47; i++) {
        unsigned char c = static_cast<unsigned char>(i);
        std::cout << c << " - " << i << std::endl;
    }
    for (int i = 58; i <= 63; i++) {
        unsigned char c = static_cast<unsigned char>(i);
        std::cout << c << " - " << i << std::endl;
    }
    std::cout << std::endl;
}


const char glas[] = "аеёиоуыэюя";
const char soglas[] = "бвгджзйклмнопрстфхцчшщ";

char to_lower(char c) {
    unsigned char uc = static_cast<unsigned char>(c);

    if (uc == 168) return static_cast<char>(184);
    if (uc >= 192 && uc <= 223) {
        return static_cast<char>(uc + 32);
    }

    if ((uc >= 224 && uc <= 255) || uc == 184) {
        return c;
    }

    return c;
}

bool is_glas(char c) {
    char temp = to_lower(c);
    for (int i = 0; glas[i] != '\0'; i++) {
        if (temp == glas[i]) {
            return true;
        }
    }
    return false;
}


bool is_rus_letter(char c) {
    unsigned char uc = static_cast<unsigned char>(c);
    return (uc >= 192 && uc <= 223) || (uc >= 224 && uc <= 255) || uc == 168 || uc == 184;
}

bool is_digit(char c) {
    return (c >= '0' && c <= '9');
}

bool is_word_start(char c) {
    return (is_rus_letter(c) || is_digit(c));
}

bool is_word_center(char c) {
    return (is_rus_letter(c) || is_digit(c) || c == '-');
}

void word_to_lower(std::string& word) {
    for (size_t i = 0; i < word.length(); i++) {
        word[i] = to_lower(word[i]);
    }
}

bool is_alph_order(const std::string& word) {
    if (word.length() <= 1) return true;

    for (size_t i = 1; i < word.length(); i++) {
        if (!is_rus_letter(word[i]) || !is_rus_letter(word[i - 1])) {
            continue;
        }

        char prev = word[i - 1];
        char curr = word[i];

        char prev_fixed = prev;
        char curr_fixed = curr;

        if (prev == 'ё') prev_fixed = 'е' + 1; 
        if (curr == 'ё') curr_fixed = 'е' + 1;

        if (prev_fixed == curr_fixed) {
            if (prev == 'ё' && curr != 'ё') {
                continue;
            }
            if (curr == 'ё' && prev != 'ё') {
                return false;
            }
        }

        if (curr_fixed < prev_fixed) {
            return false;
        }
    }
    return true;
}

std::string pure_word(const std::string& text, int start, int end) {
    std::string word;
    for (int i = start; i <= end; i++) {
        if (is_rus_letter(text[i]) || is_digit(text[i])) {
            word += text[i];
        }
    }
    return word;
}



int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    setlocale(LC_ALL, "Russian");

    // Пункт 0
    //print_table();


    // Задача 1

    std::ifstream in_1("input_1.txt");
    if (!in_1.is_open()) {
        std::cout << "File is not open" << std::endl;
        return -1;
    }

    char str[101];
    in_1.getline(str, 101);
    in_1.close();

    char res[101];
    int j = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        if (!is_glas(str[i])) {
            res[j++] = str[i];
        }
    }
    res[j] = '\0';

    std::ofstream out_1("output_1.txt");
    out_1 << res;
    out_1.close();


    // Задача 2

    std::ifstream in_2("input_2.txt");
    if (!in_2.is_open()) {
        std::cout << "File is not open" << std::endl;
        return -1;
    }
    int N;
    in_2 >> N;
    in_2.close();

    std::ifstream in("text.txt");
    if (!in.is_open()) {
        std::cout << "File is not open" << std::endl;
        return -1;
    }

    std::string text;
    char ch;
    while (in.get(ch)) {
        text += ch;
    }
    in.close();

    std::string all_words[1000]; // максимум 1000 слов
    int all_words_count = 0;

    size_t i = 0;
    while (i < text.length() && all_words_count < 1000) {
        while (i < text.length() && !is_word_start(text[i])) {
            i++;
        }

        if (i >= text.length()) break;

        size_t start = i;

        while (i < text.length() && is_word_center(text[i])) {
            i++;
        }
        size_t end = i - 1;

        while (end >= start && text[end] == '-') {
            end--;
        }

        while (start <= end && text[start] == '-') {
            start++;
        }

        if (start <= end) {
            std::string word = pure_word(text, start, end);

            if (!word.empty()) {
                all_words[all_words_count] = word;
                all_words_count++;
            }
        }
    }

    if (all_words_count == 0) {
        std::cout << "Нет слов для обработки." << std::endl;
        return 0;
    }


    std::string suitable_words[1000];
    std::string norm_for_compare[1000];
    int suitable_count = 0;

    for (int idx = 0; idx < all_words_count; idx++) {
        std::string word = all_words[idx];
        std::string lower_word = word;
        word_to_lower(lower_word);

        if (is_alph_order(lower_word)) {
            bool found = false;
            for (int j = 0; j < suitable_count; j++) {
                if (norm_for_compare[j] == lower_word) {
                    found = true;
                    break;
                }
            }

            if (!found && suitable_count < 1000) {
                suitable_words[suitable_count] = word;
                norm_for_compare[suitable_count] = lower_word;
                suitable_count++;
            }
        }
    }

    if (suitable_count == 0) {
        std::cout << "Нет слов, удовлетворяющих условию." << std::endl;
        return 0;
    }


    for (int i = 0; i < suitable_count - 1; i++) {
        for (int j = i + 1; j < suitable_count; j++) {
            if (suitable_words[i].length() < suitable_words[j].length()) {
                std::string temp = suitable_words[i];
                suitable_words[i] = suitable_words[j];
                suitable_words[j] = temp;

                temp = norm_for_compare[i];
                norm_for_compare[i] = norm_for_compare[j];
                norm_for_compare[j] = temp;
            }
        }
    }

    std::ofstream out("result.txt");

    int count;
    if (N < suitable_count) {
        count = N;
    }
    else {
        count = suitable_count;
    }

    for (int i = 0; i < count; i++) {
        out << i + 1 << ". " << suitable_words[i] << std::endl;
    }
    out.close();

    return 0;
}
