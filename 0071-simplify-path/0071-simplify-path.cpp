class Solution {
public:
    string simplifyPath(string path) {
        vector<string> folders;
        string folder;

        for (int i = 0; i <= path.size(); i++) {
            if (i == path.size() || path[i] == '/') {
                if (folder == "..") {
                    if (!folders.empty())
                        folders.pop_back();
                }
                else if (!folder.empty() && folder != ".") {
                    folders.push_back(folder);
                }

                folder = "";
            }
            else {
                folder += path[i];
            }
        }

        string result = "";

        for (string &dir : folders) {
            result += "/" + dir;
        }

        return result.empty() ? "/" : result;
    }
};