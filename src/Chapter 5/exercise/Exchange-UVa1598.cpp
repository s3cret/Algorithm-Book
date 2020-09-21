// NOT SOLVED
#include <iostream>
#include <cstdio>
#include <utility>
#include <map>
#include <queue>
#include <vector>
#include <string>
#ifdef LOCAL
#include <My_Util_Cpp.h>
#endif

using namespace std;
typedef pair<int, int> Pair;

struct ASC
{
    bool operator()(const Pair &lhs, const Pair &rhs)
    {
        return lhs.second > rhs.second;
    }
};
struct DES
{
    bool operator()(const Pair &lhs, const Pair &rhs)
    {
        return lhs.second < rhs.second;
    }
};

// when sell or trade or cancel, operate the price
// map<int, pair<int , queue<int>> > stock_at_price; // price -> (totoal amount at price i, queue for sell_id i)
map<int, int> stock_at_price; // price -> (totoal amount at price i, queue for sell_id i)
map<int, int> canceled;

map<int, Pair> buyers;  // ID -> (size, bid)
map<int, Pair> sellers; // ID -> (size, ask)

priority_queue<Pair, vector<Pair>, DES> buys_q;  // (ID, Price)
priority_queue<Pair, vector<Pair>, ASC> sells_q; // (ID, Price)

void add_buy(int ID, Pair p)
{
    buyers[ID] = p;
    buys_q.push(make_pair(ID, p.second));
}

void add_sell(int ID, Pair p)
{
    sellers[ID] = p;
    sells_q.push(make_pair(ID, p.second));
    stock_at_price[p.second] += p.first;
}

void cancel_sell(int ID)
{
    if (canceled[ID] == 0)
    {
        stock_at_price[sellers[ID].second] -= sellers[ID].first;
        canceled[ID] = 1;
    }
}

void cancel_buy(int ID)
{

}

void cancel(int ID)
{
    if (sellers.find(ID) != sellers.end())
    {
        cancel_sell(ID);
    }
    else
    {
        cancel_buy(ID);
    }
}

// buy: (size, bid), sell: (size, ask)
void trade(Pair &buy)
{
    int output = buy.first;
    int price = sells_q.top().second;

    while (sells_q.size())
    {
        int id = sells_q.top().first;

        if (buy.second < sellers[id].second)
        {
            break;
        }

        if (buy.first <= sellers[id].first)
        {
            sellers[id].first -= buy.first;
            stock_at_price[price] -= buy.first;
            buy.first = 0;

            break;
        }
        else
        {
            buy.first -= sellers[id].first;
            stock_at_price[price] -= sellers[id].first;
            sells_q.pop();
        }
    }

    if (buy.first == 0)
    {
        buys_q.pop();
    }

    cout << "TRADE " << output - buy.first << " " << buy.second << endl;
}

void print()
{
    int buy_size = 0, buy_price = 0, sell_size = 0, sell_price = 99999;
    while (buys_q.size())
    {
        if (canceled[buys_q.top().first])
        {
            buys_q.pop();
            continue;
        }
        buy_size = buyers[buys_q.top().first].first;
        buy_price = buyers[buys_q.top().first].second;
        break;
    }

    while (sells_q.size())
    {
        if (canceled[sells_q.top().first])
        {
            sells_q.pop();
            continue;
        }
        sell_price = sellers[sells_q.top().first].second;
        sell_size = stock_at_price[sell_price];
        break;
    }

    printf("QUOTE %d %d - %d %d\n", buy_size, buy_price, sell_size, sell_price);
}

int main()
{
#ifdef LOCAL
    io_redirect(__FILE__);
#endif

    int n;
    cin >> n;

    int ID = 0;
    for (int kase = 0; kase < n; kase++)
    {
        string cmd;
        cin >> cmd;

        ID++;
        int q, p; // p for price
        cin >> q;
        if (cmd[0] != 'C')
        {
            cin >> p;
            Pair pa = make_pair(q, p);
            if (cmd[0] == 'B')
            {
                add_buy(ID, pa);
            }
            else
            {
                add_sell(ID, pa);
            }
        }
        else
        {
            cancel(q);
        }

        while (buys_q.size() > 0 && sells_q.size() > 0)
        {
            if (canceled[buys_q.top().first])
            {
                buys_q.pop();
                continue;
            }

            if (canceled[sells_q.top().first])
            {
                sells_q.pop();
                continue;
            }

            if (buys_q.top().second >= sells_q.top().second)
            {
                trade(buyers[buys_q.top().first]);
            }
            break;
        }

        print();
    }

    return 0;
}