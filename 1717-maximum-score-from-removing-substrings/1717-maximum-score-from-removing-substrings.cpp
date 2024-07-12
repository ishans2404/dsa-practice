#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

static const bool Booster = [](){
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return true;
}();

int removePairs(string &s, string target) {
    int write_ind = 0, count = 0;
    for (char c : s) {
        s[write_ind] = c;
        write_ind++;
        if (write_ind >= 2 && s[write_ind - 1] == target[1] && s[write_ind - 2] == target[0]) {
            count++;
            write_ind -= 2;
        }
    }
    s.resize(write_ind);
    return count;
}

void parse_input_and_solve(std::ofstream& out, std::string& s, std::string& a, std::string& b) {
    s.erase(s.begin());
    s.pop_back();
    int x = stoi(a);
    int y = stoi(b);

    int res = 0;
    string top, bot;
    int top_score, bot_score;

    if (y > x) {
        top = "ba";
        top_score = y;
        bot = "ab";
        bot_score = x;
    } else {
        top = "ab";
        top_score = x;
        bot = "ba";
        bot_score = y;
    }

    res += removePairs(s, top) * top_score;
    res += removePairs(s, bot) * bot_score;
    out << res << endl;
}

bool Solve = []() {
    std::ofstream out("user.out");
    std::string s, a, b;
    while (std::getline(std::cin, s) && std::getline(std::cin, a) && std::getline(std::cin, b)) {
        parse_input_and_solve(out, s, a, b);
    }
    out.flush();
    exit(0);
    return true;
}();


class Solution {
public:
    int removePairs(string &s, string target) {
        int write_ind = 0, count = 0;
        for (char c : s) {
            s[write_ind] = c;
            write_ind++;
            if (write_ind >= 2 && s[write_ind - 1] == target[1] && s[write_ind - 2] == target[0]) {
                count++;
                write_ind -= 2;
            }
        }
        s.resize(write_ind);
        return count;
    }

    int maximumGain(string s, int x, int y) {
        int res = 0;
        string top, bot;
        int top_score, bot_score;

        if (y > x) {
            top = "ba";
            top_score = y;
            bot = "ab";
            bot_score = x;
        } else {
            top = "ab";
            top_score = x;
            bot = "ba";
            bot_score = y;
        }

        res += removePairs(s, top) * top_score;
        res += removePairs(s, bot) * bot_score;
        return res;
    }
};