#include <cstdio>
#include <iostream>
#include <string>
#include <vector>

#ifdef LOCAL
#include <My_Util_Cpp.h>
#endif

using namespace std;

vector<int> colomn_max_length;

// int = 1 means it should generate new line
pair<int, string> read();
// if the value is bigger than the index value, then replace it;
void append(int value, int index);
// print str and then fill width with c
void print(string str, int width, char x = ' ');

int main()
{
#ifdef LOCAL
    io_redirect(__FILE__);
#endif
    string str;
    int index = 0;
    pair<int, string> p;

    vector<string> line;
    vector<vector<string> > codes;

    while (1)
    {
        p = read(); // p.second may be an empty string

        // only to operate with non-empty string
        if (p.second.compare("") != 0)
        {
            append(p.second.length(), index++);
            line.push_back(p.second);
        }
        // if reads EOF
        if (p.first == -1)
        {
            break;
        }
        // if there's a new line
        else if (p.first == 1)
        {
            index = 0;
            codes.push_back(line);
            line.clear();
        }
    }
    codes.push_back(line); // append the last line

    // itreate the codes
    vector<vector<string> >::iterator row;
    vector<string>::iterator col;
    for (row = codes.begin(); row != codes.end(); row++)
    {
        for (col = row->begin(); col != row->end(); col++)
        {
            string s = *col;
            int width;
            int i = col - row->begin();

            // if it isn't the last element in the row
            if (col != row->end() - 1)
            {
                width = colomn_max_length[i] + 1;
            }
            else
            {
                width = s.length();
            }

            print(s, width);

            if (col == row->end() - 1)
            {
                cout << endl;
            }
        }
    }

    return 0;
}

pair<int, string> read()
{
    int reading_word = 0;
    pair<int, string> p;
    char c;
    while (1)
    {
        c = getchar();
        if (c == EOF)
        {
            p.first = -1;
            break;
        }
        else if (c == ' ')
        {
            if (reading_word)
            {
                break;
            }
            continue;
        }
        else if (c == '\n')
        {
            p.first = 1;
            break;
        }
        else
        {
            reading_word = 1;
            p.second += c;
        }
    }

    return p;
}

void append(int value, int index)
{
    if (colomn_max_length.size() <= index)
    {
        colomn_max_length.resize(index + 1);
    }

    if (colomn_max_length[index] < value)
    {
        colomn_max_length[index] = value;
    }
}

void print(string str, int width, char x)
{
    string extra(width - str.length(), x);
    cout << str << extra;
}
