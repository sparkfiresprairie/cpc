//
// Created by Xingyuan Wang on 3/18/17.
//

#include "Design.h"

class Path {
private:
    vector<string> split(string s, string const& delimiter) const {
        vector<string> tokens;
        size_t pos = 0;
        while ( (pos = s.find(delimiter)) != string::npos) {
            string token = s.substr(0, pos);
            if (!token.empty()) tokens.push_back(token);
            s.erase(0, pos + delimiter.size());
        }
        if (!s.empty()) tokens.push_back(s);
        return tokens;
    }
public:
    Path(std::string path) {
        currentPath = path;
    }

    std::string getPath() const {
        return currentPath;
    }

    Path cd(std::string newPath) const {
        vector<string> stk = split(currentPath, "/");
        for (int i = 0; i < newPath.size(); ++i) {
            if (i == 0 && newPath[i] == '/') {
                stk.clear();
            } else {
                int j = i;
                while (i < newPath.size() && newPath[i] != '/') ++i;
                string dir = newPath.substr(j, i - j);
                if (dir == "." ) continue;
                else if (dir == "..") {
                    if (!stk.empty()) stk.pop_back();
                } else {
                    stk.push_back(dir);
                }
            }
        }
        string result;
        for (auto const& token : stk) {
            result.append("/" + token);
        }
        if (result.empty()) result.append("/");
        return Path(result);
    }

private:
    std::string currentPath;
};

