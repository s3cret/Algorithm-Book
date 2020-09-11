#include <string>
#include <unistd.h>

void get_in_fname(const char* file)
{
    std::string filename(file);
    filename = filename.substr(0, filename.find('.') + 1);
    filename += "in";
    if (access(filename.c_str(), F_OK) == -1)
    {
        fclose(fopen(filename.c_str(), "w"));
    }
    freopen(filename.c_str(), "r", stdin);
}

void get_out_fname(const char* file)
{
    std::string filename(file);
    filename = filename.substr(0, filename.find('.') + 1);
    filename += "out";
    if (access(filename.c_str(), F_OK) == -1)
    {
        fclose(fopen(filename.c_str(), "w"));
    }
    freopen(filename.c_str(), "w", stdout);
}

void io_redirect(const char* file)
{
    get_in_fname(file);
    get_out_fname(file);
}