// NOT SOLVED: TIME EXCEEDED LIMIT
#include <algorithm>
#include <iostream>
#include <sstream>
#include <utility>
#include <string>
#include <set>
#include <map>
#include <vector>
#ifdef LOCAL
#include <My_Util_Cpp.h>
#endif

using namespace std;

#define ALL(x) x.begin(), x.end()
#define INS(x) inserter(x, x.begin())
#define NOTFOUND string::npos
typedef pair<int, int> Pair;
// typedef set<Pair> Set;

vector<string> output;
// line cache
vector<string> LINEcache;
// store all the strings' id
map<string, int> IDcache;
// assign an ID to str and store the ID to IDcache
int ID(string str)
{
    if (IDcache.find(str) != IDcache.end())
    {
        return IDcache[str];
    }

    LINEcache.push_back(str);
    // this way you can use LINEcache[id] to get your LINE
    // id = IDcache[str]
    return IDcache[str] = LINEcache.size() - 1;
}
// to save the string's word to bucket
void save_word_to_bucket(map<string, set<int> > &bucket, string str, int id);
//

void add_to_output(set<int> result)
{
    for (set<int>::iterator it = result.begin(); it != result.end(); it++)
    {
        output.push_back(LINEcache[(*it)]);
    }
    output.push_back("----------");
}

int main()
{
#ifdef LOCAL
    io_redirect(__FILE__);
#endif
    int K;
    cin >> K;
    getchar();
    // store the id of line
    vector<int> articles[K];
    // map the bucket[K][word] -> line_id
    map<string, set<int> > bucket[K];

    // init for case K
    for (int i = 0; i < K; i++)
    {
        while (1)
        {
            string line;
            getline(cin, line);
            if (line[0] == '*' || line == "")
            {
                // stop read line and don't push ***** to articles
                break;
            }

            int id = ID(line); // line id
            articles[i].push_back(ID(line));
            save_word_to_bucket(bucket[i], line, id);
        }
    }

    int Q;
    cin >> Q;
    getchar();
    // start query Q
    for (int q = 0; q < Q; q++)
    {
        int pos;
        output.clear();
        string cmd;
        getline(cin, cmd);

        int found = 0;
        map<string, set<int> > buck;

        if ((pos = cmd.find("AND")) != NOTFOUND)
        {
            // A AND B
            string A = cmd.substr(0, pos - 1);
            string B = cmd.substr(pos + 4);

            for (int i = 0; i < K; i++)
            {
                set<int> result;
                buck = bucket[i];
                // if article[i] can find A and B
                if (buck[A].size() && buck[B].size())
                {
                    set_union(ALL(buck[A]), ALL(buck[B]), INS(result));
                }

                if (result.size() > 0)
                {
                    found = 1;
                    add_to_output(result);
                }
            }
        }
        else if ((pos = cmd.find("OR")) != NOTFOUND)
        {
            // A OR B
            string A = cmd.substr(0, pos - 1);
            string B = cmd.substr(pos + 3);

            for (int j = 0; j < K; j++)
            {
                set<int> result;
                buck = bucket[j];
                result.insert(buck[A].begin(), buck[A].end());
                result.insert(buck[B].begin(), buck[B].end());

                if (result.size() > 0)
                {
                    found = 1;
                    add_to_output(result);
                }
            }
        }
        else if (cmd.find("NOT") != NOTFOUND)
        {
            // NOT A
            string A = cmd.substr(4);

            for (int i = 0; i < K; i++)
            {
                buck = bucket[i];
                if (buck[A].size() == 0)
                {
                    found = 1;
                    for (int j = 0; j < articles[i].size(); j++)
                    {
                        int line_id = articles[i][j];
                        output.push_back(LINEcache[line_id]);
                    }
                    output.push_back("----------");
                }
            }
        }
        else
        {
            // CONTAINS A
            for (int i = 0; i < K; i++)
            {
                buck = bucket[i];
                set<int> result = buck[cmd];
                if (result.size() > 0)
                {
                    add_to_output(result);
                }
            }
        }

        if (output.size() > 0)
        {
            for (int i = 0; i < output.size() - 1; i++)
            {
                cout << output[i] << endl;
            }
            cout << string(10, '=') << endl;
        }
        else
        {
            cout << "Sorry, I found nothing." << endl;
            cout << string(10, '=') << endl;
        }
    }

    return 0;
}

void remove_punct(string &word)
{
    for (int i = 0, len = word.size(); i < len; i++)
    {
        if (ispunct(word[i]))
        {
            word.erase(i--, 1);
            len--;
        }
    }
}

void lower(string &word)
{
    for (int i = 0; i < word.length(); i++)
    {
        if (isalpha(word[i]))
        {
            word[i] = tolower(word[i]);
        }
    }
}

void save_word_to_bucket(map<string, set<int> > &bucket, string str, int line_id)
{
    stringstream ss(str);
    string word;
    while (ss >> word)
    {
        remove_punct(word);
        lower(word);
        bucket[word].insert(line_id);
    }
}
